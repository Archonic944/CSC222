#!/bin/bash

# Check if the file name is provided as an argument
if [ $# -eq 0 ]; then
    echo "Please provide the C++ file name as an argument."
    exit 1
fi

# Extract the file name without the extension
filename=$(basename "$1")
filename="${filename%.*}"

# Check for cout without endl or cout after endl
#check_cout_without_endl "$1"

# Compile the C++ file
g++ -o "./out/$filename.out" "$1"

# Execute the compiled C++ file
"./out/$filename.out"