#!/bin/bash

for i in $(ls inputs/invalid)
    do
        echo "Testing $i" >> leaks.txt
        valgrind ./lem-in < inputs/invalid/$i 2>> leaks.txt
        echo "----------------------------------------" >> leaks.txt
    done