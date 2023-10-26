#include <stdio.h>
#include <stdlib.h> // Include the stdlib.h header for rand()
#include <time.h>

//function to swap values using temp
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//fucntion to get the index where partition occurs
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];//assigning the first element as pivot
    int i = low + 1;//second index as i
    int j = high;//last index as j

    while (1)//while true always
    {
        while (i <= j && arr[i] < pivot)//incrementing i until its less than largest index and less than pivot
        {
            i++;
        }
        while (i <= j && arr[j] > pivot)//decrementing j until its more than first index and greater than pivot
        {
            j--;
        }
        if (i <= j)//if i and j do not cross each other
        {
            swap(&arr[i], &arr[j]);//swap ith and jth element
        }
        else
        {
            break;//break the loop
        }
    }

    swap(&arr[low], &arr[j]);//swap pivot or first element and jth element
    return j;//return the index from where we will divide
}

//function to sort using quick sort
void quicksort(int arr[], int low, int high)
{
    if (low < high)//array has elements more than one
    {
        int x = partition(arr, low, high);//index where partition occurs, function thus called

        //recursively using the function on both the parts which are partitioned by x
        quicksort(arr, low, x - 1);
        quicksort(arr, x + 1, high);
    }
}


//function to print the array 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int values[] = {10,5}; //values to work with in each experiment

    for (int i = 0; i <5; i++) { //loop works 4 times
        int n = values[i]; //retrieve value from values at the current index
        int arr[n]; //create an array of the size of the retrived value


        for (int j = 0; j < n; j++) { //loop to fill the new array arr
             arr[j] = rand()%100+1; //gets filled with random values
        }

        printf("\n");
        
        printf("n = %d\n", n); //array length
        printf("Original array: "); //printing orignal array
        printArray(arr, n);

        quicksort(arr, 0, n - 1); //calling function to sort elements using quick sort

        printf("Sorted array: "); //printing sorted array
        printArray(arr, n);
        }

    return 0;
}


