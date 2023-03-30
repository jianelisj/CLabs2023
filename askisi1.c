/*Λειτουργίες Πινάκων*/
#include <stdio.h>

#define N 5

/*ΔΗΛΩΣΗ ΠΡΩΤΟΤΥΠΩΝ-ΕΠΙΚΕΦΑΛΙΔΩΝ ΣΥΝΑΡΤΗΣΕΩΝ*/
void read_array(int *y);
void print_array(int x[]);
float mesos_oros(int x[N]);
int anazitisi(int x[N],int z);
void artioi_perittoi(int x[],int *art,int *per); /*art=&a, per=&p*/

int main() 
{
    int x[N]; /*δήλωση πίνακα*/
    float mo;
    int z,times,a,p;

    read_array(x); /*δεν μεταβιβάζεται ο πίνακας αλλά μόνο η & του αρχικού του στοιχείου διότι x=&x[0];*/

    printf("Pinakas\n");

    print_array(x); /*δεν μεταβιβάζεται ο πίνακας αλλά μόνο η & του αρχικού του στοιχείου διότι x=&x[0];*/

    mo=mesos_oros(x); /*Η συνάρτηση mesos_oros(x); καλείται με καταχώριση διότι επιστρέφει αποτέλεσμα*/

    printf("\nMO= %.2f\n",mo); /*Τυπώνεται η μεταβλητή mo με ακρίβεια 2 δεκαδικών*/

    printf("Dose stoixeio anazitisis\n");
    scanf("%d",&z);

    times=anazitisi(x,z); /*Η συνάρτηση anazitisi(x,z); καλείται με καταχώριση διότι επιστρέφει αποτέλεσμα*/

    printf("To stoixeio %d emfanizetai %d fores\n",z,times);

     /*Να καλείται συνάρτηση που να λαμβάνει τον πίνακα και να τυπώνει το πλήθος άρτιων-περιττών*/

    artioi_perittoi(x,&a,&p); /*Μετβιβάζουμε τη διεύθυνση της μεταβλητής a του main για να καταχωρηθεί σε αυτή το 1ο αποτέλεσμα δηλ 
    το πλήθος άρτιων και τη διεύθυνση της μεταβλητής p του main για να καταχωρηθεί σε αυτή το 2ο αποτέλεσμα δηλ το πλήθος περιττών*/

    printf("Plithos Artion = %d kai Plithos Peritton = %d\n",a,p);

    return 0;
}

void read_array(int x[]) /*void read_array(int x[Ν])*/
{
    int i;

    for (i=0;i<N;i++)
    {
        printf("Dose timi\n");
        scanf("%d",&x[i]); /*Η τιμή μπαίνει στη θέση που δείχνει του στοιχείου i*/
    }
}

void print_array(int x[])
{
    int i;
    for (i=0;i<N;i++)
        printf("%d\t",x[i]);
}

float mesos_oros(int x[N])
{
    int i,sum=0;

    for (i=0;i<N;i++)
        sum+=x[i];

    return (float)sum/N;
}

int anazitisi(int x[N],int z)
{
    int c=0,i;

    for (i=0;i<N;i++)
        if (x[i]==z)
            c++;

    return c;
}

void  artioi_perittoi(int x[],int *art,int *per) /*art=&a, per=&p*/
{
    int i;

    *art=*per=0; //Το *art ειναι το περιεχόμενο του a και το *per ειναι το περιεχόμενο του p

     for (i=0;i<N;i++)
        if (x[i]%2==0)
            (*art)++; /*στο περιεχόμενο της μεταβλητής που δείχνει ο δείκτης art δηλ. στο a του main προσθέτουμε 1 άρα αυξάνουμε το 
            a του main κατά 1**/
        else
            (*per)++;/*στο περιεχόμενο της μεταβλητής που δείχνει ο δείκτης art δηλ. στο p του main προσθέτουμε 1 άρα αυξάνουμε το 
            p του main κατά 1**/
}