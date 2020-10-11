#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* copyStr(const char* someStr) {
    char* buf = malloc (sizeof(char) * strlen(someStr));
    sprintf(buf, "%s", someStr);
    return buf;
}

// Function to reverse any sequence
// starting with pointer begin and
// ending with pointer end
void reverse(char* begin, char* end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverseWordsInString(char *myString) {
/* Your code here */
    char* word_begin = NULL;
    char* temp = myString; /* temp is for word boundary */

    /*STEP 1 of the above algorithm */
    while (*temp) {

        /*This condition is to make sure that the 
        string start with valid character (not
        space) only*/
        if ((word_begin == NULL) && (*temp != ' '))
            word_begin = temp;

        if (word_begin && ((*temp++ == ' ') ||
            (*(temp + 1) == '\0'))) {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    } /* End of while */

    /*STEP 2 of the above algorithm */
    reverse(myString, temp - 1);
}

void putlong(long n) 
{ 
    if (n/10) 
        putlong(n/10); 

    // Print the last digit 
    putchar(n%10 + '0');
} 

int main() {
    // char* prt = "srijan";
    // printf("%s", prt);
    // printf("%ld", strlen(prt));
    putlong(256);
}