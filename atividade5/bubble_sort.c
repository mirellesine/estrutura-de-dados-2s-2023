#include "bubble_sort.h"
#include <string.h>
#define MaxTamanhoPalavra 50

void swap(char *WordA, char *WordB){
    char PalavraTemp[MaxTamanhoPalavra];
    strcpy(PalavraTemp, WordA);
    strcpy(WordA, WordB);
    strcpy(WordB, PalavraTemp);
}

void BubbleSort(char palavras[][MaxTamanhoPalavra], int NumElementos){
    int i, j;
    for (i = 0; i < NumElementos - 1; i++){
        for (j = 0; j < NumElementos - i - 1; j++){
            if (strcmp(palavras[j], palavras[j + 1]) > 0){
                swap(palavras[j], palavras[j + 1]);
            }
        }
    }
}