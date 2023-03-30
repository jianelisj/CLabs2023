//Να γραφεί αναδρομική και επαναληπτική συνάρτηση υπολογισμού του n!=1*2*3*...(n-1)*n
//P(n)=1*2*3*...(n-1)*n=P(n-1)*n
//P(3)=P(2)*3=6
//P(2)=P(1)*2=2
//P(1)=P(0)*1=1
//P(0)=1

#include <stdio.h>

int par_epanal(int n);
int par_anadrom(int n);

int main()
{
    int n;

    printf("dose to n\n");
    scanf("%d", &n);

    printf("To %d! = %d anadromimka\n",n,par_anadrom(n));   
   
    printf("To %d! = %d epanaliptika\n",n,par_epanal(n));   

    return 0;
}

int par_anadrom(int n) //αναδρομικη συνάρτηση ειναι αυτή που καλεί τον εαυτό της
{
    if (n==0)
        return 1;
    else
        return par_anadrom(n-1)*n;
}

int par_epanal(int n)
{
    int p=1;

    for (int i=1;i<=n;i++)
        p*=i;

    return p;
}
