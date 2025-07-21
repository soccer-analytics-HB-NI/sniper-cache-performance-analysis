#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000
#define ITERATIONS 10
#define SEQUENTIAL_RATIO 0.7

int main() {
    int *array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    long long sum = 0;
    
    // Initialize array
    srand(42);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }
    
    clock_t start = clock();
    
    // Mixed access pattern (70% sequential, 30% random)  
    for (int iter = 0; iter < ITERATIONS; iter++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if ((double)rand() / RAND_MAX < SEQUENTIAL_RATIO) {
                // Sequential access
                sum += array[i];
            } else {
                // Random access
                int random_index = rand() % ARRAY_SIZE;
                sum += array[random_index];
            }
        }
    }
    
    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Mixed Access Results:\n");
    printf("Sum: %lld\n", sum);
    printf("CPU Time: %f seconds\n", cpu_time);
    
    free(array);
    return 0;
}
