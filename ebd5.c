#include <stdio.h>
#include <string.h>

void inverse(char *s, char *invs);
int count_words(char *s);

int main() 
{
    char text[1000000];
    char inv_text[1000000];
    
    printf("Enter text (max 1MB): ");
    fgets(text, sizeof(text), stdin);
    
    inverse(text, inv_text);
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

    for (i = 0; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    strcpy(invs, s);
  
    
    // Reverse words in output string
    char *word_start = invs;
    char *p = invs;
    while (*p != '\0') {
        if (*p == ' ' || *p == '\n' || *p == '\t') {
            // Found end of word, reverse it
            char *q = p - 1;
            while (q >= word_start) {
                char tmp = *q;
                *q = *word_start;
                *word_start = tmp;
                q--;
                word_start++;
            }
            word_start = p + 1;
        }
        p++;
    }
   
    // Reverse entire string
    char *begin = invs;
    char *end = p - 1;
    while (begin < end)
     {
        char tmp = *begin;
        *begin = *end;
        *end = tmp;
        begin++;
        end--;
    }

   
}

int count_words(char *s)
 {
    int count = 0;
    int in_word = 0;
    while (*s != '\0') {
        if (*s == ' ' || *s == '\n' || *s == '\t') 
        {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        s++;
    }
    return count;
}