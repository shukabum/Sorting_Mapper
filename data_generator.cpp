#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include <random>

using namespace std;

void generateData(ofstream& outfile, int size) {
    vector<int> data(size);
    
    // Generate a base dataset
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 1000;  
    }

    // Generate 10 permutations
    random_device rd;
    mt19937 g(rd()); 

    for (int i = 0; i < 10; ++i) {
        vector<int> temp = data;
        shuffle(temp.begin(), temp.end(), g); 
        outfile << "Permutation " << (i + 1) << ":\n";
        for (int num : temp) {
            outfile << num << " "; 
        }
        outfile << "\n"; 
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  

    ofstream outfile("test_data.txt");
    if (!outfile) {
        cerr << "Error opening file: test_data.txt" << endl;
        return 1;
    }

    int size = 1000; // Size of each dataset configuration

    // Generate the dataset and write to the file
    generateData(outfile, size);
    outfile.close();
    cout << "Data generation complete. Check test_data.txt for the data." << endl;

    return 0;
}
