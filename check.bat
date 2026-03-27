@echo off
REM Code quality check script for CppDesignPatterns project
REM Runs cppcheck and clang-format on local code

setlocal enabledelayedexpansion

REM Color codes simulation and other settings
set "BOLD=[1m"
set "RED=[91m"
set "GREEN=[92m"
set "YELLOW=[93m"
set "RESET=[0m"

set "FIX_FORMAT=0"
set "CHECK_ONLY=0"

REM Parse arguments
:parse_args
if "%1"=="" goto check_tools
if "%1"=="--fix" (
    set "FIX_FORMAT=1"
    shift
    goto parse_args
)
if "%1"=="--check" (
    set "CHECK_ONLY=1"
    shift
    goto parse_args
)
if "%1"=="--help" (
    goto show_help
)
echo Unknown option: %1
exit /b 1

:show_help
echo.
echo Code Quality Check Script
echo.
echo Usage: check.bat [OPTIONS]
echo.
echo Options:
echo   --fix           - Fix formatting issues automatically
echo   --check         - Check formatting without fixing (default^)
echo   --help          - Show this help message
echo.
echo Examples:
echo   check.bat              - Check code quality
echo   check.bat --fix        - Fix formatting issues
echo   check.bat --check      - Only check without fixing
echo.
exit /b 0

:check_tools
echo.
echo CppDesignPatterns - Code Quality Check
echo.

REM Check for cppcheck
where cppcheck >nul 2>&1
if errorlevel 1 (
    echo Warning: cppcheck not found
    echo Install from: https://github.com/danmar/cppcheck/releases
    set "HAVE_CPPCHECK=0"
) else (
    set "HAVE_CPPCHECK=1"
)

REM Check for clang-format
where clang-format >nul 2>&1
if errorlevel 1 (
    echo Warning: clang-format not found
    echo Install from: https://clang.llvm.org/download.html
    set "HAVE_CLANG_FORMAT=0"
) else (
    set "HAVE_CLANG_FORMAT=1"
)

if %HAVE_CPPCHECK%==0 if %HAVE_CLANG_FORMAT%==0 (
    echo.
    echo Error: No tools available for code quality checks
    exit /b 1
)

echo.
set "ALL_PASSED=1"

REM Run cppcheck if available
if %HAVE_CPPCHECK%==1 (
    goto run_cppcheck
) else (
    echo Skipping cppcheck...
)

:check_format
if %HAVE_CLANG_FORMAT%==1 (
    goto check_formatting
) else (
    echo Skipping clang-format check...
)

goto finish

:run_cppcheck
echo.
echo ============================================================
echo Running Static Analysis ^(cppcheck^)
echo ============================================================
echo.

cppcheck --enable=all ^
    --suppress=missingIncludeSystem ^
    --suppress=unusedFunction ^
    --error-exitcode=1 ^
    --inline-suppr ^
    Application\ Basics\ DesignPatterns\

if errorlevel 1 (
    echo.
    echo Error: Issues found by cppcheck
    set "ALL_PASSED=0"
) else (
    echo.
    echo Check passed: No cppcheck issues found
)

goto check_format

:check_formatting
echo.
echo ============================================================
echo Checking Code Formatting ^(clang-format^)
echo ============================================================
echo.

setlocal enabledelayedexpansion
set "FORMAT_ISSUES=0"

REM Collect all files and check them
setlocal enabledelayedexpansion
set "FILE_COUNT=0"
set "ISSUE_COUNT=0"

for /r Application %%f in (*.cpp *.hpp *.h) do (
    set /a FILE_COUNT+=1
    echo Checking: %%f
    
    REM Create temp file with formatted output
    clang-format "%%f" > "%TEMP%\clang_formatted.tmp" 2>NUL
    
    REM Compare files using FC command
    fc /b "%%f" "%TEMP%\clang_formatted.tmp" >NUL 2>&1
    if errorlevel 1 (
        echo   NEEDS FORMATTING
        set /a ISSUE_COUNT+=1
        set "FORMAT_ISSUES=1"
    )
)

for /r Basics %%f in (*.cpp *.hpp *.h) do (
    set /a FILE_COUNT+=1
    echo Checking: %%f
    
    clang-format "%%f" > "%TEMP%\clang_formatted.tmp" 2>NUL
    fc /b "%%f" "%TEMP%\clang_formatted.tmp" >NUL 2>&1
    if errorlevel 1 (
        echo   NEEDS FORMATTING
        set /a ISSUE_COUNT+=1
        set "FORMAT_ISSUES=1"
    )
)

for /r DesignPatterns %%f in (*.cpp *.hpp *.h) do (
    set /a FILE_COUNT+=1
    echo Checking: %%f
    
    clang-format "%%f" > "%TEMP%\clang_formatted.tmp" 2>NUL
    fc /b "%%f" "%TEMP%\clang_formatted.tmp" >NUL 2>&1
    if errorlevel 1 (
        echo   NEEDS FORMATTING
        set /a ISSUE_COUNT+=1
        set "FORMAT_ISSUES=1"
    )
)

echo.
echo Checked !FILE_COUNT! files, found !ISSUE_COUNT! with formatting issues

if %FORMAT_ISSUES%==1 (
    if %FIX_FORMAT%==1 (
        echo.
        echo Fixing formatting...
        for /r Application %%f in (*.cpp *.hpp *.h) do (
            clang-format -i "%%f"
        )
        for /r Basics %%f in (*.cpp *.hpp *.h) do (
            clang-format -i "%%f"
        )
        for /r DesignPatterns %%f in (*.cpp *.hpp *.h) do (
            clang-format -i "%%f"
        )
        echo Formatting fixed
    ) else (
        echo.
        echo Some files need formatting
        echo Run with --fix to automatically fix formatting issues
        set "ALL_PASSED=0"
    )
) else (
    echo All files properly formatted
)

REM Clean up temp file
if exist "%TEMP%\clang_formatted.tmp" del "%TEMP%\clang_formatted.tmp"

endlocal & set "ALL_PASSED=%ALL_PASSED%"

goto finish

:finish
echo.
echo ============================================================
if %ALL_PASSED%==1 (
    echo All checks passed!
) else (
    echo Some checks failed
)
echo ============================================================
echo.

if %ALL_PASSED%==1 (
    exit /b 0
) else (
    exit /b 1
)
