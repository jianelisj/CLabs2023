#include <stdio.h>

//Να εισάγονται στο main 3 float τιμές, να μεταβιβάζονται σε μια συνάρτηση που να επιστρέφει το ΜΟ τους στο main και να τυπώνεται
//Οι 3 τιμές να μεταβιβάζονται σε μια συνάρτηση που να υπολογίζει και να τυπώνει τη max και τη min τιμή

void max_min(float a, float b, float c);
float mo(float a, float b, float c);

int main()
{
    float a,b,c;

    printf("Enter 3 values \n");
    scanf("%f%f%f",&a,&b,&c);

    printf("Average = %.2f\n",mo(a,b,c));

    max_min(a,b,c);

    return 0;
}

float mo(float a, float b, float c)
{
    return (a+b+c)/3;
}

void max_min(float a, float b, float c)
{
    float max,min;

    max=min=a;

    if (b>max)
        max=b;

    if (c>max)
        max=c;

    if (b<min)
        min=b;

    if (c<min)
        min=c;

    printf("Max = %.2f and Min=%.2f\n",max,min);
}