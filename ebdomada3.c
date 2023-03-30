#include <stdio.h>
#define SIZE 10

int main(void)
{
    char array_char[SIZE];
    int array_int[SIZE];
    double array_double[SIZE];

    printf("Size of array array_char in bytes: %zu\n", sizeof(array_char));

    printf("Size of array array_int in bytes: %zu\n", sizeof(array_int));

    printf("Size of array array_double in bytes: %zu\n", sizeof(array_double));

    return 0;
}