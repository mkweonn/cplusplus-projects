#!/bin/bash
# (c)2023 Nathan Greenfield

# Pull the graded tests
wget "https://drive.google.com/uc?export=download&id=1MvwZb0INMoP7Sqwx8skInq0nZ9voYauY" -O hw07.tar.gz
tar xzf hw07.tar.gz

echo "Compiling..."
mkdir build
cd build
RELEASE=ON CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
make || exit 1

#echo "Running clang-tidy..."
#../run-clang-tidy.py -quiet -header-filter=.*/src/.* || exit 1

# Return to root folder (so cwd is correct)
cd ..

# Run student tests
echo "Running student tests..."
timeout 30 build/tests/tests [student] || exit 1

# Run graded tests
echo "Running graded tests..."
timeout 30 build/tests/tests [graded] || exit 1
