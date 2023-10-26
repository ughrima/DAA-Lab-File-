#include <stdio.h>
#include <stdbool.h>

//function to sort the array
void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;

//outer loop 
    for (i = 0; i < n - 1; i++) {
        swapped = false;

        //inner loop to compare and swap adjacent elements
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        //If no two elements were swapped in the inner loop, the array is already sorted
        if (swapped == false)
            break;
    }
}

// Function to sort the array using Selection Sort
void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minindex = i; // Assume the current index is the minimum

        // Find the index of the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }

        // Swap the current element with the minimum element found
        int temp = arr[i];   // Store the current element in a temporary variable
        arr[i] = arr[minindex];  // Replace the current element with the minimum element
        arr[minindex] = temp;  // Place the current element in the position of the minimum element

        // After this iteration, the minimum element in the unsorted part is in its correct position
    }
}

//print function in order to print every element of a sorted array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main() {
    int arr[] = { 4,8,5,2,3,4,7,9,0,7,4,2,1,23,4,5,67,68 }; //array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]); //size of array
    printf("UnSorted array: \n");  // Print the unsorted array
    printArray(arr,n);

    printf("\n");

    int arr2[n]; // Create a new array arr2 to copy the original array
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }


    bubbleSort(arr2, n); // Sort the array using Bubble Sort function
    selectionsort(arr, n); // Sort the array using Selection Sort function

    printf("Sorted array through bubble sort : \n");
    printArray(arr2,n); //printing sorted array

    printf("\n");

    printf("Sorted array through selection sort : \n");
    printArray(arr,n); //printing sorted array


    return 0;
}
