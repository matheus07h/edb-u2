#include "sorting.h"
#include <iostream>
#include <chrono>

void selectionSort(std::vector<int>& arr, SortMetrics& metrics) {
    auto start = std::chrono::high_resolution_clock::now();
    metrics = {0, 0, 0.0};
    
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            metrics.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[min_idx], arr[i]);
            metrics.swaps++;
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    metrics.duration = std::chrono::duration<double, std::milli>(end - start).count();
}

void insertionSort(std::vector<int>& arr, SortMetrics& metrics) {
    auto start = std::chrono::high_resolution_clock::now();
    metrics = {0, 0, 0.0};
    
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (true) {
            if (j >= 0) {
                metrics.comparisons++;
                if (arr[j] > key) {
                    arr[j + 1] = arr[j];
                    metrics.swaps++;
                    j--;
                    continue;
                }
            }
            break;
        }
        arr[j + 1] = key;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    metrics.duration = std::chrono::duration<double, std::milli>(end - start).count();
}

void bubbleSort(std::vector<int>& arr, SortMetrics& metrics) {
    auto start = std::chrono::high_resolution_clock::now();
    metrics = {0, 0, 0.0};
    
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            metrics.comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                metrics.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    metrics.duration = std::chrono::duration<double, std::milli>(end - start).count();
}

void quickSortHelper(std::vector<int>& arr, int low, int high, SortMetrics& metrics) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            metrics.comparisons++;
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
                metrics.swaps++;
            }
        }
        std::swap(arr[i + 1], arr[high]);
        metrics.swaps++;
        int pi = i + 1;

        quickSortHelper(arr, low, pi - 1, metrics);
        quickSortHelper(arr, pi + 1, high, metrics);
    }
}

void quickSort(std::vector<int>& arr, SortMetrics& metrics) {
    auto start = std::chrono::high_resolution_clock::now();
    metrics = {0, 0, 0.0};
    
    quickSortHelper(arr, 0, arr.size() - 1, metrics);
    
    auto end = std::chrono::high_resolution_clock::now();
    metrics.duration = std::chrono::duration<double, std::milli>(end - start).count();
}

void merge(std::vector<int>& arr, int left, int mid, int right, SortMetrics& metrics) {
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        metrics.comparisons++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
        metrics.swaps++;
    }

    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
        metrics.swaps++;
    }
    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
        metrics.swaps++;
    }
}

void mergeSortHelper(std::vector<int>& arr, int left, int right, SortMetrics& metrics) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortHelper(arr, left, mid, metrics);
        mergeSortHelper(arr, mid + 1, right, metrics);
        merge(arr, left, mid, right, metrics);
    }
}

void mergeSort(std::vector<int>& arr, SortMetrics& metrics) {
    auto start = std::chrono::high_resolution_clock::now();
    metrics = {0, 0, 0.0};
    
    mergeSortHelper(arr, 0, arr.size() - 1, metrics);
    
    auto end = std::chrono::high_resolution_clock::now();
    metrics.duration = std::chrono::duration<double, std::milli>(end - start).count();
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void printMetrics(const SortMetrics& metrics) {
    std::cout << "\nMetricas de desempenho:\n";
    std::cout << "Tempo de execucao: " << metrics.duration << " ms\n";
    std::cout << "Comparacoes realizadas: " << metrics.comparisons << "\n";
    std::cout << "Trocas realizadas: " << metrics.swaps << "\n";
}