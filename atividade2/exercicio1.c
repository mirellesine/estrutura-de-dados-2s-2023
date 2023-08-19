#include <stdio.h>

//Soma dos elementos de um array. Escreva uma função que recebe um array de números inteiros e retorna a soma de todos os elementos;


int main() {
    int tamanhoArray;
    
    printf("Quantos elementos deseja somar?");
    scanf("%d", &tamanhoArray);

    int array[tamanhoArray];

    for (int i = 0; i < tamanhoArray; i++) {
        printf("Digite o número para a posição %d: ", i);
        scanf("%d", &array[i]);
    }

    int soma;
    soma = 0;

    for (int i = 0; i < tamanhoArray; i++) {
        soma += array[i];
    }

    printf("A soma dos elementos do array é: %d\n", soma);

    return 0;
}
