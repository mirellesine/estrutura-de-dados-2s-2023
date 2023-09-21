#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main (int argc, char *argv[]){
    int sizeOfArray = argc - 1;
    int vet[sizeOfArray];

    for(int i = 0; i < argc - 1; i++){
        if(i + 1 <= argc -1){
            int value = atoi(argv[i+1]);
            vet[i] = value;
        }
    }

    bubble_sort(vet, sizeOfArray);

    for(int i = 0; i < argc - 1; i++){
        printf("\n%d ", vet[i]);
    }
    printf("\n");
}