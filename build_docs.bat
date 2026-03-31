@echo off
REM Build script for documentation on Windows

echo Installing Python dependencies...
pip install -r docs\requirements.txt

echo.
echo Checking for Doxygen installation...
where doxygen >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo Warning: Doxygen is not installed or not in PATH
    echo Please install Doxygen from: https://www.doxygen.nl/download.html
    exit /b 1
)

echo.
echo Creating build directories...
if not exist docs\doxygen mkdir docs\doxygen

echo.
echo Running Doxygen...
doxygen Doxyfile

echo.
echo Building Sphinx documentation...
cd docs
if exist _build rmdir /s /q _build
call make.bat html
cd ..

echo.
echo Documentation generated successfully!
echo Open docs\_build\html\index.html to view the documentation.
