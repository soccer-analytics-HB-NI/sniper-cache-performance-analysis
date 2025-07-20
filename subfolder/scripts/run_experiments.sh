#!/bin/bash

echo "Running cache performance experiments..."

# Create results directory
mkdir -p results

echo "Running native performance tests..."
echo "=== Sequential Access ==="
./bin/sequential_access

echo "=== Random Access ==="
./bin/random_access

echo "=== Mixed Access ==="
./bin/mixed_access

echo "✅ All experiments completed!"