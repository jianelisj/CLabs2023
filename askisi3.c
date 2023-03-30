/*Λειτουργίες Δισδτάστατων Πινάκων με αναπαράσταση τους ως δείκτες*/
#include <stdio.h>

#define N 3
#define M 3

void read_array(int x[N][M]);
void print_array(int x[N][M]);
float mesos_oros(int x[N][M]);
void artioi_perittoi(int x[N][M],int *art,int *per);

int main() 
{
    int x[N][M]; /*δήλωση πίνακα με Ν γραμμές και Μ στήλες*/
    int z,a,p;

    read_array(x); /*δεν μεταβιβάζεται ο πίνακας αλλά μόνο η & του αρχικού του στοιχείου διότι x=&x[0];*/

    printf("Pinakas\n");
    
    print_array(x); /*δεν μεταβιβάζεται ο πίνακας αλλά μόνο η & του αρχικού του στοιχείου διότι x=&x[0];*/

    printf("\nMesos Oros = %.2f\n",mesos_oros(x)); /*Καλούμε τη συνάρτηση mesos_oros(x) που επιστρέφει αποτέλεσμα κατευθείαν σε printf*/

    printf("Dose stoixeio anazitisis\n");
    scanf("%d",&z);

    printf("To stoixeio %d emfanizetai %d fores\n",z,anazitisi(x,z));

    artioi_perittoi(x,&a,&p);
    printf("Plithos Artion = %d kai Plithos Peritton = %d\n",a,p);

    return 0;
}

void read_array(int x[][M]) 
{
    int i,j;

    for (i=0;i<N;i++)
        for (j=0;j<M;j++)
        {
            printf("Dose timi\n");
            scanf("%d",*(x+i)+j); /*scanf("%d",&x[i][j])*/
    }
}

void print_array(int x[][M]) 
{
     int i,j;

    for (i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
             printf("%d\t",*(*(x+i)+j));/*printf("%d\t",x[i][j]);*/

        printf("\n");
    }
}

float mesos_oros(int x[N][M]) 
{
    int sum=0,i,j;

    for (i=0;i<N;i++)
        for (j=0;j<M;j++)
             sum+=*(*(x+i)+j); /*sum+=x[i][j];*/

    return (float)sum/(N*M);
}

int anazitisi(int x[N][M],int z)
{
    int c=0,i,j;

    for (i=0;i<N;i++)
        for (j=0;j<M;j++)
            if (*(*(x+i)+j)==z) /*if (x[i][j]==z)*/
                c++;

    return c;
}

void  artioi_perittoi(int x[N][M],int *art,int *per) /*art=&a, per=&p*/
{
    int i,j;

    *art=*per=0; //Το *art ειναι το περιεχόμενο του a και το *per ειναι το περιεχόμενο του p

     for (i=0;i<N;i++)
        for (j=0;j<M;j++)
            if (*(*(x+i)+j)%2==0) /*if (x[i][j]%2==0)*/
                (*art)++; /*στο περιεχόμενο της μεταβλητής που δείχνει ο δείκτης art δηλ. στο a του main προσθέτουμε 1 άρα αυξάνουμε το 
                a του main κατά 1**/
            else
                (*per)++;/*στο περιεχόμενο της μεταβλητής που δείχνει ο δείκτης art δηλ. στο p του main προσθέτουμε 1 άρα αυξάνουμε το 
                p του main κατά 1**/
}