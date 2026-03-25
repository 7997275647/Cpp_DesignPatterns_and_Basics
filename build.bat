@echo off
REM Build automation script for CppDesignPatterns project
REM Supports: build, rebuild, clean, release, debug, and run commands

setlocal enabledelayedexpansion

REM Set default values
set "BUILD_TYPE=Release"
set "BUILD_DIR=build"
set "ACTION=build"
set "GENERATOR=Visual Studio 17 2022"

REM Parse command line arguments
if "%1"=="" (
    set "ACTION=build"
) else (
    set "ACTION=%1"
)

if not "%2"=="" (
    set "BUILD_TYPE=%2"
)

REM Display help
if "%ACTION%"=="help" (
    echo.
    echo CppDesignPatterns Build Automation Script
    echo.
    echo Usage: build.bat [ACTION] [BUILD_TYPE]
    echo.
    echo Actions:
    echo   build       - Build the project (default^)
    echo   rebuild     - Clean and rebuild the project
    echo   clean       - Clean build artifacts
    echo   run         - Build and run the project
    echo   release     - Build release configuration
    echo   debug       - Build debug configuration
    echo   help        - Show this help message
    echo.
    echo Build Types:
    echo   Release     - Optimized build (default^)
    echo   Debug       - Debug build with symbols
    echo.
    echo Examples:
    echo   build.bat                    - Build release version
    echo   build.bat debug              - Build debug version
    echo   build.bat rebuild release    - Rebuild release version
    echo   build.bat run debug          - Build and run debug version
    echo.
    goto end
)

REM Create build directory if it doesn't exist
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

REM Execute requested action
if "%ACTION%"=="build" (
    call :build_project
) else if "%ACTION%"=="rebuild" (
    call :clean_project
    call :build_project
) else if "%ACTION%"=="clean" (
    call :clean_project
) else if "%ACTION%"=="run" (
    call :build_project
    call :run_project
) else if "%ACTION%"=="release" (
    set "BUILD_TYPE=Release"
    call :build_project
) else if "%ACTION%"=="debug" (
    set "BUILD_TYPE=Debug"
    call :build_project
) else (
    echo Unknown action: %ACTION%
    echo Use 'build.bat help' for usage information
    goto end
)

goto end

REM ============================================================================
REM Function: build_project
REM ============================================================================
:build_project
echo.
echo ============================================================
echo Building %BUILD_TYPE% Configuration
echo ============================================================
echo.

REM Run CMake configuration
echo [1/2] Configuring project...
cd /d "%BUILD_DIR%"
cmake -G "%GENERATOR%" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DCMAKE_CXX_STANDARD=17 ..
if errorlevel 1 (
    echo Error: CMake configuration failed
    cd ..
    goto error
)

REM Build the project
echo.
echo [2/2] Building project...
cmake --build . --config %BUILD_TYPE%
if errorlevel 1 (
    echo Error: Build failed
    cd ..
    goto error
)

cd ..
echo.
echo ============================================================
echo Build Complete!
echo Output directory: %BUILD_DIR%\bin\%BUILD_TYPE%
echo ============================================================
echo.
goto :eof

REM ============================================================================
REM Function: clean_project
REM ============================================================================
:clean_project
echo.
echo ============================================================
echo Cleaning Build Artifacts
echo ============================================================
echo.

if exist "%BUILD_DIR%" (
    echo Removing %BUILD_DIR% directory...
    rmdir /s /q "%BUILD_DIR%"
    echo Clean complete.
) else (
    echo Nothing to clean.
)
echo.
goto :eof

REM ============================================================================
REM Function: run_project
REM ============================================================================
:run_project
echo.
echo ============================================================
echo Running Application
echo ============================================================
echo.

set "EXE_PATH=%BUILD_DIR%\bin\%BUILD_TYPE%\CppDesignPatterns.exe"

if exist "%EXE_PATH%" (
    echo Launching: %EXE_PATH%
    call "%EXE_PATH%"
) else (
    echo Error: Executable not found at %EXE_PATH%
    goto error
)
echo.
goto :eof

REM ============================================================================
REM Error handler
REM ============================================================================
:error
echo.
echo ============================================================
echo ERROR: Build process failed
echo ============================================================
echo Use 'build.bat help' for usage information
echo.
exit /b 1

:end
endlocal
