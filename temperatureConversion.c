#include <stdio.h>

int main() {
    float celc, farh;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celcius to Fahrenheit Conversion\n");
    celc = lower;
    while(lower <= upper) {
        farh = (celc * (9.0/5.0) + 32);
        printf("%3.0f\t%6.1f\n", celc, farh);
        celc += 20;
        lower += step;
    }
}