#!/bin/bash
# ©2023 Nathan Greenfield

# Pull the graded tests
wget "https://drive.google.com/uc?export=download&id=14WyOlX2P0iy2hrNm-WjxJYaxJEIFrusy" -O hw01.tar.gz
tar xzf hw01.tar.gz

# Cmake into build directory
echo "Compiling..."
mkdir build
cd build
CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
make || exit 1

# Return to root folder (so cwd is correct)
cd ..

# Run graded tests
echo "Running graded tests..."
timeout 30 build/tests/tests [graded] || exit 1
