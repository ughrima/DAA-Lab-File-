#include <stdio.h>
#include <string.h>

// Function to perform Brute Force String Matching
int search(char text[], char pattern[]) {
    int textlength = strlen(text); //length of text array say 10
    int patternlength = strlen(pattern); //length of pattern array say 5

    // Iterate through the text to find the pattern
    for (int i = 0; i <= textlength - patternlength; i++) { //say 0 to 10-5=5
        int j;

        // Check if the current substring matches the pattern
        for (j = 0; j < patternlength; j++) { //0 to 5 
            if (text[i + j] != pattern[j]) { 
                break; // If a mismatch is found, exit the inner loop
            }
        }

        // If the inner loop completed without a mismatch, we found the pattern
        if (j == patternlength) {
            return i; // Return the position of the first occurrence
        }
    }

    return -1; // Pattern not found in the text
}

int main() {
    char text[] = "This is a sample text"; //sample text
    char pattern[] = "sample"; //pattern to be found

    int result = search(text, pattern); //matching and searching for pattern using function

    if (result != -1) { //pattern found
        printf("Pattern found at position %d\n", result);
    } else { //pattern not found
        printf("Pattern not found in the text.\n");
    }

    return 0;
}
