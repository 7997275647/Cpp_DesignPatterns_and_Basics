# C++ Design Patterns and Basics

A comprehensive C++ project demonstrating classic software design patterns in modern C++ (C++17).

## Overview

This project serves as a learning resource for C++ developers, featuring:

- **C++ Fundamentals**: Essential concepts including pointers, vectors, operator overloading, and two-pointer algorithms
- **Design Patterns**: Implementation of 5 classic Gang of Four design patterns with practical examples
- **Well-Documented Code**: Comprehensive API documentation generated with Doxygen and Sphinx
- **Cross-Platform Build System**: CMake-based build configuration supporting Windows, macOS, and Linux


## Requirements

### Prerequisites

- **C++17 or later** compiler (MSVC, GCC, or Clang)
- **CMake 3.10+** for building
- **Python 3.7+** (for documentation generation)
- **Doxygen** (for C++ documentation parsing)

### Setup

#### Windows

1. **Install CMake**: Download from [cmake.org](https://cmake.org/download/)
2. **Install a C++ compiler**:
   - Visual Studio 2019 or later with C++ workload, or
   - MinGW-w64
3. **Install Doxygen**: Download from [doxygen.nl](https://www.doxygen.nl/download.html)
   - Ensure Doxygen is added to your PATH


## Project Structure

```
.
├── Application/              # Main executable entry point
│   ├── Inc/
│   │   └── main.hpp         # Main function declaration
│   └── Src/
│       └── main.cpp         # Application entry point
│
├── Basics/                   # C++ fundamentals library
│   ├── Inc/
│   │   ├── Pointers.hpp
│   │   ├── Vector.hpp
│   │   ├── TwoPointers.hpp
│   │   └── OperatorOverloading.hpp
│   └── Src/
│       ├── Pointers.cpp
│       ├── Vector.cpp
│       ├── TwoPointers.cpp
│       └── OperatorOverloading.cpp
│
├── DesignPatterns/           # Design patterns library
│   ├── Inc/
│   │   ├── CommandPattern.hpp
│   │   ├── ObserverPattern.hpp
│   │   ├── StatePattern.hpp
│   │   ├── ChainofResponsibilityPattern.hpp
│   │   └── TemplateMethodDesignPattern.hpp
│   ├── Src/
│   │   ├── CommandPattern.cpp
│   │   ├── ObserverPattern.cpp
│   │   ├── StatePattern.cpp
│   │   ├── ChainofResponsibilityPattern.cpp
│   │   └── TemplateMethodDesignPattern.cpp
│   └── Docs/
│       └── CommandPattern.md # Pattern documentation
│
├── docs/                     # Sphinx documentation
│   ├── conf.py              # Sphinx configuration
│   ├── index.rst            # Documentation main page
│   ├── basics.rst           # Basics documentation
│   ├── design_patterns.rst  # Design patterns documentation
│   ├── application.rst      # Application documentation
│   └── requirements.txt     # Python dependencies
│
├── CMakeLists.txt           # CMake configuration
├── Doxyfile                 # Doxygen configuration
├── build.bat                # Windows build script
├── build.sh                 # Unix build script
├── build_docs.bat           # Windows documentation build script
└── build_docs.sh            # Unix documentation build script
```

## Documentation

### Generating API Documentation

The project includes comprehensive API documentation using Doxygen and Sphinx.

#### Windows

```bash
.\build_docs.bat
# Open generated documentation
start docs\_build\html\index.html
```

### View Documentation

Generated HTML documentation is available at:
- **Windows**: `docs\_build\html\index.html`
- **Unix**: `docs/_build/html/index.html`

## Usage Examples

### Running the Application

After building, run the executable:

```bash
# Windows
.\build\bin\Release\CppDesignPatterns.exe

```


## Configuration

### C++ Standard

The project is configured for **C++17**. To use a different standard, modify [CMakeLists.txt](CMakeLists.txt):

```cmake
set(CMAKE_CXX_STANDARD 20)  # Change to desired standard
```

### Compiler Warnings

- **Windows (MSVC)**: `/W4` (Warning Level 4)
- **Unix (GCC/Clang)**: `-Wall -Wextra -Wpedantic`

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/YourFeature`)
3. Commit your changes (`git commit -m 'Add YourFeature'`)
4. Push to the branch (`git push origin feature/YourFeature`)
5. Open a Pull Request

Please ensure:
- Code follows project conventions
- Documentation is updated
- All builds succeed without errors
- Compiler warnings are addressed


## Related Documentation

- [C++ Standard Reference](https://en.cppreference.com/)
- [Design Patterns: Elements of Reusable Object-Oriented Software](https://en.wikipedia.org/wiki/Design_Patterns) by Gang of Four
- [CMake Documentation](https://cmake.org/documentation/)
- [Doxygen Manual](https://www.doxygen.nl/manual/index.html)

## License

This project is open source and available under the [MIT License](LICENSE).

## Author

Created as a resource for C++ development and design patterns.

## Support

For issues, questions, or suggestions:
- Open an issue on the GitHub repository
- Check the [documentation](docs/)
- Review code examples in the respective modules

---

**Happy learning!** 🚀
