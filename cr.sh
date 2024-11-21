#!/bin/bash

# Check if at least one input file is provided
if [ $# -eq 0 ]; then
    echo "Please provide one or more C++ files as arguments."
    exit 1
fi

# Export CPATH
export CPATH=/usr/local/lib/gcc/include

# Validate input files and prepare the file list for compilation
cpp_files=""
for file in "$@"; do
    if [ -f "$file" ]; then
        cpp_files="$cpp_files $file"
    else
        echo "Warning: '$file' is not a valid file. Skipping."
    fi
done

# Check if any valid files were found
if [ -z "$cpp_files" ]; then
    echo "No valid C++ files provided. Exiting."
    exit 1
fi

# Create output directory
mkdir -p ./out

# Compile the provided files
output_file="./out/combined_files.out"
g++ -o "$output_file" $cpp_files --std=c++11

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executing the binary..."
    # Execute the compiled binary
    "$output_file"
else
    echo "Compilation failed. Please check your code for errors."
    exit 1
fi