#include <iostream>
#include <vector>
using namespace std;

// MergeSort Implementation
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// QuickSort Implementation
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

// Hybrid Sort Algorithm
void hybrid_sort(vector<int>& arr, int threshold = 20) {
    if (arr.size() <= threshold) {
        merge_sort(arr, 0, arr.size() - 1);  // Use MergeSort for smaller arrays
    } else {
        quick_sort(arr, 0, arr.size() - 1);  // Use QuickSort for larger arrays
    }
}

// Main Function
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7, 45, 22, 34, 16, 3};

    // Printing the original array
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Calling the hybrid_sort function
    hybrid_sort(arr, 10);  // Threshold for switching between QuickSort and MergeSort

    // Printing the sorted array
    cout << "Sorted Array (Hybrid Sort): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
