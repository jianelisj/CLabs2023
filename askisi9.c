//Υπολογισμος του x^n με αναδρομική και επαναληπτική συνάρτηση
//x*x*x....*x
//P(x,n)=P(x,n-1)*x ->Αναδρομικός Τύπος
//P(x,0)=1 ->Αρχική Συνθήκη (συνθήκη τερματισμού αναδρομής)
/*
P(2,3)=P(2,2)*2=8
P(2,2)=p(2,1)*2=4
P(2,1)=p(2,0)*2=2
P(2,0)=1
*/

#include <stdio.h>
float dynami_ana(int x, int n);


int main()
{
    int x,n;

    printf("dose basi kai ektheti\n");
    scanf("%d%d",&x,&n);

    printf("To %d ^ %d = %.3f\n",x,n,dynami_ana(x,n));    
    printf("To %d ^ %d = %.3f\n",x,n,dynami_epa(x,n));    

    return 0;
}

float dynami_ana(int x, int n)
{
    if (n==0) 
        return 1;
    else
        if (n>0)
            return dynami_ana(x,n-1)*x;
        else
            return 1/dynami_ana(x,-n);
}