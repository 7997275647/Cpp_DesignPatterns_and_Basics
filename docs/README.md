# Documentation Setup Guide

This directory contains the Sphinx/Breathe/Doxygen documentation setup for the C++ Design Patterns and Basics project.

## Quick Start

### Prerequisites

1. **Python 3.7+** - For Sphinx and Breathe
2. **Doxygen** - For parsing C++ code
3. **Make** (optional, for Unix-like systems)

### Installation

#### Windows

1. Install Doxygen from https://www.doxygen.nl/download.html
   - Add Doxygen to your PATH during installation

2. Install Python dependencies:
   ```bash
   pip install -r docs/requirements.txt
   ```

3. Build the documentation:
   ```bash
   build_docs.bat
   ```
   Or from the docs directory:
   ```bash
   cd docs
   make.bat html
   ```

#### macOS/Linux

1. Install Doxygen:
   ```bash
   # macOS
   brew install doxygen
   
   # Ubuntu/Debian
   sudo apt-get install doxygen
   ```

2. Install Python dependencies:
   ```bash
   pip install -r docs/requirements.txt
   ```

3. Build the documentation:
   ```bash
   ./build_docs.sh
   ```
   Or from the docs directory:
   ```bash
   cd docs
   make html
   ```

## Output

The generated HTML documentation will be in:
- **Windows**: `docs\_build\html\index.html`
- **Unix**: `docs/_build/html/index.html`

Open this file in a web browser to view the documentation.

## File Structure

```
docs/
├── conf.py                    # Sphinx configuration
├── index.rst                  # Main documentation page
├── modules.rst                # API reference index
├── basics.rst                 # Basics module documentation
├── design_patterns.rst        # Design patterns documentation
├── application.rst            # Application documentation
├── requirements.txt           # Python dependencies
├── Makefile                   # Unix build helper
├── make.bat                   # Windows build helper
├── _build/                    # Built documentation (generated)
├── _static/                   # Static files
├── _templates/                # Custom templates
└── doxygen/                   # Doxygen XML output (generated)
```

## Configuration Files

### Doxyfile

Located at the project root (`../Doxyfile`), this file configures Doxygen:
- Specifies which directories to parse (Basics, DesignPatterns, Application)
- Generates XML output for Breathe to consume
- Configured for C++17

### conf.py

Sphinx configuration:
- Enables Breathe extension for C++ integration
- Configures the Read the Docs theme
- Sets up project metadata

## Documenting Your Code

### C++ Comments

Use standard Doxygen-style comments in your header files:

```cpp
/**
 * @brief Brief description of the class
 * 
 * Detailed description of what the class does.
 */
class MyClass {
public:
    /**
     * @brief Brief description of the method
     * 
     * @param param1 Description of param1
     * @param param2 Description of param2
     * @return Description of return value
     */
    int myMethod(int param1, const std::string& param2);
};
```

### Adding Documentation Pages

To add new documentation pages:

1. Create a new `.rst` file in the `docs/` directory
2. Add it to the `toctree` directive in `index.rst`

Example `docs/my_feature.rst`:
```rst
My Feature
==========

.. doxygenfile:: MyFeature.hpp
   :project: CppDesignPatterns
```

## Troubleshooting

### "Doxygen not found"

- Install Doxygen: https://www.doxygen.nl/download.html
- On Windows, ensure it's added to PATH environment variable
- On macOS/Linux, use package manager (brew, apt-get, etc.)

### "Module 'sphinx' not found"

```bash
pip install sphinx breathe sphinx-rtd-theme
```

### XML folder is empty

Run Doxygen separately:
```bash
doxygen ../Doxyfile
```

### Documentation doesn't update

Clean and rebuild:
```bash
# Windows
cd docs
make.bat cleanall
make.bat html

# Unix
cd docs
make cleanall
make html
```

## Customization

- **Theme**: Change `html_theme` in `conf.py` (default: `sphinx_rtd_theme`)
- **Logo**: Add image file to `_static/` and set `html_logo` in `conf.py`
- **CSS**: Create custom stylesheets in `_static/`
- **HTML templates**: Customize in `_templates/`

## Additional Resources

- [Sphinx Documentation](https://www.sphinx-doc.org/)
- [Breathe Documentation](https://breathe.readthedocs.io/)
- [Doxygen Documentation](https://www.doxygen.nl/manual/index.html)
- [reStructuredText Primer](https://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html)

## Building Documentation in CI/CD

These scripts can be integrated into GitHub Actions, GitLab CI, or other CI/CD systems to automatically build and deploy documentation on each commit.
