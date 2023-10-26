#include <stdio.h>
#include <stdlib.h> // Include the stdlib.h header for rand()

//function to merge to arrays in a sorted manner
void merge(int arr[], int left, int middle, int right) { 
    
    int n1 = middle - left + 1; //calculating the size of first subarray
    int n2 = right - middle;  //calculating the size of first subarray
    int L[n1], R[n2];  // Create temporary arrays to store subarray
    
    //copying data into these temp arrays L and R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    
    //merging the two subarrays into orignal array
    while (i < n1 && j < n2) {
        //this happens when element in L is smaller or equal than element in R
        if (L[i] <= R[j]) { //comparing elements of L and R
            arr[k] = L[i];  //adding element of L in arr
            i++; 
        }
        //this happens when element in R is smaller or than element in L
        else {
            arr[k] = R[j]; //adding element of R in arr
            j++;
        }
        k++; 
    }
    
    //copying the remaing elements
    while (i < n1) { //if elements are left in L
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) { //if elements are left in R
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) { //parameters -  array, left that is begining and right that is end
    if (left < right) { //this means array has elements
        int middle = left + (right - left) / 2; //find the middle index so that we can divide
        mergeSort(arr, left, middle); //calls the function again so that we can keep dividing 
        mergeSort(arr, middle + 1, right); 
        merge(arr, left, middle, right); //once it gets divided then merging and sorting starts
    }
}

//function to print the array 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int values[] = {3,5,6,9}; //values to work with in each experiment

    for (int i = 0; i <5; i++) { //loop works 4 times
        int n = values[i]; //retrieve value from values at the current index
        int arr[n]; //create an array of the size of the retrived value

        printf("Array = ");
        for (int j = 0; j < n; j++) { //loop to fill the new array arr
            arr[j] = rand()%10; //gets filled with random values
            printf(" %d, ",arr[j]); //printing array
        }

        printf("\n");
        
        printf("n = %d\n", n); //array length
        printf("Original array: "); //printing orignal array
        printArray(arr, n);

       mergeSort(arr, 0, n - 1); //calling function to sort elements using merge sort

        printf("Sorted array: "); //printing sorted array
        printArray(arr, n);
        }

    return 0;
}
