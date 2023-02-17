#include <stdio.h>
#include <stdbool.h>

int main() {
    //Count blanks, tabs, and newlines
    
    int blankCount = 0, tabCount = 0, newLineCount = 0, c;
    while((c = getchar()) != EOF) {
        if(c == ' ') {
            blankCount++;
        }
        if(c == '\t') {
            tabCount++;
        }
        if(c == '\n'){
            newLineCount++;
        }
    }
    printf("\nNumber of blanks: %d\nNumber of tabs: %d\nNumber of newlines: %d", blankCount, tabCount, newLineCount);


    //White Space Corrector (removes all but one white space)
    int c;
    bool firstSpace = false;
    while((c = getchar()) != EOF) {
        if(c == ' ' && !firstSpace){
            putchar(c);
            firstSpace = true;
        } 
        if (c != ' ' && c != '\n') {
            putchar(c);
        }
    }
    

    //replace tabs with \t and backspaces with \b and each backslash with double slashes
    int c;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if(c == '\\') {
            putchar('\\');
        }
        else {
            putchar(c);
        }
    }
}