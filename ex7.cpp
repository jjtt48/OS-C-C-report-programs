#include <stdio.h>

int isUpperCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char inputChar;
    printf("Enter letter: ");
    scanf(" %c", &inputChar);
    if (isUpperCase(inputChar) == 1) {
        printf("%c is an uppercase letter.\n", inputChar);
    } else {
        printf("%c is not an uppercase letter.\n", inputChar);
    }

    return 0;
}