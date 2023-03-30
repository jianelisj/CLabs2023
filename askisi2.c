/*Λειτουργίες Πινάκων με αναπαράσταση τους ως δείκτες*/
#include <stdio.h>

#define N 5

void read_array(int *y);
void print_array(int x[]);
float mesos_oros(int *y);
void  artioi_perittoi(int *y,int *art,int *per);

int main() 
{
    int x[N]; /*δήλωση πίνακα*/
    int z,a,p;

    read_array(x); /*δεν μεταβιβάζεται ο πίνακας αλλά μόνο η & του αρχικού του στοιχείου διότι x=&x[0];*/

    printf("Pinakas\n");
    
    print_array(x); /*δεν μεταβιβάζεται ο πίνακας αλλά μόνο η & του αρχικού του στοιχείου διότι x=&x[0];*/

    printf("\nMesos Oros = %.2f\n",mesos_oros(x)); /*Καλούμε τη συνάρτηση mesos_oros(x) που επιστρέφει αποτέλεσμα κατευθείαν σε printf*/

    printf("Dose stoixeio anazitisis\n");
    scanf("%d",&z);


    printf("To stoixeio %d emfanizetai %d fores\n",z,anazitisi(x,z));

    /*Να καλείται συνάρτηση που να λαμβάνει τον πίνακα και να τυπώνει το πλήθος άρτιων-περιττών*/
    artioi_perittoi(x,&a,&p); /*Μετβιβάζουμε τη διεύθυνση της μεταβλητής a του main για να καταχωρηθεί σε αυτή το 1ο αποτέλεσμα δηλ 
    το πλήθος άρτιων και τη διεύθυνση της μεταβλητής p του main για να καταχωρηθεί σε αυτή το 2ο αποτέλεσμα δηλ το πλήθος περιττών*/

    printf("Plithos Artion = %d kai Plithos Peritton = %d\n",a,p);

    return 0;
}

void read_array(int *y) /*To *y είναι ένας τοπικός δείκτης που λαμβάνει τη & του αρχικού του στοιχείου του πίνακα x από το main και δείχνει σε αυτό*/
{
    int i;

    for (i=0;i<N;i++)
    {
        printf("Dose timi\n");
        scanf("%d",y+i); /*Η τιμή από το πληγκτρολόγιο μπαίνει στη διεύθυνση του στοιχείου που δείχνει ο δείκτης y+i*/
    }
}

void print_array(int *y)
{
    int i;
    for (i=0;i<N;i++)
        printf("%d\t",*(y+i));/*τυπώνεται το περιεχόμενο του στοιχείου που δείχνει ο δείκτης y+i*/
}

float mesos_oros(int *y)
{
    int sum=0,i;

     for (i=0;i<N;i++)
        sum+=*(y+i); /*To *(y+i) ειναι το περιεχόμενο του x[i]. Με το +i ο δείκτης y μετακινείται κάθε φορά στο επόμενο στοιχείο του πίνακα x*/

    return (float)sum/N;
}

int anazitisi(int *y,int z)
{
    int c=0,i;

    for (i=0;i<N;i++)
        if (*(y+i)==z)
            c++;

    return c;
}

void  artioi_perittoi(int *y,int *art,int *per) /*art=&a, per=&p*/
{
    int i;

    *art=*per=0; //Το *art ειναι το περιεχόμενο του a και το *per ειναι το περιεχόμενο του p

     for (i=0;i<N;i++)
        if (*(y+i)%2==0)
            (*art)++; /*στο περιεχόμενο της μεταβλητής που δείχνει ο δείκτης art δηλ. στο a του main προσθέτουμε 1 άρα αυξάνουμε το 
            a του main κατά 1**/
        else
            (*per)++;/*στο περιεχόμενο της μεταβλητής που δείχνει ο δείκτης art δηλ. στο p του main προσθέτουμε 1 άρα αυξάνουμε το 
            p του main κατά 1**/
}