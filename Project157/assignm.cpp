#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Function to perform Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    // Initialize a vector of 100,000 integers in descending order
    std::vector<int> data(100000);
    for (int i = 0; i < 100000; ++i) {
        data[i] = 100000 - i;
    }

    // Measure execution time for Bubble Sort
    auto startBubbleSort = std::chrono::high_resolution_clock::now();
    bubbleSort(data);
    auto endBubbleSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationBubbleSort = endBubbleSort - startBubbleSort;

    // Re-initialize the vector in descending order
    for (int i = 0; i < 100000; ++i) {
        data[i] = 100000 - i;
    }

    // Measure execution time for STL sort
    auto startSTLSort = std::chrono::high_resolution_clock::now();
    std::sort(data.begin(), data.end());
    auto endSTLSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationSTLSort = endSTLSort - startSTLSort;

    // Print execution times
    std::cout << "Bubble Sort Execution Time: " << durationBubbleSort.count() << " seconds\n";
    std::cout << "STL Sort Execution Time: " << durationSTLSort.count() << " seconds\n";

    return 0;
}