#!/bin/bash

if [[ -f "out/annoyingmarkdown"  ]]; then
    sudo cp out/annoyingmarkdown /usr/bin/
else
    echo "You probably didn't compile project."
fi
