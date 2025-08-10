# cyon-shell

## Overview
**cyon-shell** is a custom C++ build and compilation utility.  
It provides a command-line interface to compile and link C++ source files,  
with support for specifying file names and optional directories.  
The tool is designed for flexibility and automation in small to medium-sized C++ projects.

## Features
- Compile C++ source files using **Clang** (more compiler support planned).
- Accepts file name and optional directory path as arguments.
- Uses the provided directory or defaults to the current working directory.
- Handles basic compilation workflows without external build dependencies.

## Project Structure
inc/ # Header files
src/ # Implementation files
mycompiler.cpp # Main entry for CLI tool

markdown
Copy
Edit

## Requirements
- Clang (`clang++`)
- C++20 or newer
- CMake (optional, for build system generation)
- Make or Ninja (optional, for building)

## Building

### Using CMake
```bash
mkdir build
cd build
cmake ..
cmake --build .
Using Make
bash
Copy
Edit
make
Usage
From the build directory or after installing the executable:

bash
Copy
Edit
./mycompiler <file-name> [directory]
Examples
bash
Copy
Edit
# Compile file in the current directory
./mycompiler main.cpp

# Compile file from a specified directory
./mycompiler main.cpp /home/user/project/src
Future Plans
Support for additional compilers (GCC, MSVC, etc.).

Extended build configuration options.

Dependency tracking for faster incremental builds.
