#include <iostream>
#include <vector>
#include "sorting.h"
#include "arrays.h" 

void displayMenu() {
    std::cout << "\nMenu de Opcoes:\n";
    std::cout << "1. Selection Sort\n";
    std::cout << "2. Insertion Sort\n";
    std::cout << "3. Bubble Sort\n";
    std::cout << "4. Quick Sort\n";
    std::cout << "5. Merge Sort\n";
    std::cout << "6. Sair\n";
    std::cout << "Escolha uma opcao: ";
}

void displayArrayOptions() {
    std::cout << "\nEscolha o vetor para ordenar:\n";
    std::cout << "1. Aleatorio 10 elementos\n";
    std::cout << "2. Ordenado 10 elementos\n";
    std::cout << "3. Aleatorio 10000 elementos\n";
    std::cout << "4. Ordenado 10000 elementos\n";
    std::cout << "5. Aleatorio 20000 elementos\n";
    std::cout << "6. Ordenado 20000 elementos\n";
    std::cout << "Escolha: ";
}

int main() {
    int choice, arrayChoice;
    SortMetrics metrics;

    do {
        displayMenu();
        std::cin >> choice;

        if (choice >= 1 && choice <= 5) {
            displayArrayOptions();
            std::cin >> arrayChoice;

            std::vector<int> arr;
            
            switch(arrayChoice) {
                case 1: arr = aleatorio_10; break;
                case 2: arr = ordenado_10; break;
                case 3: arr = aleatorio_10000; break;
                case 4: arr = ordenado_10000; break;
                case 5: arr = aleatorio_20000; break;
                case 6: arr = ordenado_20000; break;
                default:
                    std::cout << "Opcao invalida! Usando aleatorio_10 por padrao.\n";
                    arr = aleatorio_10;
            }

            if (arr.size() == 10) {
                std::cout << "\nArray antes da ordenacao: ";
                printArray(arr);
            }

            switch (choice) {
                case 1: selectionSort(arr, metrics); break;
                case 2: insertionSort(arr, metrics); break;
                case 3: bubbleSort(arr, metrics); break;
                case 4: quickSort(arr, metrics); break;
                case 5: mergeSort(arr, metrics); break;
            }

            if (arr.size() == 10) {
                std::cout << "Array apos ordenacao: ";
                printArray(arr);
            }

            printMetrics(metrics);
        } else if (choice != 6) {
            std::cout << "Opcao invalida! Tente novamente.\n";
        }

    } while (choice != 6);

    std::cout << "Programa encerrado.\n";
    return 0;
}