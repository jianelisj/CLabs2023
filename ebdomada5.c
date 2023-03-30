#include <stdio.h>
#include <string.h>

void inverse(char *s, char *invs);
int count_words(char *s);

int main() 
{
    char text[1000000];
    char inv_text[1000000];
    
    printf("Enter Input String: ");
    fgets(text, sizeof(text), stdin); //εισαγωγή strign εισόδου μέσω fgets για να μπορούμε να εισάγουμε και κενά
    
    inverse(text, inv_text); //κλήση συνάρτησης αντιστροφής λέξεων και χαρακτήρων
    printf("Inverted text: %s\n",text);
    
    int word_count = count_words(text);
    printf("Number of words: %d\n", word_count);
    
    return 0;
}

void inverse(char *s, char *invs) 
{
    int i,j;
    char temp;
    j = strlen(s) - 1;

    //Με αυτό το for αντιστρέφουμε όλους τους χαρακτήρες του string εισόδου
    for (i = 0; i < j; i++, j--) 
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    strcpy(invs, s);//αντιγράφουμε το string εισόδου s στο string εξόδου invs
  
    
    //Εδώ Αντιστρέφουμε κάθε λέξη του string εισόδου
    char *strwrd = invs;
    char *p = invs;
    while (*p != '\0') //εκτελούμε επανάληψη όσο δεν έχουμε φτάσει στο τέλος του αλφαριθμητικού
    {
        if (*p == ' ' || *p == '\n' || *p == '\t') //αυτοί είναι οι χαρακτήρες τερματισμού μιας λέξης
         {
            //εντοπίζουμε το τέλος κάθε λέξης και την αντιστρέφουμε
            char *q = p - 1;

            while (q >= strwrd) 
            {
                char tmp = *q;
                *q = *strwrd;
                *strwrd = tmp;
                q--;
                strwrd++;
            }
            strwrd = p + 1;
        }
        p++; //μετάβαση στον επόμενο χαρακτήρα του string αυξάνοντας το δείκτη
    }
   
}

int count_words(char *s) //συνάρτηση υπολογισμού πλήθους λέξεων
 {
    int count = 0;
    int in_word = 0;

    while (*s != '\0') //Όσο το αλφαριθμητικό δεν έχει τελειώσει κάνουμε επανάληψη
    {
        if (*s == ' ' || *s == '\n' || *s == '\t') //αυτοί είναι οι χαρακτήρες τερματισμού μιας λέξης
        {
            in_word = 0;
        } 
        else if (!in_word)
         {
            in_word = 1;  //ένδειξη ότι αλλάζουμε λέξη
            count++; //αύξηση μετρητή λέξεων
        }

        s++; //μετάβαση στον επομενο χαρακτήρα του string αυξάνοντας το δείκτη
    }

    return count; //επιστροφή μετρητή λέξεων
}