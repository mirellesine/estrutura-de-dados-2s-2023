#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"
#define MaxTamanhoPalavra 100
#define NumeroMaxPalavras 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    FILE *InputFile = fopen(argv[1], "r");
    if (InputFile == NULL) {
        perror("Erro ao abrir arquivo(INPUT)");
        return 1;
    }

    char palavras[NumeroMaxPalavras][MaxTamanhoPalavra];
    int contPalavras = 0;
    while (!feof(InputFile) && contPalavras < NumeroMaxPalavras) {
        fscanf(InputFile, "%s", palavras[contPalavras]);
        contPalavras++;
    }
    fclose(InputFile);

    BubbleSort(palavras, contPalavras);

    FILE *arquivoSaida = fopen("arq_palavras_ordenado.txt", "w");
    if (arquivoSaida == NULL) {
        perror("Erro na abertura do arquivo(OUTPUT)");
        return 1;
    }

    for (int i = 0; i < contPalavras; i++) {
        fprintf(arquivoSaida, "%s\n", palavras[i]);
    }
    fclose(arquivoSaida);

    return 0;
}