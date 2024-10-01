#!/bin/bash
# (c)2023 Nathan Greenfield

# Pull the graded tests
wget "https://drive.google.com/uc?export=download&id=1H6YW8yWXORjzsxaH6U6TXx-dE3treOZb" -O hw05.tar.gz
tar xzf hw05.tar.gz

echo "Compiling..."
mkdir build
cd build
RELEASE=ON CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
make || exit 1

# Return to root folder (so cwd is correct)
cd ..

# Run student tests
echo "Running student tests..."
timeout 30 build/tests/tests [student] || exit 1

# Run graded tests
echo "Running graded tests..."
timeout 30 build/tests/tests [graded] || exit 1

