#!/bin/bash

rm -rf out/*

if [[ "$(uname)" == "Darwin" ]]; then
    make mac
else
    make
fi