#!/usr/bin/env bash

# clear previous output
clear

cd src

# compile C code
gcc index_sort.c main.c array.c -o ../out/main

# run generated executable
../out/main
