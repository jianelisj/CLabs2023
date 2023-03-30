#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CHARS 500000

void initialize(char src[]);
void copy_with_loop(char dst[],char src[]);
void copy_with_memcpy(char dst[],char src[]);

int main(void) 
{
    char src[NUM_CHARS];
    char dst[NUM_CHARS];
    clock_t start_time, end_time;
    double elapsed_time;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // initialize source string with random characters
    initialize(src);

    start_time = clock(); // record start time
    
    //copy source string to destination string using loop & print the time needed
    copy_with_loop(dst,src);

    end_time = clock(); // record end time
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);


    start_time = clock(); // record start time

    //copy source string to destination string using memcpy & print the time needed
    copy_with_memcpy(dst,src);

    end_time = clock(); // record end time
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}
void initialize(char src[])
{
    // GEMIZOYME ME TYXAIOYS XARAKTHRES TON PINAKA
    for (int i = 0; i < NUM_CHARS; i++)
    {
        src[i] = 'a' + rand() % 26;
        //printf("%c\n", src[i]);
    }
}

void copy_with_loop(char dst[],char src[])
{
    //ANTIGRAFOYME TON PINAKA KAI EKTYPONOYNE TON XRONO ANTIGRAFEIS
    for (int i = 0; i < NUM_CHARS; i++)
    {
        dst[i] = src[i];
        printf("%c\n", src[i]);
    }
}

void copy_with_memcpy(char dst[],char src[])
{
    //ANTIGRAFOYME TON PINAKA KAI EKTYPONOYNE TON XRONO ANTIGRAFEIS
     memcpy(dst, src, strlen(src)+1);
    for (int i = 0; i < NUM_CHARS; i++)
        printf("%c\n", src[i]);
    
}