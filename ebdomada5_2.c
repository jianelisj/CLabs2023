#include <stdio.h>
#include <string.h>

void inverse(char *s, char *invs);
int count_words(char *s);

int main() 
{
    char text[1000000];
    char inv_text[1000000];
    
    printf("Please enter text:" );
    scanf("%1024[^\n]",text); 

    inverse(text, inv_text); //κλήση συνάρτησης αντιστροφής λέξεων και χαρακτήρων
    printf("Inverted text: %s\n",text);
    
    int word_count = count_words(text);
    printf("Number of words: %d\n", word_count);
    
    return 0;
}

void inverse(char *inputstr, char *invs) 
{
    int i,j;
    char stwapch;
    j = strlen(inputstr) - 1;

    //Με αυτό το for αντιστρέφουμε όλους τους χαρακτήρες του string εισόδου
    for (i = 0; i < j; i++, j--) 
    {
        stwapch = inputstr[i];
        inputstr[i] = inputstr[j];
        inputstr[j] = stwapch;
    }

    strcpy(invs, inputstr);//αντιγράφουμε το string εισόδου inputstr στο string εξόδου invs
  
    
    //Εδώ Αντιστρέφουμε κάθε λέξη του string εισόδου
    char *trmp = invs;
    char *ptr = invs;
    while (*ptr) //εκτελούμε επανάληψη όσο δεν έχουμε φτάσει στο τέλος του αλφαριθμητικού
    {
        if (*ptr == ' ' || *ptr == '\n' || *ptr == '\t') //αυτοί είναι οι χαρακτήρες τερματισμού μιας λέξης
         {
            //εντοπίζουμε το τέλος κάθε λέξης και την αντιστρέφουμε
            char *nextptr = ptr - 1;

            while (nextptr >= trmp) 
            {
                char p = *nextptr;
                *nextptr = *trmp;
                *trmp = p;
                nextptr--;
                trmp++;
            }
            trmp = ptr + 1;
        }
        ptr++; //μετάβαση στον επόμενο χαρακτήρα του string αυξάνοντας το δείκτη
    }
   
}

int count_words(char *inputstr) //συνάρτηση υπολογισμού πλήθους λέξεων
 {
    int wrd_counter = 0;
    int samew = 0;

    while (*inputstr != '\0') //Όσο το αλφαριθμητικό δεν έχει τελειώσει κάνουμε επανάληψη
    {
        if (*inputstr == ' ' || *inputstr == '\n' || *inputstr == '\t') //αυτοί είναι οι χαρακτήρες τερματισμού μιας λέξης
            samew = 0;
        
        else if (!samew)
         {
            samew = 1;  //ένδειξη ότι αλλάζουμε λέξη
            wrd_counter++; //αύξηση μετρητή λέξεων
        }

        inputstr++; //μετάβαση στον επομενο χαρακτήρα του string αυξάνοντας το δείκτη
    }

    return wrd_counter; //επιστροφή μετρητή λέξεων
}