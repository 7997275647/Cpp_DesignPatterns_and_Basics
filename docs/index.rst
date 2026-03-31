C++ Design Patterns and Basics Documentation
==============================================

Welcome to the comprehensive documentation of the **C++ Design Patterns and Basics** project. This documentation covers design patterns implementation, C++ fundamentals, and practical examples.

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   design_patterns
   basics
   application
   modules

.. contents:: Table of Contents
   :local:

Introduction
============

This project demonstrates:

- **C++ Design Patterns**: Common design patterns like Command, Observer, State, Chain of Responsibility, and Template Method
- **C++ Basics**: Fundamental concepts including pointers, vectors, operator overloading, and two-pointer techniques
- **Practical Application**: Real-world examples combining these patterns and techniques

Project Structure
=================

- **Basics/**: Core C++ fundamentals and utilities
- **DesignPatterns/**: Implementation of various design patterns
- **Application/**: Main application using the libraries

Getting Started
===============

The project is built using CMake and supports both Unix-like systems and Windows.

Build Instructions
------------------

On Unix-like systems::

    ./build.sh

On Windows::

    .\build.bat

Or using CMake manually::

    mkdir build
    cd build
    cmake ..
    cmake --build .

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
