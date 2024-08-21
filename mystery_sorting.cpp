#include "mystery_sorting.h"
#include "sorting_algorithms.h" 
using namespace std;

void MysterySort1(vector<int>& arr) {
    selectionSort(arr);
}

void MysterySort2(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1); 
}

void MysterySort3(vector<int>& arr) {
    insertionSort(arr);
}

void MysterySort4(vector<int>& arr) {
    bubbleSort(arr); 
}

void MysterySort5(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1); 
}
