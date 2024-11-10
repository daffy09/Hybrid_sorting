#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of the smaller element

    // Traverse through all elements, compare each with pivot
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);  // Swap elements
        }
    }

    // Swap the pivot element with the element at i + 1
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return the partitioning index
}

// Function to perform QuickSort
void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pivot = partition(arr, low, high);

        // Recursively sort the subarrays
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

// Main function to test QuickSort
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    // Printing the original array
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Calling the quick_sort function
    quick_sort(arr, 0, arr.size() - 1);

    // Printing the sorted array
    cout << "Sorted Array (QuickSort): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
