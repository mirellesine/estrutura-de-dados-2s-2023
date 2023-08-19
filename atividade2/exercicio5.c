#include <stdio.h>

void multiplicaArray(int array1[], int array2[], int tamanho, int resultado[]) {
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = array1[i] * array2[i];
    }
}

int main() {
    int array1[] = {5, 7, 9, 6};
    int array2[] = {5, 7, 9, 6};
    int tamanho = sizeof(array1) / sizeof(array1[0]);
    int resultado[tamanho];

    multiplicaArray(array1, array2, tamanho, resultado);

    printf("Resultado da multiplicação: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", resultado[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
