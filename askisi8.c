#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int athroisma_pinaka_epanaliptika(int x[],int n);
int athroisma_pinaka_anadromika(int x[],int n);
int ginomeno_pinaka_epanaliptika(int x[],int n);
int ginomeno_pinaka_anadromika(int x[],int n);
int main()
{
    int *x,n;

    srand(time(NULL));//ΑΡΧΙΚΟΠΟΙΗΣ ΓΕΝΝΗΤΡΙΑΣ ΤΥΧΑΙΩΝ ΑΡΙΘΜΩΝ ΜΕ ΤΗΝ ΤΡΕΧΟΥΣΑ ΧΡΟΝΙΚΗ ΣΤΙΓΜΗ ΤΟΥ Η/Υ ΩΣΤΕ ΣΕ ΚΑΘΕ ΕΚΤΈΛΕΣΗ ΝΑ ΠΑΡΑΟΓΝΤΑΙ ΔΙΑΦΟΡΕΤΙΚΕΣ
    //ΤΥΧΑΙΕΣ ΤΙΜΕΣ

    printf("Dose megethos Pinaka\n");
    scanf("%d", &n);

    x=(int*)malloc(n*sizeof(int)); //H συνάρτηση mallocator δεσμεύει συνεχόμενη μνήμη για ένα πίνακα όχι εκ των προτέρων αλλά δυναμικά δηλ. 
    //κατά τη διάρκεια εκτέλεσης
    //Δεσμεύει n θέσεις μνήμης. Για κάθε θέση δεσμεύει τόσα bytes όσα επιτρέφει ο τύπος sizeof(int) και επιστρέφει τη διεύθυνση της 1η θέσης 
    //από αυτές που δέσμευσε στο δείκτη x. Το (int *) δηλώνει ότι το περιεχόμενο της 1η θέσης περιέχει int. Όταν γίνει η δέσμευση μνήμης το x
    //είναι κανονικός πίνακας

    for (int i = 0; i <n;   i++) 
        x[i] =rand()%10+1;

    for (int i = 0; i <n;   i++) 
        printf("%d ", x[i]);    

    printf("\nTo athroisma tou pinaka anadromika einai %d\n",athroisma_pinaka_anadromika(x,n));
    printf("\nTo athroisma tou pinaka epanaliptika einai %d\n",athroisma_pinaka_epanaliptika(x,n));

    printf("\nTo ginomeno tou pinaka anadromika einai %d\n",ginomeno_pinaka_anadromika(x,n));
    printf("\nTo ginomeno tou pinaka epanaliptika einai %d\n",ginomeno_pinaka_epanaliptika(x,n));

    return 0;
}

int athroisma_pinaka_anadromika(int x[],int n)
{
    //x[0]+x[1]+x[2]+...x[n-1]=(x[0]+x[1]+x[2]+...x[n-2])+x[n-1]

    if (n==1)
        return x[0];
    else
        return athroisma_pinaka_anadromika(x,n-1)+x[n-1];
}

int athroisma_pinaka_epanaliptika(int x[],int n)
{
    int sum=0;

    for (int i=0;i<n;i++)
        sum+=x[i];

    return sum;
}


int ginomeno_pinaka_anadromika(int x[],int n)
{
    //x[0]*x[1]*x[2]*...x[n-1]=(x[0]*x[1]*x[2]*...*x[n-2])*x[n-1]

    if (n==1)
        return x[0];
    else
        return ginomeno_pinaka_anadromika(x,n-1)*x[n-1];
}

int ginomeno_pinaka_epanaliptika(int x[],int n)
{
    int prod=1;

    for (int i=0;i<n;i++)
        prod*=x[i];

    return prod;
}
