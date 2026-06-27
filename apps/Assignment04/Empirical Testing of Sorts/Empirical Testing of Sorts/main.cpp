//
// keyanna takita
//
// Add commit line to test each function
//
//

#include <iostream>
#include <vector>       // instead of arrays
#include <chrono>       // Module04partA
#include <random>       // instead of typeing the numbers over and over
using namespace std;

// Bubble Sort: O(n^2)
void bubbleSort(vector<int>& a)     // return to nothing
{                                   // sorting vector directly no copy
    for (int i = 0; i < a.size() - 1; i++)      // Each pass moves one largest num to the end
    {
        for (int j = 0; j < a.size() - i - 1; j++)      // move across the vector
        {
            if (a[j] > a[j + 1])    // compare
            {
                swap(a[j], a[j + 1]);       // swap to what was compared
            }
        }
    }
}

// Selection Sort: O(n^2)       Workign differently
void selectionSort(vector<int>& a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        swap(a[i], a[minIndex]);
    }
}

// Insertion Sort: O(n^2)
void insertionSort(vector<int>& a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Partition for Quicksort      module04PartC this has two functions
int partition(vector<int>& a, int low, int high)
{
    int pivot = a[high];
    int pIndex = low;

    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    swap(a[pIndex], a[high]);
    return pIndex;          // where is the pivot?
}

// Quicksort: O(n log n) average
void quickSort(vector<int>& a, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(a, low, high);
        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}
                // similair to Module04PartC where the algorithm calls itself

// Fill vector with random num
vector<int> makeRandomVector(int size)
{
    vector<int> numbers;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);

    for (int i = 0; i < size; i++)          //loop
    {
        numbers.push_back(dist(gen));
    }

    return numbers;
}

// ----- Main Function -----
int main()
{
    vector<unsigned long int> sizes = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 250000};

    cout << "Size,Bubble,Selection,Insertion,Quicksort" << endl;

    for (unsigned long int size : sizes)
    {
        vector<int> original = makeRandomVector(size);

            // make four copies, bubble, selection, insertion, and quicksort
                // all with would get the same og rand list but make sorting fair
        
        vector<int> bubble = original;
        vector<int> selection = original;
        vector<int> insertion = original;
        vector<int> quick = original;

        // time from Towers of Handi example
        auto start = chrono::steady_clock::now();       // start
        bubbleSort(bubble);                             // stop
        auto end = chrono::steady_clock::now();
        chrono::duration<double> bubbleTime = end - start;      // (-) to gett how long it took
    
        start = chrono::steady_clock::now();
        selectionSort(selection);
        end = chrono::steady_clock::now();
        chrono::duration<double> selectionTime = end - start;

        start = chrono::steady_clock::now();
        insertionSort(insertion);
        end = chrono::steady_clock::now();
        chrono::duration<double> insertionTime = end - start;

        start = chrono::steady_clock::now();
        quickSort(quick, 0, quick.size() - 1);
        end = chrono::steady_clock::now();
        chrono::duration<double> quickTime = end - start;

        
        // Display
        
        cout << size << ","
             << bubbleTime.count() << ","
             << selectionTime.count() << ","
             << insertionTime.count() << ","
             << quickTime.count()
             << endl;
    }

    return 0;
}
