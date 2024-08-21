#include "mystery_sorting.h"
#include "sorting_algorithms.h"
#include "time_comparison.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sstream>
#include <iomanip>  
#include <algorithm> 
#include <cctype>  
using namespace std;

vector<int> loadData(const string& filename, int permutationIndex) {
    vector<int> data;
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        return data;
    }

    string line;
    int currentIndex = 0;

    while (getline(infile, line)) {
        // If this line starts with "Permutation", we check if it's the one we want
        if (line.find("Permutation") != string::npos) {
            if (currentIndex == permutationIndex) {
                // The next line contains the data we want
                if (getline(infile, line)) {
                    istringstream iss(line);
                    int number;
                    while (iss >> number) {
                        data.push_back(number);
                    }
                }
                break; // No need to read further once we've found our permutation
            }
            currentIndex++;
        }
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

void runAnalysisOnData(const vector<int>& testData, int repetitions, vector<double>& knownTimes, vector<double>& mysteryTimes) {
    knownTimes[0] += measureSortTime(bubbleSort, testData, repetitions);
    knownTimes[1] += measureSortTime(insertionSort, testData, repetitions);
    knownTimes[2] += measureSortTime(selectionSort, testData, repetitions);
    knownTimes[3] += measureSortTime(mergeSortWrapper, testData, repetitions);
    knownTimes[4] += measureSortTime(quickSortWrapper, testData, repetitions);

    mysteryTimes[0] += measureSortTime(MysterySort1, testData, repetitions);
    mysteryTimes[1] += measureSortTime(MysterySort2, testData, repetitions);
    mysteryTimes[2] += measureSortTime(MysterySort3, testData, repetitions);
    mysteryTimes[3] += measureSortTime(MysterySort4, testData, repetitions);
    mysteryTimes[4] += measureSortTime(MysterySort5, testData, repetitions);
}

void printAverageResults(const vector<double>& knownTimes, const vector<double>& mysteryTimes, int iterations) {
    cout << "\nAverage Timing Results (over " << iterations << " datasets):\n";
    const string algorithmNames[] = {
        "Bubble Sort",
        "Insertion Sort",
        "Selection Sort",
        "Merge Sort",
        "Quick Sort"
    };

    cout << "Known Sorting Algorithms Averages:\n";
    for (size_t i = 0; i < knownTimes.size(); ++i) {
        cout << algorithmNames[i] << ": " << fixed << setprecision(10) << (knownTimes[i] / iterations) << " seconds\n";
    }

    cout << "\nMystery Sorting Algorithms Averages:\n";
    for (size_t i = 0; i < mysteryTimes.size(); ++i) {
        cout << "MysterySort" << (i + 1) << ": " << fixed << setprecision(10) << (mysteryTimes[i] / iterations) << " seconds\n";
    }
    cout << endl;
    compareTimes(knownTimes, mysteryTimes);
}

int main() {
    string dataFile = "test_data.txt";
    int repetitions = 100;
    const int numPermutations = 10;

    // Vectors to accumulate the total time for each algorithm
    vector<double> knownTimes(5, 0.0);
    vector<double> mysteryTimes(5, 0.0);

    // Iterate over all permutations
    for (int i = 0; i < numPermutations; i++) {
        cout << "Analyzing dataset: Permutation " << (i + 1) << endl;
        vector<int> testData = loadData(dataFile, i);

        if (testData.empty()) {
            cerr << "Test data for Permutation " << (i + 1) << " is empty. Skipping..." << endl;
            continue;
        }

        runAnalysisOnData(testData, repetitions, knownTimes, mysteryTimes);
    }

    printAverageResults(knownTimes, mysteryTimes, numPermutations);

    return 0;
}
