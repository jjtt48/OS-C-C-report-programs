#include <stdio.h>

int main() {
    int i;
    printf("Decimal\t\tOctal\t\tHexadecimal\n");
    for (i = 1; i <= 10; i++) {
        printf("%d\t\t%o\t\t%X\n", i, i, i);
    }
    return 0;
}