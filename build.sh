#!/bin/bash

####################

# Remove previous output
rm -rf out/*

# Variables
files="
      src/*.c
      "

compiler="cc"

os="$(uname)"
os="$(echo $os | tr '[:upper:]' '[:lower:]')" # Lower case

if [[ $os == "darwin" ]]; then os="macos"; fi # MacOS fix

output="out/annoyingmarkdown_$os"

###
echo "Getting default compiler..."
###

# Get compiler
if [[ "$os" == "macos" ]]; then
    compiler="gcc"
fi

###
echo "Using '$compiler' as default compiler."
echo "Compiling..."
###

# Compile
$compiler $files -o $output

###
echo "Output generated as '$output'"
###

if [[ $1 == "install" ]]; then
    if [[ -f $output ]]; then
        cp $output /usr/bin/annoyingmarkdown
    else
        echo "Compilation probably failed. ($output not found)"
    fi
fi
