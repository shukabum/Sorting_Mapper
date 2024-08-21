# Sorting_Project

## Overview

The `Sorting_Project` is a C++ project designed to identify sorting algorithms by comparing their execution times. The project includes implementations of various sorting algorithms and mystery sorting functions. It measures the execution time of each sorting function and maps them to known sorting algorithms based on timing characteristics.

## Project Structure

- **`main.cpp`**: The main entry point for the project that loads test data, measures the time for each sorting algorithm, and compares the times to identify the mystery sorting functions.
- **`sorting_algorithms.cpp`**: Contains implementations of known sorting algorithms (Bubble Sort, Insertion Sort, Selection Sort, Merge Sort, Quick Sort).
- **`time_comparison.cpp`**: Contains functions to measure sorting times and compare the execution times of known and mystery sorting algorithms.
- **`data_generator.cpp`**: Generates test data for sorting algorithms and saves it to a text file.
- **`test_data.txt`**: Example data file containing integer numbers to be sorted. This file is generated by the `data_generator.cpp` program.

## Setup

1. **Clone the Repository**

   ````bash
   git clone https://github.com/yourusername/Sorting_Project.git

   cd Sorting_Project

2. **Create Test Data**
Before running the project, generate the test data file by running the data_generator program. This will create the test_data.txt file needed for sorting.
    ```bash
    g++ -o data_generator data_generator.cpp
    
    ./data_generator
3. **Build and Run the Project**
Compile the Project
Use mingw32-make to compile the project. Make sure you're in the project directory where the Makefile is located.
   ```bash
    mingw32-make
   
    ./Sorting_Project
   
 ## Important
         - Each time if any changes are made in the data_generation code then you have to run both of the above commands again.
         - Each time if any changes are made in the code then you have to run both of the above commands again.

## How to change the number of iterations:

You can change the number of iterations in the main.cpp file. The variable "repetitions" is used to control the number of times each sorting algorithm is executed.

## How to change the size of the test data:

You can change the size of the test data in the data_generator.cpp file. The variable "size" is used to control the size of the test data.

## KEYPOINTS

- If the dataset is small (100-500) we need to have more than 100000 iterations
- If the dataset is large (1000-5000) we can run the it under 10000 iterations.
