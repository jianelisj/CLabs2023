#include <stdio.h>

int main(void)
{
    char a='A';
    char msg[]="A";
    char * months[]={"Jan","Feb","Mar"};

    printf("the value of a is: %c\n",a);
    printf("the address of a is: %p\n",&a);
    printf("the size of a is : %d\n\n\n",sizeof(char));
    printf("the value of msg is: %s\n", msg);
    printf("the first character of msg is: %c\n",msg[0]);
    printf("the address of the first character of msg : %p\n",msg);
    printf("the size of msg is: %d\n\n\n",sizeof(msg));
    printf("the value of months is: %p \n",months);
    printf("Jan starts at address : %p\n",months[0]);
    printf("Feb starts st address : %p\n", months[1]);
    printf("Mar starts st address : %p\n", months[2]);
    printf("the second character of the 2nd string is %c:\n",months[1][1]);
    printf("the second character of the 2nd string(with pointer arithmetic)is %c:\n",*(months[1]+1));
    printf("the size of months is: %d \n ",sizeof(months)/sizeof(months[0]));
    
    return 0;
}