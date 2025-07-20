#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000
#define ITERATIONS 10

int main() {
    int *array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    long long sum = 0;
    
    // Initialize array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }
    
    clock_t start = clock();
    
    // Sequential access pattern (high spatial locality)
    for (int iter = 0; iter < ITERATIONS; iter++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            sum += array[i];
        }
    }
    
    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Sequential Access Results:\n");
    printf("Sum: %lld\n", sum);
    printf("CPU Time: %f seconds\n", cpu_time);
    
    free(array);
    return 0;
}