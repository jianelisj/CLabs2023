#include <stdio.h>

int main(void)
 {
    int x[10], y[15], z[20];
    int* ptr[] = { x, y, z };

    printf("the address of the first element of x is: %p\n", &x[0]); // method 1
    printf("the address of the first element of x is: %p\n", x);    // method 2
    printf("the address of the first element of x is: %p\n", ptr[0]);// method 3
    printf("the address of the first element of x is: %p\n", &*x);  // method 4
    printf("the address of the first element of x is: %p\n", &x);   // method 5
    printf("the address of the first element of x is: %p\n", x + 0);// method 6

    return 0;
}