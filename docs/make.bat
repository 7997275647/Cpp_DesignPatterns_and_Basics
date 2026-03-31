@echo off
REM make.bat - Makefile for Windows Sphinx builds

if "%1"=="" goto help
if "%1"=="help" goto help
if "%1"=="html" goto html
if "%1"=="clean" goto clean
if "%1"=="cleanall" goto cleanall
if "%1"=="doxygen" goto doxygen

:help
echo Sphinx and Breathe documentation build helper
echo Use make.bat/make html, etc. where [target] is one of:
echo   html       to make standalone HTML files
echo   doxygen    to run Doxygen to generate XML
echo   clean      to remove build artifacts
echo   cleanall   to remove all generated files including Doxygen output
goto end

:html
echo Running Doxygen...
if not exist doxygen mkdir doxygen
cd ..
doxygen Doxyfile
cd docs
if errorlevel 1 exit /b 1
echo Building HTML documentation...
if exist _build rmdir /s /q _build
python -m sphinx -b html . _build/html
if errorlevel 1 exit /b 1
echo.
echo Build finished. The HTML pages are in _build\html.
goto end

:doxygen
echo Running Doxygen...
if not exist doxygen mkdir doxygen
cd ..
doxygen Doxyfile
cd docs
if errorlevel 1 exit /b 1
goto end

:clean
echo Cleaning build artifacts...
if exist _build rmdir /s /q _build
goto end

:cleanall
echo Cleaning all generated files...
if exist _build rmdir /s /q _build
if exist doxygen rmdir /s /q doxygen
echo Clean complete.
goto end

:end
