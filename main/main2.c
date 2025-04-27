#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_timer.h"
#include "esp_pm.h"

// Benchmark configuration
#define ARRAY_SIZE 1000
#define NUM_ITERATIONS 5

// Function declarations
static void generate_random_array(int arr[], int size);
static void bubble_sort(int arr[], int size);
static void print_array(const int arr[], int size);
static void run_benchmark(void);

void app_main(void)
{
    esp_pm_config_esp32s3_t pm_config = {
    .max_freq_mhz = 240,  // Max CPU Frequency (240 MHz)
    .min_freq_mhz = 160,   // Min CPU Frequency (80 MHz)
    .light_sleep_enable = false  // Disable light sleep for stable Wi-Fi
};
esp_pm_configure(&pm_config);

    printf("ESP32 Bubble Sort Benchmark (ESP-IDF)\n");
    printf("=====================================\n\n");
    
    // Run the benchmark
    run_benchmark();
    
    // Print final memory info
    printf("\nFinal Memory Status:\n");
    printf("Free heap: %lu bytes\n", esp_get_free_heap_size());
    printf("Minimum free heap: %lu bytes\n", esp_get_minimum_free_heap_size());
}

static void generate_random_array(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = 5000; // Generate random numbers between 0 and 9999
    }
}

static void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

static void print_array(const int arr[], int size)
{
    printf("Array: ");
    for (int i = 0; i < (size < 10 ? size : 10); i++) { // Print first 10 elements only
        printf("%d ", arr[i]);
    }
    printf("...\n");
}

static void run_benchmark(void)
{
    int *test_array = malloc(ARRAY_SIZE * sizeof(int));
    if (test_array == NULL) {
        printf("Failed to allocate memory for test array!\n");
        return;
    }

    int64_t total_time = 0;
    int64_t min_time = INT64_MAX;
    int64_t max_time = 0;
    
    printf("Running bubble sort benchmark with array size: %d\n", ARRAY_SIZE);
    printf("Number of iterations: %d\n\n", NUM_ITERATIONS);
    
    // Run multiple iterations
    for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
        printf("Iteration %d:\n", iter + 1);
        
        // Generate new random array
        generate_random_array(test_array, ARRAY_SIZE);
        printf("Before sort: ");
        print_array(test_array, ARRAY_SIZE);
        
        // Measure sorting time using esp_timer
        int64_t start_time = esp_timer_get_time();
        bubble_sort(test_array, ARRAY_SIZE);
        int64_t end_time = esp_timer_get_time();
        int64_t duration = end_time - start_time;
        
        printf("After sort:  ");
        print_array(test_array, ARRAY_SIZE);
        
        // Update statistics
        total_time += duration;
        if (duration < min_time) min_time = duration;
        if (duration > max_time) max_time = duration;
        
        printf("Time taken: %lld microseconds\n\n", duration);
        
        // Small delay between iterations
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    
    // Print benchmark results
    printf("Benchmark Results:\n");
    printf("==================\n");
    printf("Average time: %lld microseconds\n", total_time / NUM_ITERATIONS);
    printf("Minimum time: %lld microseconds\n", min_time);
    printf("Maximum time: %lld microseconds\n", max_time);
    
    free(test_array);
}