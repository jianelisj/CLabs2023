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
    int sumint=0,sumchar=0,sumdouble = 0;

    for (int i = 0; i <SIZE;i++)
    {
        sumchar+=sizeof(*tbl_char);
        sumint+=sizeof(*tbl_int);
        sumdouble+=sizeof(*tbl_double);
    }
       
    printf("Size of char array is %d bytes\n",sumchar);

    printf("Size of int array is %d bytes\n",sumint);

    printf("Size of double array is %d bytes\n",sumdouble);
   
}