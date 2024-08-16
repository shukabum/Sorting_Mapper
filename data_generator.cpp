#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateTestData(const string& filename, int numElements, int maxValue) {
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error creating file: " << filename << endl;
        return;
    }

    srand(time(0));  // Seed the random number generator

    for (int i = 0; i < numElements; ++i) {
        int randomValue = rand() % maxValue;
        outfile << randomValue << " ";
    }

    outfile.close();
    cout << "Test data generated and saved to " << filename << endl;
}

int main() {
    string dataFile = "test_data.txt";
    int numElements = 10;  // Number of elements in the test data
    int maxValue = 1000;    // Maximum value of the elements

    generateTestData(dataFile, numElements, maxValue);

    return 0;
}
