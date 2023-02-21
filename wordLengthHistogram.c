#include <stdio.h>

int main() {
    #define LONGESTWORD 10
    //Initialiize the word Length array which will have frequency of word lengths with 1-9 as possible lengths
    int wordLength[LONGESTWORD];
    for (int i = 0; i < LONGESTWORD;i++){
        wordLength[i] = 0;
    }

    //Get size of words
    #define INWORD 1;
    #define OUTOFWORD 0;
    int c;
    int status = INWORD;
    int length = 0;
    while((c = getchar()) != EOF) {
        if(c == ' ') {
            wordLength[length] += 1;
            length = 0;
        } 
        else if(c == '\n') {
            wordLength[length] += 1;
            length = 0;
            break;
        }else {
            length++;
        }
        putchar(c);
    }
    printf("\n");
    
    //print histogram
    for(int i = 0; i < LONGESTWORD; i++) {
        for(int j = 0; j < wordLength[i]; j++) {
            if(j == 0) {
                printf("%d ", i);
            }
            printf("|");
        }
        printf("\n");
    }
}