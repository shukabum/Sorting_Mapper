#include "sorting_algorithms.h"
#include "time_comparison.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;


vector<int> loadData(const string& filename) {
    vector<int> data;
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        return data;
    }

    int number;
    while (infile >> number) {
        data.push_back(number);
    }

    infile.close();
    return data;
}

void mergeSortWrapper(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

void quickSortWrapper(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

void MysterySort1(vector<int>& arr) { mergeSortWrapper(arr); }
void MysterySort2(vector<int>& arr) { quickSortWrapper(arr); }
void MysterySort3(vector<int>& arr) { bubbleSort(arr); }
void MysterySort4(vector<int>& arr) { insertionSort(arr); }
void MysterySort5(vector<int>& arr) { selectionSort(arr); }

int main() {
    string dataFile = "test_data.txt";
    vector<int> testData = loadData(dataFile);

    if (testData.empty()) {
        cerr << "Test data is empty. Exiting..." << endl;
        return 1;
    }

    int repetitions = 10000000;

    vector<double> knownTimes(5);
    knownTimes[0] = measureSortTime(bubbleSort, testData, repetitions);
    knownTimes[1] = measureSortTime(insertionSort, testData, repetitions);
    knownTimes[2] = measureSortTime(selectionSort, testData, repetitions);
    knownTimes[3] = measureSortTime(mergeSortWrapper, testData, repetitions);
    knownTimes[4] = measureSortTime(quickSortWrapper, testData, repetitions);


    vector<double> mysteryTimes(5);
    mysteryTimes[0] = measureSortTime(MysterySort1, testData, repetitions);
    mysteryTimes[1] = measureSortTime(MysterySort2, testData, repetitions);
    mysteryTimes[2] = measureSortTime(MysterySort3, testData, repetitions);
    mysteryTimes[3] = measureSortTime(MysterySort4, testData, repetitions);
    mysteryTimes[4] = measureSortTime(MysterySort5, testData, repetitions);

    compareTimes(knownTimes, mysteryTimes);

    return 0;
}
