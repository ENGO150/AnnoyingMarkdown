#!/bin/bash

####################

# Remove previous output
rm -rf out/*

# Variables
files="
      src/*.c
      "

compiler="gcc"

os="$(uname)"
os="$(echo $os | tr '[:upper:]' '[:lower:]')" # Lower case

if [[ $os == "darwin" ]]; then os="macos"; fi

output="out/annoyingmarkdown_$os"

# Check for Windows
if [[ $os == "windows" ]]; then
    output="$output.exe"
fi

###
echo "Getting default compiler..."
###

# Get compiler
if [[ "$os" == "linux" ]]; then
    compiler="cc"
fi

###
echo "Using '$compiler' as default compiler."
echo "Compilíng..."
###

# Compile
$compiler $files -o $output

###
echo "Output generated as '$output'"
###
