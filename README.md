📊 ESP32-S3 Bubble Sort Benchmark with DFS Analysis 🚀

Optimizing Energy Consumption and Real-Time Performance in IoT-Driven Embedded Systems: A Scheduling Framework for Single, Dual, and Distributed Core Microcontroller (ESP32-S3) - Here its 1st part of this project and this repository contains a benchmark test for the ESP32-S3, comparing the performance of the bubble sort algorithm with and without DFS enabled. The project measures execution time, power efficiency, and memory usage using the ESP-IDF framework and also Computation Performance (Factorial and Fibonacci) , GPIO Toggling Speed, Floating-Point Performance (Sin/Cos Computation and FFT Calculations) results are also included with this repository.

📌 Key Features 

⚡ Dynamic Frequency Scaling (DFS)
Configurable CPU frequencies (80 MHz to 240 MHz).
Power-saving mode for energy-efficient operations.

📊 Performance Benchmarking

Measures sorting time for a 1000-element array.
Tracks average, min, and max execution times across multiple iterations.

📈 Comparative Analysis

Compares results with DFS enabled (80-240 MHz) vs. fixed frequency (240 MHz).
Includes memory usage statistics (heap, fragmentation).

🔧 ESP-IDF Integration

Uses esp_timer for precise timing.
Supports FreeRTOS task management.

📋 Benchmark Results ⏱️ Execution Time (Bubble Sort - 1000 Elements) Configuration Avg Time (µs) Min Time (µs) Max Time (µs) DFS Enabled 30,000 30,000 30,015 DFS Disabled 39,010 39,008 39,016

📉 Key Observations

DFS reduces execution time by ~23% (fixed 240 MHz vs. DFS scaling).
Consistent performance across iterations (low variance).
Memory efficiency: ~388 KB free heap after benchmark.

🛠️ Hardware & Software Setup

🔌 Hardware

Board: ESP32-S3
CPU Frequency: 80–240 MHz (configurable via esp_pm).
Monitoring Tools:
Logic analyzer (for GPIO toggling).
Multimeter (power consumption).

💻 Software

Framework: ESP-IDF (latest stable release).
Libraries: freertos, esp_timer, esp_pm.
IDE: VS Code with ESP-IDF extension.

📊 Graphical Analysis

Performance Comparison
(DFS vs. Fixed Frequency: Execution time and power trade-offs.)

📜 Project Documentation

📄 Benchmark Report: Detailed DFS impact analysis.

🤝 Contributing

Open to improvements! Submit PRs for:
🧩 Additional sorting algorithms (QuickSort, MergeSort).
🔋 Power consumption profiling.
📶 WiFi/Bluetooth performance tests.

📧 Contact 

Author: Ajish Suresh Kumar
Email: ajishsureshkumar@gmail.com

🎉 Happy Benchmarking!


