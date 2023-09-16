#include <stdio.h>

int main() {
    int num;
   long int factorial = 1;
   printf("Enter number: ");
   scanf("%d", &num);
   if (num < 0) {
        printf("Error.\n");
    } else {
       for (int i = 1; i <= num; i++) {
            factorial *= i;
        }
        printf("Factorial of %d = %d\n", num, factorial);
    }

    return 0;
}