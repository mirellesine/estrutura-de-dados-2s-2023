#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"


void bubble_sort(int *vet, int size){
    int aux;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i; j++){
            if (vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}