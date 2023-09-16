#include <stdio.h>

int isLowerCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char inputChar;
    printf("Enter letter: ");
    scanf(" %c", &inputChar);
    if (isLowerCase(inputChar) == 1) {
        printf("%c is an lowercase letter.\n", inputChar);
    } 
    else {
        printf("%c is not an lowercase letter.\n", inputChar);
    }
    return 0;
}