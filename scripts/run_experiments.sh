#!/bin/bash

# Create results directory
mkdir -p results

echo "Running cache performance experiments..."

# Run experiments with different configurations
WORKLOADS=("sequential_access" "random_access" "mixed_access")
CONFIGS=("cache_l1_32k" "cache_l1_16k")

for config in "${CONFIGS[@]}"; do
    for workload in "${WORKLOADS[@]}"; do
        echo "Running $workload with $config configuration..."
        
        # Run simulation
        $SNIPER_ROOT/run-sniper \
            --cfg $config \
            --stats-output "results/${workload}_${config}" \
            -- bin/$workload
            
        echo "Completed $workload with $config"
    done
done

echo "All experiments completed!"