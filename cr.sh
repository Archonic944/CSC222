#!/bin/bash

# Check if the input is provided
if [ $# -eq 0 ]; then
    echo "Please provide a C++ file name or a directory as an argument."
    exit 1
fi

# Check if the input is a file or a directory
if [ -f "$1" ]; then
    # Input is a file
    # Extract the file name without the extension
    filename=$(basename "$1")
    filename="${filename%.*}"

    # Compile the C++ file
    mkdir -p ./out
    g++ -o "./out/$filename.out" "$1"

    # Execute the compiled C++ file
    "./out/$filename.out"

elif [ -d "$1" ]; then
    # Input is a directory
    # Set CPATH environment variable
    export CPATH=/usr/local/lib/gcc/include

    # Find all .cc and .cpp files in the directory and compile them
    cpp_files=$(find "$1" -type f \( -name "*.cc" -o -name "*.cpp" \))
    if [ -z "$cpp_files" ]; then
        echo "No .cc or .cpp files found in the directory."
        exit 1
    fi

    # Compile all .cc and .cpp files
    mkdir -p ./out
    g++ -o ./out/all_files_combined.out $cpp_files --std=c++11

    # Execute the compiled binary
    ./out/all_files_combined.out
else
    echo "The provided argument is neither a file nor a directory."
    exit 1
fi