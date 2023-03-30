#include <stdio.h>
#define SIZE 10

void print_memory_size(char* tbl_char, int *tbl_int, double *tbl_double);

int main(void)
{
    char array_char[SIZE];
    int array_int[SIZE];
    double array_double[SIZE];

    print_memory_size(array_char, array_int, array_double);

    return 0;
}

void print_memory_size(char* tbl_char, int * tbl_int, double *tbl_double)
{
    int sum = 0;

    for (int i = 0; i <SIZE;i++)
        sum+=sizeof(*tbl_char);
       
    printf("Size of array array_char in bytes: %d\n", sum);
   
    sum=0;
    for (int i = 0;i <SIZE;i++)
          sum+=sizeof(*tbl_int);
    
    printf("Size of array array_int in bytes: %d\n", sum);
   
    sum=0;
    for (int i = 0; i <SIZE;i++)
          sum+=sizeof(*tbl_double);
    
    printf("Size of array array_double in bytes: %d\n", sum);
   
}