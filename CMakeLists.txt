cmake_minimum_required(VERSION 3.10)
project(MyCompilerTool CXX)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${CMAKE_SOURCE_DIR}/inc)

# Source files
set(SOURCES
    src/compiler.cpp
    src/linker.cpp
    src/scanner.cpp
    src/service.cpp
    mycompiler.cpp
)

add_executable(mycompiler ${SOURCES})
