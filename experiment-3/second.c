#include <stdio.h>
#include <stdlib.h> // Include the stdlib.h header for rand()
#include <time.h>

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        // Select the key to be inserted at the right position.
        int key = arr[i];
        // Initialize an index for elements to the left of the key.
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than the key
        // one position ahead of their current position.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift the current element to the right.
            j = j - 1; // Move to the previous element.
        }
        // Place the key in its correct position within the sorted segment.
        arr[j + 1] = key;
    }
}


//function to print the array 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int values[] = {10,5,6,9}; //values to work with in each experiment

    for (int i = 0; i <5; i++) { //loop works 4 times
        int n = values[i]; //retrieve value from values at the current index
        int arr[n]; //create an array of the size of the retrived value

        for (int j = 0; j < n; j++) { //loop to fill the new array arr
            arr[j] = rand()%10; //gets filled with random values
        }

        printf("\n");
        
        printf("n = %d\n", n); //array length
        printf("Original array: "); //printing orignal array
        printArray(arr, n);

        insertionsort(arr, n ); //calling function to sort elements using insertion sort

        printf("Sorted array: "); //printing sorted array
        printArray(arr, n);
        }

    return 0;
}


