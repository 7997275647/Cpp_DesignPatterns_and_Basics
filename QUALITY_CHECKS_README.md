# Code Quality Tools Setup Guide

This guide helps you set up and use `cppcheck` and `clang-format` on Windows.

## Installation Options

### Option 1: Using Chocolatey (Recommended)

If you have Chocolatey installed:

```powershell
choco install cppcheck clang-format
```

### Option 2: Using Scoop

```powershell
scoop install cppcheck clang-format
```

### Option 3: Manual Installation

#### cppcheck
1. Download from: https://github.com/danmar/cppcheck/releases
2. Download the Windows installer (e.g., `cppcheck-2.x-x64-Setup.msi`)
3. Run the installer and follow the prompts
4. Add installation directory to PATH (usually `C:\Program Files\cppcheck`)

#### clang-format
1. Download from: https://releases.llvm.org/download.html
2. Download the Windows installer (e.g., `LLVM-x.x.x-win64.exe`)
3. Run the installer
4. **Important:** Check "Add LLVM to the system PATH" during installation
5. Or manually add it to PATH: `C:\Program Files\LLVM\bin`

### Option 4: Visual Studio (clang-format only)

If you have Visual Studio installed:
1. clang-format may already be available in: `C:\Program Files (x86)\Microsoft Visual Studio\[version]\[edition]\VC\Tools\Clang\bin`
2. Add this directory to your PATH

## Verify Installation

Open a new PowerShell/Command Prompt and verify:

```powershell
cppcheck --version
clang-format --version
```

## Usage

### Basic Check
```cmd
check.bat
```

### Fix Formatting Issues
```cmd
check.bat --fix
```

### Only Check Formatting
```cmd
check.bat --check
```

### Show Help
```cmd
check.bat --help
```

## Running Before Push

### Manual: Check before committing
```cmd
check.bat
```
If it passes, you can safely commit and push.

### Automatic: Using Git Hooks (Advanced)

To automatically run checks before commits:

1. Copy the pre-commit hook:
```powershell
Copy-Item hooks/pre-commit .git/hooks/pre-commit
```

2. If you're on Windows, you may need to use a PowerShell version instead. Create `.git/hooks/pre-commit` (without extension) with this content:

```powershell
#!/bin/bash
# Windows users: This hook requires Git Bash or WSL
# Alternative: Run check.bat manually before pushing

echo "Running pre-commit checks..."

REM Get staged C++ files
for /f %%f in ('git diff --cached --name-only --diff-filter=ACM') do (
    if "%%~xf"==".cpp" (
        cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction --error-exitcode=1 %%f
        if errorlevel 1 (
            echo Commit aborted due to cppcheck issues
            exit /b 1
        )
    )
)

echo All checks passed!
exit /b 0
```

## Integration with Your Workflow

1. **Before committing:**
   ```cmd
   check.bat
   ```

2. **To fix formatting automatically:**
   ```cmd
   check.bat --fix
   git add .
   git commit -m "Format code"
   ```

3. **To commit anyway (bypass checks):**
   ```cmd
   git commit --no-verify
   ```

## Troubleshooting

### "cppcheck is not recognized"
- **Solution:** Reinstall cppcheck and ensure PATH includes the installation directory
- **Verify:** Run `where cppcheck` in PowerShell

### "clang-format is not recognized"
- **Solution:** Reinstall LLVM and check "Add LLVM to the system PATH"
- **Verify:** Run `where clang-format` in PowerShell
- **Alternative:** Check if Visual Studio has it at `C:\Program Files (x86)\Microsoft Visual Studio\[version]\[edition]\VC\Tools\Clang\bin`

### "The term 'check.bat' is not recognized"
- **Solution:** Navigate to the project directory first:
  ```powershell
  cd C:\Users\modug\OneDrive\Desktop\GitHub\Cpp_DesignPatterns_and_Basics
  .\check.bat
  ```

### Tools fail to run or find files
- Ensure you're running the script from the project root directory
- Check that `Application/`, `Basics/`, and `DesignPatterns/` directories exist

## IDE Integration (Optional)

### Visual Studio Code
Install extensions:
- **cppcheck extension**: `ms-vscode.cpptools` 
- **clang-format extension**: `xaver.clang-format`

Then configure in `.vscode/settings.json`:
```json
{
    "C_Cpp.codeAnalysisRunningMessage": "Running code analysis...",
    "editor.formatOnSave": true,
    "editor.defaultFormatter": "xaver.clang-format"
}
```

### Visual Studio
1. Open Tools → Options → Text Editor → C/C++ → Advanced
2. Set "Enable Code Analysis on Build" to True
3. Code will be checked automatically on build

## CI/CD Pipeline

Your GitHub Actions workflow (`.github/workflows/build.yml`) automatically runs these checks on every push and pull request. You can view results in the "Actions" tab on GitHub.

## Next Steps

1. Install the tools: Choose one installation method above
2. Run `check.bat` to verify everything works
3. Add to your pre-commit workflow before pushing
4. Configure your IDE for real-time checking (optional)
