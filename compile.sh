#!/bin/bash
set -evx
for dir in */; do
    if [ -d "$dir" ]; then
        cd "$dir"
        for dir2 in */; do
            if [ -d "$dir2" ]; then
                cd "$dir2"
                ls
                FILE=main.cpp

                if test -f $FILE; then
                    g++ -std=c++17 -DENABLE_BREAK main.cpp -o executable
                fi

                cd ..
            fi
        done
        cd ..
    fi
done
