//Code to check execution time of sorting algorithms using clock
//May not show values more than 3 decimals after zero, for higher precision, use chrono

#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>
#define PRECISION 5                     //How many decimals
#define SIZE 10000                   //Size of array

using namespace std;

int is_sorted(int input[], int size) {
   while ( --size >= 1 ) {
      if ( input[size] < input[size-1] ) {
         return 0;
      }
   }
   return 1;
}

void shuffle(int input[], int size) {
   int temp, r;
   for(int i = 0; i < size; i++) {
      temp = input[i];
      r = rand() % size;
      input[i] = input[r];
      input[r] = temp;
   }
}

void bogosort(int input[], int size) {
   while (!is_sorted(input, size)) {
      shuffle(input, size);
   }
}

//execution time of bogosort
void bogoSortExecutionTime(int input[], int size)
{
    clock_t start = clock();
    bogosort(input, size);
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Bogo Sort Execution Time: " << fixed << setprecision(PRECISION) << time_taken << " seconds" << endl;
}

//selection sort
void selectionSort(int input[], int size)
{
    int i, j, min_idx, temp;
    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (input[j] < input[min_idx])
            {
                min_idx = j;
            }
        }
        temp = input[i];
        input[i] = input[min_idx];
        input[min_idx] = temp;
    }
}

//execution time of selection sort
void selectionSortExecutionTime(int input[], int size)
{
    clock_t start = clock();
    selectionSort(input, size);
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Selection Sort Execution Time: " << fixed << setprecision(PRECISION) << time_taken << " seconds" << endl;
}

//insertion sort
void insertionSort(int input[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = input[i];
        j = i - 1;
        while (j >= 0 && input[j] > key)
        {
            input[j + 1] = input[j];
            j = j - 1;
        }
        input[j + 1] = key;
    }
}

//execution time of insertion sort
void insertionSortExecutionTime(int input[], int size)
{
    clock_t start = clock();
    insertionSort(input, size);
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Insertion Sort Execution Time: " << fixed << setprecision(PRECISION) << time_taken << " seconds" << endl;
}

//bubble sort
void bubbleSort(int input[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (input[j] > input[j + 1])
            {
                temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

//execution time of bubble sort
void bubbleSortExecutionTime(int input[], int size)
{
    clock_t start = clock();
    bubbleSort(input, size);
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Bubble Sort Execution Time: " << fixed << setprecision(PRECISION) << time_taken << " seconds" << endl;
}


//generate random integer array
void generateRandomArray(int input[], int size)
{
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {
        input[i] = rand() % 100;
    }
}

//generate reverse sorted array
void generateReverseSortedArray(int input[], int size)
{
    for(int i = 0; i < size; i++)
    {
        input[i] = size - i;
    }
}

//generate sorted array
void generateSortedArray(int input[], int size)
{
    for(int i = 0; i < size; i++)
    {
        input[i] = i;
    }
}

//prints array
void printArray(int input[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}

int main()
{
    int numbers[SIZE];

    cout << "Size: " << SIZE << endl;

    cout << "\nBest Case: " << endl;
    generateSortedArray(numbers, SIZE);
    selectionSortExecutionTime(numbers, SIZE);

    generateSortedArray(numbers, SIZE);
    insertionSortExecutionTime(numbers, SIZE);

    generateSortedArray(numbers, SIZE);
    bubbleSortExecutionTime(numbers, SIZE);

    cout << "\nAverage case: " << endl;
    generateRandomArray(numbers, SIZE);
    selectionSortExecutionTime(numbers, SIZE);

    generateRandomArray(numbers, SIZE);
    insertionSortExecutionTime(numbers, SIZE);

    generateRandomArray(numbers, SIZE);
    bubbleSortExecutionTime(numbers, SIZE);

    cout << "\nWorst case: " << endl;
    generateReverseSortedArray(numbers, SIZE);
    selectionSortExecutionTime(numbers, SIZE);

    generateReverseSortedArray(numbers, SIZE);
    insertionSortExecutionTime(numbers, SIZE);

    generateReverseSortedArray(numbers, SIZE);
    bubbleSortExecutionTime(numbers, SIZE);

    // generateRandomArray(numbers, SIZE);
    // bogoSortExecutionTime(numbers, SIZE);
    
    return 0;
}

//Giga Hidjrika Aura Adkhy
//02/03/2022
