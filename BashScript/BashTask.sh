#!/bin/bash

# Verify that a source directory was provided as an argument
if [ $# -eq 0 ]; then
    echo "Please provide a source directory."
    exit 1
fi

SOURCE_DIR="$1"

# Ensure the subdirectories exist
mkdir -p "$SOURCE_DIR/images"
mkdir -p "$SOURCE_DIR/documents"
mkdir -p "$SOURCE_DIR/others"

# Iterate over each item in the source directory
for item in "$SOURCE_DIR"/*; do
    # Only process regular files
    if [ -f "$item" ]; then
        # Extract the file extension
        extension="${item##*.}"
        
        # Determine the appropriate subdirectory and move the file
        if [[ "$extension" =~ ^(jpg|png|gif)$ ]]; then
            mv "$item" "$SOURCE_DIR/images/"
        elif [[ "$extension" =~ ^(txt|doc|pdf)$ ]]; then
            mv "$item" "$SOURCE_DIR/documents/"
        else
            mv "$item" "$SOURCE_DIR/others/"
        fi
    fi
done

echo "Organization complete."
