#include <stdio.h>

/*Να εισάγονται στο main 2 int τιμές, να μεταβιβάζονται σε μια συνάρτηση που να τις εναλλάσει 
και να τις "επιστρέφει" στο main όπου και τυπώνονται*/ 
void swap(int *a,int *b);

int main()
{
    int x,y;

    printf("\nEnter 2 values\n");
    scanf("%d%d",&x,&y);

    printf("Before swap x=%d y=%d\n",x,y);

    swap(&x,&y);

    printf("After  swap x=%d y=%d\n",x,y);

    return 0;
}

void swap(int *a,int *b)
{
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;
}
