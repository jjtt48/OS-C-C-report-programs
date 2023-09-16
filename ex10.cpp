#include <stdio.h>

int main() {

    int integerNum = 10;
    double doubleNum = integerNum; // Implicitly converts int to double

    printf("Implicit Type Casting:\n");
    printf("Integer: %d\n", integerNum);
    printf("Double: %lf\n", doubleNum);


    double floatingNum = 12.345;
    int intFromDouble = (int)floatingNum; // Explicitly converts double to int

    printf("\nExplicit Type Casting:\n");
    printf("Double: %lf\n", floatingNum);
    printf("Integer (after explicit casting): %d\n", intFromDouble);

    return 0;
}