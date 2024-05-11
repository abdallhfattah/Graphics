# Makefile for compiling and running the program

# Compiler
CXX = x86_64-w64-mingw32-g++
# Compiler flags
CXXFLAGS = -mwindows -lgdi32 -static

# Source files
CPP_FILES = \
			src/circle/circle.cpp \
			src/main.cpp \
			# src/fillingAlgorithm/filling.cpp \
			# src/line/line.cpp \

# Output file
OUTPUT_FILE = output.exe

# Default target
all: $(OUTPUT_FILE)

# Rule to compile the program
$(OUTPUT_FILE): $(CPP_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to run the program
run: $(OUTPUT_FILE)
	wine64 $(OUTPUT_FILE)

# Rule to clean up generated files
clean:
	rm -f $(OUTPUT_FILE)

# Phony targets
.PHONY: all run clean

