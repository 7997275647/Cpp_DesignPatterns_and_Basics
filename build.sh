#!/bin/bash
# Build automation script for CppDesignPatterns project
# Supports: build, rebuild, clean, release, debug, and run commands
# Platform: Linux/macOS

set -e  # Exit on error

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BOLD='\033[1m'
NC='\033[0m' # No Color

# Set default values
BUILD_TYPE="Release"
BUILD_DIR="build"
ACTION="build"
GENERATOR="Unix Makefiles"

# Detect if Ninja is available and use it if so
if command -v ninja &> /dev/null; then
    GENERATOR="Ninja"
fi

# Parse command line arguments
if [[ $# -eq 0 ]]; then
    ACTION="build"
else
    ACTION="$1"
fi

if [[ $# -ge 2 ]]; then
    BUILD_TYPE="$2"
fi

# Function: display_help
display_help() {
    cat << EOF

${BOLD}CppDesignPatterns Build Automation Script${NC}

${BOLD}Usage:${NC} ./build.sh [ACTION] [BUILD_TYPE]

${BOLD}Actions:${NC}
  build       - Build the project (default)
  rebuild     - Clean and rebuild the project
  clean       - Clean build artifacts
  run         - Build and run the project
  release     - Build release configuration
  debug       - Build debug configuration
  help        - Show this help message

${BOLD}Build Types:${NC}
  Release     - Optimized build (default)
  Debug       - Debug build with symbols

${BOLD}Examples:${NC}
  ./build.sh                    - Build release version
  ./build.sh debug              - Build debug version
  ./build.sh rebuild release    - Rebuild release version
  ./build.sh run debug          - Build and run debug version

EOF
}

# Function: build_project
build_project() {
    echo
    echo "${BOLD}============================================================${NC}"
    echo "Building $BUILD_TYPE Configuration"
    echo "${BOLD}============================================================${NC}"
    echo

    # Create build directory if it doesn't exist
    if [[ ! -d "$BUILD_DIR" ]]; then
        mkdir -p "$BUILD_DIR"
    fi

    # Run CMake configuration
    echo "[1/2] Configuring project..."
    cd "$BUILD_DIR"
    
    cmake -G "$GENERATOR" \
        -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
        -DCMAKE_CXX_STANDARD=17 \
        ..
    
    if [[ $? -ne 0 ]]; then
        echo "${RED}Error: CMake configuration failed${NC}"
        cd ..
        exit 1
    fi

    # Build the project
    echo
    echo "[2/2] Building project..."
    cmake --build . --config "$BUILD_TYPE"
    
    if [[ $? -ne 0 ]]; then
        echo "${RED}Error: Build failed${NC}"
        cd ..
        exit 1
    fi

    cd ..
    echo
    echo "${BOLD}============================================================${NC}"
    echo "${GREEN}Build Complete!${NC}"
    echo "Output directory: $BUILD_DIR/bin/$BUILD_TYPE"
    echo "${BOLD}============================================================${NC}"
    echo
}

# Function: clean_project
clean_project() {
    echo
    echo "${BOLD}============================================================${NC}"
    echo "Cleaning Build Artifacts"
    echo "${BOLD}============================================================${NC}"
    echo

    if [[ -d "$BUILD_DIR" ]]; then
        echo "Removing $BUILD_DIR directory..."
        rm -rf "$BUILD_DIR"
        echo "${GREEN}Clean complete.${NC}"
    else
        echo "Nothing to clean."
    fi
    echo
}

# Function: run_project
run_project() {
    echo
    echo "${BOLD}============================================================${NC}"
    echo "Running Application"
    echo "${BOLD}============================================================${NC}"
    echo

    local exe_path="$BUILD_DIR/bin/$BUILD_TYPE/CppDesignPatterns"
    
    if [[ -f "$exe_path" ]]; then
        echo "Launching: $exe_path"
        exec "$exe_path"
    else
        echo "${RED}Error: Executable not found at $exe_path${NC}"
        exit 1
    fi
    echo
}

# Main script logic
case "$ACTION" in
    build)
        build_project
        ;;
    rebuild)
        clean_project
        build_project
        ;;
    clean)
        clean_project
        ;;
    run)
        build_project
        run_project
        ;;
    release)
        BUILD_TYPE="Release"
        build_project
        ;;
    debug)
        BUILD_TYPE="Debug"
        build_project
        ;;
    help)
        display_help
        ;;
    *)
        echo "${RED}Unknown action: $ACTION${NC}"
        echo "Use './build.sh help' for usage information"
        exit 1
        ;;
esac
