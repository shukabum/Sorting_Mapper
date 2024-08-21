#include "time_comparison.h"
#include <iostream>
#include <vector>
#include <chrono>  
#include <cmath> 
#include <iomanip>  

using namespace std;
using namespace std::chrono;

double measureSortTime(void (*sortFunc)(vector<int>&), vector<int> arr, int repetitions) {
    auto start = high_resolution_clock::now();  
    for (int i = 0; i < repetitions; ++i) {
        vector<int> temp = arr;
        sortFunc(temp);
    }
    auto end = high_resolution_clock::now();    
    duration<double> elapsed = end - start;     
    double averageTime = elapsed.count() / repetitions;  
    return averageTime;
}

void compareTimes(const vector<double>& knownTimes, const vector<double>& mysteryTimes) {
    const string algorithmNames[] = {
        "Bubble Sort",
        "Insertion Sort",
        "Selection Sort",
        "Merge Sort",
        "Quick Sort"
    };


    for (size_t i = 0; i < mysteryTimes.size(); ++i) {
        double minDifference = abs(knownTimes[0] - mysteryTimes[i]);
        int minIndex = 0;
        for (size_t j = 1; j < knownTimes.size(); ++j) {
            double difference = abs(knownTimes[j] - mysteryTimes[i]);
            if (difference < minDifference) {
                minDifference = difference;
                minIndex = j;
            }
        }
        cout << "MysterySort" << (i + 1) << " is likely to be " << algorithmNames[minIndex]<<endl;
    }
}

