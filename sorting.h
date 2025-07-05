#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <chrono>

struct SortMetrics {
    long comparisons = 0;
    long swaps = 0;
    double duration = 0.0;
};

void selectionSort(std::vector<int>& arr, SortMetrics& metrics);
void insertionSort(std::vector<int>& arr, SortMetrics& metrics);
void bubbleSort(std::vector<int>& arr, SortMetrics& metrics);
void quickSort(std::vector<int>& arr, SortMetrics& metrics);
void mergeSort(std::vector<int>& arr, SortMetrics& metrics);
void printArray(const std::vector<int>& arr);
void printMetrics(const SortMetrics& metrics);

#endif