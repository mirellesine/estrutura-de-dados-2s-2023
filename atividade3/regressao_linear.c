#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int x;
    float y;
}coodinates;

int main(int argc, char *argv[]){

    printf(argv[1]);

    int lineNumbers = -1;
    FILE *arquivoCSV = fopen(argv[1], "r");
    float mediaX = 0;
    float mediaY = 0;

    if(arquivoCSV == NULL){
        printf("Erro: arquivo CSV nao encontrado");
        return 1;
    }

    char buffer;

    do{
        buffer = fgetc(arquivoCSV);

        if(buffer == '\n') {
            lineNumbers++;
        }

    }while(buffer != EOF);

    coodinates *CoordinateArray = (coodinates *)malloc(sizeof(coodinates) * lineNumbers);
    
    if(CoordinateArray == NULL){
        printf("Allocating memory was wrong\n");
        return 1;
    }

    rewind(arquivoCSV);

    for (int i = 0; i < lineNumbers; i++) {
        fscanf(arquivoCSV, "%d,%f\n", &CoordinateArray[i].x, &CoordinateArray[i].y);
    }

    fclose(arquivoCSV);

    for (int i = 0; i < lineNumbers; i++) {
        mediaX = mediaX + CoordinateArray[i].x;
        mediaY = mediaY + CoordinateArray[i].y;
    }

    mediaX = mediaX/lineNumbers;
    mediaY = mediaY/lineNumbers;

    float XlessAvarageX = 0;
    float XlessAvarageXpow = 0;

    for (int i = 0; i < lineNumbers; i++) {
        XlessAvarageX += (CoordinateArray[i].x - mediaX) * (CoordinateArray[i].y - mediaY);
        XlessAvarageXpow += (CoordinateArray[i].x - mediaX) * (CoordinateArray[i].x - mediaX);
    }

    float inclination = XlessAvarageX / XlessAvarageXpow;
    printf("Inclinacao : %.2f\n", inclination);


    float intercepcao = mediaY - (inclination * mediaX);

    printf("equação da regressão linear: y = %.2f * x + %.2f\n", inclination, intercepcao);

    return 0;
}