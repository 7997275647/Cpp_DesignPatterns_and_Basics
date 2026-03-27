# Windows Developer Quick Start Guide

## Setup (5 minutes)

### 1. Install Code Quality Tools

Open PowerShell as Administrator and run:

```powershell
# Option A: Using Chocolatey (easiest)
choco install cppcheck clang-format

# Option B: Using Scoop
scoop install cppcheck clang-format

# Option C: Manual installation
# Download from:
# - cppcheck: https://github.com/danmar/cppcheck/releases
# - LLVM (for clang-format): https://releases.llvm.org/download.html
```

### 2. Verify Installation

```powershell
cppcheck --version
clang-format --version
```

Both should return version numbers. If not, see "Troubleshooting" below.

## Daily Workflow

### Before Committing Code

```cmd
cd C:\Users\modug\OneDrive\Desktop\GitHub\Cpp_DesignPatterns_and_Basics
.\check.bat
```

### If Issues Are Found

```cmd
# Automatically fix formatting issues
.\check.bat --fix

# Then review changes and commit
git add .
git commit -m "Fix code formatting"
```

### Building Your Project

```cmd
# Release build
.\build.bat

# Debug build
.\build.bat debug

# Rebuild from scratch
.\build.bat rebuild

# Build and run
.\build.bat run
```

## Available Scripts

| Script | Purpose |
|--------|---------|
| `build.bat` | Build the C++ project |
| `check.bat` | Check code quality (formatting + static analysis) |
| `build.sh` | Linux/macOS build script |
| `check.sh` | Linux/macOS code quality script |

## Check Command Options

```cmd
check.bat              # Check everything
check.bat --fix        # Fix formatting automatically
check.bat --check      # Only check without fixing
check.bat --help       # Show help
```

## Troubleshooting

### "cppcheck is not recognized"

1. **Reinstall with Chocolatey:**
   ```powershell
   choco uninstall cppcheck
   choco install cppcheck
   ```

2. **Manually add to PATH:**
   - Find where cppcheck is installed (usually `C:\Program Files\cppcheck`)
   - Add this directory to your system PATH

3. **Verify PATH:**
   ```powershell
   $env:Path -split ';' | findstr cppcheck
   where cppcheck
   ```

### "clang-format is not recognized"

1. **Reinstall LLVM:**
   ```powershell
   choco uninstall llvm
   choco install llvm
   # During installation, CHECK "Add LLVM to the system PATH"
   ```

2. **Check Visual Studio installation:**
   ```powershell
   dir "C:\Program Files\Microsoft Visual Studio\*\*\VC\Tools\Clang\bin\clang-format.exe"
   ```
   If found, add this directory to PATH.

3. **Manually add to PATH:**
   - Find LLVM installation (usually `C:\Program Files\LLVM`)
   - Add `C:\Program Files\LLVM\bin` to your system PATH

4. **Verify PATH:**
   ```powershell
   $env:Path -split ';' | findstr LLVM
   where clang-format
   ```

### "The term '.\check.bat' is not recognized"

```powershell
# Make sure you're in the right directory
cd "C:\Users\modug\OneDrive\Desktop\GitHub\Cpp_DesignPatterns_and_Basics"

# Then run it
.\check.bat
```

### PowerShell Execution Policy Error

If you get "cannot be loaded because running scripts is disabled":

```powershell
# Temporarily allow for this session
Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope Process

# Then run the script
.\check.bat
```

## Setting PATH on Windows Permanently

### Method 1: Using PowerShell (Admin)
```powershell
# Add cppcheck to PATH
$env:Path += ";C:\Program Files\cppcheck\bin"

# Add LLVM to PATH
$env:Path += ";C:\Program Files\LLVM\bin"
```

### Method 2: Using GUI
1. Press `Win + X` and select "System"
2. Click "Advanced system settings"
3. Click "Environment Variables"
4. Under "System variables", click "Path" → "Edit"
5. Click "New" and add:
   - `C:\Program Files\cppcheck\bin`
   - `C:\Program Files\LLVM\bin`
6. Click "OK" on all dialogs
7. **Close and reopen PowerShell/Command Prompt**

## Integration with GitHub

Your code is automatically checked on every push via GitHub Actions (`.github/workflows/build.yml`). You can view results in the "Actions" tab on GitHub.

Local checking before pushing prevents CI/CD failures.

## VS Code Integration (Optional)

1. Install extensions:
   - C/C++ extension
   - Clang-Format extension

2. Create `.vscode/settings.json`:
   ```json
   {
       "editor.formatOnSave": true,
       "editor.defaultFormatter": "xaver.clang-format",
       "[cpp]": {
           "editor.formatOnSave": true
       }
   }
   ```

## Quick Reference

```bash
# View available commands
build.bat help
check.bat --help

# Check before pushing
check.bat

# Fix issues automatically
check.bat --fix

# Build project
build.bat

# Build in debug mode
build.bat debug

# Clean and rebuild
build.bat rebuild

# Build and run
build.bat run
```

For detailed documentation, see `QUALITY_CHECKS_README.md`.
