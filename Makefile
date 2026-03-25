.PHONY: all clean build release debug help

# Build directory
BUILD_DIR := build
RELEASE_DIR := $(BUILD_DIR)/release
DEBUG_DIR := $(BUILD_DIR)/debug

# Compiler settings
CMAKE := cmake
CMAKE_FLAGS := -DCMAKE_CXX_STANDARD=17

all: release

help:
	@echo "Available targets:"
	@echo "  make build    - Build the project (default)"
	@echo "  make release  - Build release version with optimizations"
	@echo "  make debug    - Build debug version with symbols"
	@echo "  make clean    - Clean all build artifacts"
	@echo "  make help     - Display this help message"

build: release

release:
	@echo "Building Release configuration..."
	@mkdir -p $(RELEASE_DIR)
	@cd $(RELEASE_DIR) && $(CMAKE) -DCMAKE_BUILD_TYPE=Release $(CMAKE_FLAGS) ../..
	@cd $(RELEASE_DIR) && $(CMAKE) --build . --config Release
	@echo "Release build complete. Output in $(RELEASE_DIR)/bin"

debug:
	@echo "Building Debug configuration..."
	@mkdir -p $(DEBUG_DIR)
	@cd $(DEBUG_DIR) && $(CMAKE) -DCMAKE_BUILD_TYPE=Debug $(CMAKE_FLAGS) ../..
	@cd $(DEBUG_DIR) && $(CMAKE) --build . --config Debug
	@echo "Debug build complete. Output in $(DEBUG_DIR)/bin"

clean:
	@echo "Cleaning build directories..."
	@rm -rf $(BUILD_DIR)
	@echo "Clean complete."

run-release: release
	@echo "Running release build..."
	@$(RELEASE_DIR)/bin/CppDesignPatterns

run-debug: debug
	@echo "Running debug build..."
	@$(DEBUG_DIR)/bin/CppDesignPatterns
