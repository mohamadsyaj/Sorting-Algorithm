#include <iostream>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <ctime> 
using namespace std;

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high - 1]);
    return arr[high - 1];
}

int partition(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = low;
    int j = high - 1;

    while (true) {
        while (arr[++i] < pivot) {}
        while (arr[--j] > pivot) {}
        if (i < j) swap(arr[i], arr[j]);
        else break;
    }
    swap(arr[i], arr[high - 1]);
    return i;
}

void QuickSort(int arr[], int low, int high) {
    if (low + 10 <= high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
    else {
        for (int i = low + 1; i <= high; ++i) {
            int tmp = arr[i];
            int j;
            for (j = i; j > low && arr[j - 1] > tmp; --j)
                arr[j] = arr[j - 1];
            arr[j] = tmp;
        }
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {

    srand(time(0));

    int const size = 5000;
    int randomArray[size];
    int sortedArray[size];
    int reversedArray[size];
    for (int i = 0; i < size; i++) {
        randomArray[i] = rand() % 10000;
    }
    for (int i = 0; i < size; i++) {
        sortedArray[i] = i;
    }
    for (int i = size - 1; i >= 0; i--) {
        reversedArray[i] = i;
    }
    auto start = chrono::high_resolution_clock::now();
    //QuickSort(sortedArray, 0, size - 1);
    //MergeSort(sortedArray, 0, size - 1);
    heapSort(sortedArray, size);
    auto end = chrono::high_resolution_clock::now();
    cout << "Sorted Array time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds\n";

    start = chrono::high_resolution_clock::now();
    //QuickSort(randomArray, 0, size - 1);
    //MergeSort(randomArray, 0, size - 1);
    heapSort(randomArray, size);
    end = chrono::high_resolution_clock::now();
    cout << "Random Array time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds\n";

   

    start = chrono::high_resolution_clock::now();
    //QuickSort(reversedArray, 0, size - 1);
    //MergeSort(reversedArray, 0, size - 1);
    heapSort(reversedArray, size);
    end = chrono::high_resolution_clock::now();
    cout << "Reversed Array time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds\n";

    return 0;
}
