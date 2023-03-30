#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1048576 // Maximum input size 1MB

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to reverse words and letters of a string
void inverse(char *s, char *invs) {
    int len = strlen(s);
    int i = 0;
    int j = len - 1;

    while (i < len) {
        // Skip non-alphanumeric characters
        while (i < len && !isalnum(s[i])) {
            invs[i] = s[i];
            i++;
        }

        if (i >= len) break;

        // Save start position of current word
        int start = i;

        // Find end of current word
        while (i < len && isalnum(s[i])) {
            i++;
        }

        // Save end position of current word
        int end = i - 1;

        // Reverse the current word
        for (int k = end; k >= start; k--) {
            invs[j--] = s[k];
        }
    }
    invs[len] = '\0';
}

// Function to count the number of words in a string
int count_words(char *s) {
    int count = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        // Skip non-alphanumeric characters
        while (i < len && !isalnum(s[i])) {
            i++;
        }

        if (i >= len) break;

        // Increment word count when a new word is encountered
        count++;

        // Skip the rest of the current word
        while (i < len && isalnum(s[i])) {
            i++;
        }
    }

    return count;
}

int main() {
    // Allocate memory for input and output strings
    char* text = (char*) malloc(MAX_INPUT_SIZE * sizeof(char));
    char* invs = (char*) malloc(MAX_INPUT_SIZE * sizeof(char));

    // Get input from user
    printf("Enter a string of maximum length 1MB: ");
    fgets(text, MAX_INPUT_SIZE, stdin);

    // Remove newline character from input string
    text[strcspn(text, "\n")] = '\0';

    // Reverse words and letters of input string
    inverse(text, invs);

    // Print reversed string
    printf("Reversed string: %s\n", invs);

    // Count number of words in input string
    int word_count = count_words(text);

    // Print word count
    printf("Number of words: %d\n", word_count);

    // Free memory allocated for input and output strings
    free(text);
    free(invs);

    return 0;
}
