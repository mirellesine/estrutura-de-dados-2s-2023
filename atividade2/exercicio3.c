#include <stdio.h>
#include <string.h>

int buscaString(char *array[], int tamanho, char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1; // achou
        }
    }
    return 0; // nao achou
}

int main () {
    char *arrayDeString[] = {"olá", "Mirelle", "Alves"};
    int tamanhoDoArray = sizeof(arrayDeString) / sizeof(arrayDeString[0]);
    char busca[] = "Mirelle";

    int resultado = buscaString(arrayDeString, tamanhoDoArray, busca);

    if (resultado) {
        printf("A string de busca foi encontrada no array.\n");
    } else {
        printf("A string de busca não foi encontrada no array.\n");
    }

    return 0;
}
