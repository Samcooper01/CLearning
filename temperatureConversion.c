#include <stdio.h>

int main() {
    #define LOWER 0
    #define UPPER 300
    #define STEP 20
    float celc, farh;


    printf("Celcius to Fahrenheit Conversion\n");
    for(celc = LOWER; celc <= UPPER; celc+=STEP) {
        farh = (celc * (9.0/5.0) + 32);
        printf("%3.0f\t%6.1f\n", celc, farh);
        celc += 20;
    }
}