#include <stdio.h>
#define SIZE 10

int main(void)
{
    char array_char[SIZE];
    int array_int[SIZE];
    double array_double[SIZE];

    printf("Size of char array is %d bytes\n", sizeof(array_char));

    printf("Size of int array is %d bytes\n", sizeof(array_int));

    printf("Size of double array is %d bytes\n", sizeof(array_double));

    return 0;
}