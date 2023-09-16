#include <stdio.h>


long int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    int base;
    int exponent;


    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    long int result = power(base, exponent);
    printf("power is %.ld\n",result);

    return 0;
}