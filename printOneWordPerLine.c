#include <stdio.h>
#include <stdbool.h>

//prints one word per line
int main() {
    #define INWORD 1;
    #define OUTOFWORD 0;
    int c;
    int status = INWORD;
    while((c = getchar()) != EOF) {
        if(c == ' ' && status) {
            status = OUTOFWORD;
            putchar('\n');
        } else {
            putchar(c);
            status = INWORD;
        }
    }
}