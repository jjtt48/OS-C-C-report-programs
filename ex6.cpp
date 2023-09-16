#include <stdio.h>

int main() {
    int n, i;
    long int fib[100];
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Error.\n");
        return 1;
    }
    fib[0] = 0;
    fib[1] = 1;
    printf("Fibonacci Series: %ld, %ld", fib[0], fib[1]);
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf(", %ld", fib[i]);
    }
    printf("\n");
    return 0;
}