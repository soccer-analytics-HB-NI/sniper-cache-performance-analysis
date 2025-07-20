#!/bin/bash

# Create output directory
mkdir -p bin

echo "Building cache performance workloads..."

# Compile workloads with optimization
echo "Compiling sequential_access.c..."
gcc -O2 -o bin/sequential_access workloads/sequential_access.c

echo "Compiling random_access.c..."
gcc -O2 -o bin/random_access workloads/random_access.c

echo "Compiling mixed_access.c..."
gcc -O2 -o bin/mixed_access workloads/mixed_access.c

echo "✅ All workloads compiled successfully!"
echo "Generated binaries:"
ls -la bin/