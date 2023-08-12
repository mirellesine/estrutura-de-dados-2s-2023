#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;

    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }
    
    int number = atoi(argv[1]);

    if (isPrime(number)) {
        printf("1 - O numero %d eh primo.\n", number);
    } else {
        printf("0 - O numero %d nao eh primo.\n", number);
    }
    
    return 0;
}
