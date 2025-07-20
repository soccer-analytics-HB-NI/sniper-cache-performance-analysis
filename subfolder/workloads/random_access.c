#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000
#define ITERATIONS 10

int main() {
    int *array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    int *indices = (int*)malloc(ARRAY_SIZE * sizeof(int));
    long long sum = 0;
    
    // Initialize array and random indices
    srand(42); // Fixed seed for reproducibility
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
        indices[i] = rand() % ARRAY_SIZE;
    }
    
    clock_t start = clock();
    
    // Random access pattern (low spatial locality)
    for (int iter = 0; iter < ITERATIONS; iter++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            sum += array[indices[i]];
        }
    }
    
    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Random Access Results:\n");
    printf("Sum: %lld\n", sum);
    printf("CPU Time: %f seconds\n", cpu_time);
    
    free(array);
    free(indices);
    return 0;
}