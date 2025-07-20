#!/bin/bash

# Create output directory
mkdir -p bin

# Compile workloads
echo "Compiling workloads..."
gcc -O2 -o bin/sequential_access workloads/sequential_access.c
gcc -O2 -o bin/random_access workloads/random_access.c
gcc -O2 -o bin/mixed_access workloads/mixed_access.c

echo "Workloads compiled successfully!"