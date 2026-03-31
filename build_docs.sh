#!/bin/bash
# Build script for documentation on Unix-like systems

echo "Installing Python dependencies..."
pip install -r docs/requirements.txt

echo ""
echo "Checking for Doxygen installation..."
if ! command -v doxygen &> /dev/null; then
    echo "Warning: Doxygen is not installed"
    echo "Please install Doxygen using: brew install doxygen (macOS) or apt-get install doxygen (Linux)"
    exit 1
fi

echo ""
echo "Creating build directories..."
mkdir -p docs/doxygen

echo ""
echo "Running Doxygen..."
doxygen Doxyfile

echo ""
echo "Building Sphinx documentation..."
cd docs
rm -rf _build
make html

echo ""
echo "Documentation generated successfully!"
echo "Open _build/html/index.html to view the documentation."
