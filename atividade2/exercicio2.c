#include <stdio.h>

//Maior e menor elemento do array. Escreva uma função que recebe um array de números inteiros e retorna o menor e o maior elemento do array.

void encontrarMaiorMenor(int array[], int tamanho, int *menor, int *maior) {
    *menor = array[0];
    *maior = array[0];

    for (int i = 1; i < tamanho; i++) {
        if (array[i] < *menor) {
            *menor = array[i];
        }
        if (array[i] > *maior) {
            *maior = array[i];
        }
    }
}

int main () {
    int tamanhoArray;
    
    printf("Quantos elementos tem o array?");
    scanf("%d", &tamanhoArray);

    int array[tamanhoArray];

    for (int i = 0; i < tamanhoArray; i++) {
        printf("Digite o número para a posição %d: ", i);
        scanf("%d", &array[i]);
    }

    int menor, maior;
    encontrarMaiorMenor(array, tamanhoArray, &menor, &maior);

    printf("O menor elemento do array é: %d\n", menor);
    printf("O maior elemento do array é: %d\n", maior);

    return 0;
}