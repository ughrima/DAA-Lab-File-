#include <stdio.h>

// Linear Search
int f1=0; //using f1 as flag to count the number of times the loop worked
int linearsearch(int arr[], int n, int key) { //parameters - array, array length and key
    for (int i = 0; i < n; i++) { //loop iterating from 0 to n-1
        f1++; //flag f1 incrementing 
        if (arr[i] == key) { //checking if key is same as array element 
            return i; //if yes then index returned else -1
        }
    }
    return -1; 
}

// Binary Search
int f2=0; //using f2 as flag to count the number of times the loop worked
int binarysearch(int arr[],int beg,int end,int item){  //parameters - array, array start point and end point and key
    while(beg<=end){ //this means that array has some length
        f2++; //incrementing flag f2 
        int mid=(beg+end)/2; //finding the medium index of the array
        if (item==arr[mid]){ //if key is the middle most element only 
            return mid;
        }
        if (item<arr[mid]){ //if key is smaller than the middle most element
            end=mid-1; //makes end as middle

        }
        else{ //if key is bigger than the middle most element
            beg=mid+1; //makes middle as begining
    }
}
return -1;
}

int main() {
    int values[] = {10,6,4,9}; //values to work with in each experiment

    for (int i = 0; i <5; i++) { //loop works 4 times
        int n = values[i]; //retrieve value from values at the current index
        int arr[n]; //create an array of the size of the retrived value
        int key = rand() % n; //generate a random key using modulo. Ensures that random is between 0 to n-1

        for (int j = 0; j < n; j++) { //loop to fill the new array arr
            arr[j] = j; //gets filled with numbers 0,1,2,3...
        }

        int linearSearchResult = linearsearch(arr, n, key); //calling function to search element linearly
        int binarySearchResult = binarysearch(arr,0, n, key); //calling function to search element using binear search

        //printing result
        printf("n = %d:\n", n);
        printf("key: %d\n", key);
        printf("Linear Search Result: %d\n", linearSearchResult);
        printf("No. of times the linear loop worked = %d\n",f1);
        printf("Binary Search Result: %d\n", binarySearchResult);
        printf("No. of times the binary loop worked = %d\n",f2);
    }

    return 0;
}
