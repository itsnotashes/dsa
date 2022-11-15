// Given an array of integers, create a heap from it and sort using heapsort 

#include <stdio.h>
#include <stdlib.h>

void heapify(int *a, int n, int currentIndex) {
    int largest = currentIndex;
    int left = 2 * currentIndex + 1;
    int right = 2 * currentIndex + 2;
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != currentIndex) {
        int temp = a[currentIndex];
        a[currentIndex] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void makeHeap(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void heapSort(int *a, int n) {
    makeHeap(a, n);
    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}



int main() {
    int arr[] = {5, 4, 8, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Create a heap from the array
    makeHeap(arr, n);
    // print the array before sorting
    print(arr, n);
    heapSort(arr, n);
    print(arr, n);
    return 0;
}