#ifndef TIME_COMPARISON_H
#define TIME_COMPARISON_H

#include <vector>
#include <string>
using namespace std;


double measureSortTime(void (*sortFunc)(vector<int>&), vector<int> arr, int repetitions);
void compareTimes(const vector<double>& knownTimes, const vector<double>& mysteryTimes);

#endif 
