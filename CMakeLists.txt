cmake_minimum_required(VERSION 3.10)
project(CppDesignPatterns)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories for the project
include_directories(${CMAKE_SOURCE_DIR}/Basics/Inc)
include_directories(${CMAKE_SOURCE_DIR}/DesignPatterns/Inc)
include_directories(${CMAKE_SOURCE_DIR}/Application/Inc)

# Source files for Basics library
set(BASICS_SOURCES
    Basics/Src/Pointers.cpp
    Basics/Src/Vector.cpp
)

# Source files for DesignPatterns library
set(DESIGNPATTERNS_SOURCES
    DesignPatterns/Src/CommandPattern.cpp
)

# Source files for Application executable
set(APPLICATION_SOURCES
    Application/Src/main.cpp
)

# Create libraries
add_library(BasicsLib ${BASICS_SOURCES})
add_library(DesignPatternsLib ${DESIGNPATTERNS_SOURCES})

# Create executable
add_executable(CppDesignPatterns ${APPLICATION_SOURCES})

# Link libraries to executable
target_link_libraries(CppDesignPatterns 
    BasicsLib
    DesignPatternsLib
)

# Optional: Add debug and release flags for MSVC
if(MSVC)
    target_compile_options(CppDesignPatterns PRIVATE /W4)
else()
    target_compile_options(CppDesignPatterns PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Print build information
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
