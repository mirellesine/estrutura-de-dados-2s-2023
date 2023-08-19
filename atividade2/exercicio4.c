#include <stdio.h>

int contaIntNoArray(int array[], int tamanho, int busca) {
    int contador = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == busca) {
            contador++;
        }
    }
    
    return contador;
}

int main() {
    int arrayDeNumeros[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int tamanhoDoArray = sizeof(arrayDeNumeros) / sizeof(arrayDeNumeros[0]);
    int numeroDeBusca = 7;

    int quantidadeOcorrencias = contaIntNoArray(arrayDeNumeros, tamanhoDoArray, numeroDeBusca);

    printf("O número %d aparece %d vezes no array.\n", numeroDeBusca, quantidadeOcorrencias);

    return 0;
}
