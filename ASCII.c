#include <stdio.h>


int main() {
    char c = 'c';

    if (c >= 'a' && c <= 'z') {
        c = (c - 'a') + 'A';
    }

    printf("\n%c\n", c);

    return 0;
}