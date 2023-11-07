#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "lista.h"

int main(int argc, char* argv[]) {

    No* n0 = criar_no('C', NULL);
    No* n1 = criar_no('E', NULL);
    No* n2 = criar_no('A', criar_no('D', criar_no('B', criar_no('X', criar_no('Z', NULL))));
    No* n3 = criar_no('U', NULL);
    inserir_no(n0, n2);
    inserir_no(n0, n1);
    inserir_no(n0, n3);
    imprimir_lista(n0);
    printf("\nqtd nos: %d", contar_nos(n0));
    No* n_copia = copiar_lista(n0);
    printf("\n");
    imprimir_lista(n_copia);
    concatenar_listas(n0, n_copia);
    printf("\n");
    imprimir_lista(n0);

    // Chamadas novas
    printf("\nVerificar existencia: %d", verificar_existencia(n0, 'A'));
    printf("\nVerificar ocorrencias: %d", contar_ocorrencias(n0, 'A'));
    printf("\nImprimir inversa: ");
    imprimir_inversa(n0);
    printf("\nInserir no i: ");
    inserir_no_em_i(n0, 2, 'A');
    printf("\n");
    imprimir_lista(n0);
    printf("\nRemover no i: ");
    remover_no_em_i(n0, 2);
    printf("\n");
    imprimir_lista(n0);
    printf("\nRemover no: ");
    remover_no(n0, 'A');
    printf("\n");
    imprimir_lista(n0);
    liberar_lista(n0);
    n0 = NULL;

    //Atividade 9
   
    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    FILE* file = fopen("1kk_rand_float.csv", "r");
    if (file == NULL) {
        printf("nao foi possível abrir o arquivo.\n");
        return 1;
    }

    float num;
    while (fscanf(file, "%f", &num) != EOF) {
        No* novo_no = criar_no(num, NULL); // Use 'criar_no' ao invés de 'no'
        lista_inserir_no(lista_nao_ordenada, novo_no);
        novo_no = criar_no(num, NULL); // Use 'criar_no' ao invés de 'no'
        lista_inserir_no_ordenado(lista_ordenada, novo_no);
    }

    fclose(file);

    // Medir tempo medio de inserção de lista não ordenada
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    printf("\n\nTempo de inicio: %f\n", ((double)start) / CLOCKS_PER_SEC);
    for (int i = 100000; i >= 1; i--) {
        No* novo_no = criar_no(i * 1.0, NULL); // Use 'criar_no' ao invés de 'no'
        lista_inserir_no_ordenado(lista_ordenada, novo_no);
    }
    end = clock();
    printf("Tempo de fim: %f\n", ((double)end) / CLOCKS_PER_SEC);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo medio de insercao na lista ordenada: %f segundos\n", cpu_time_used);

    // Medir tempo médio de inserção de lista ordenada
    start = clock();
    for (int i = 100000; i >= 1; i--) {
        No* novo_no = criar_no(i * 1.0, NULL); // Use 'criar_no' ao invés de 'no'
        lista_inserir_no_ordenado(lista_ordenada, novo_no);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo medio de insercao na lista ordenada: %f segundos\n", cpu_time_used);

    // Libera memoria alocada para as listas
    lista_liberar(lista_nao_ordenada);
    lista_nao_ordenada = NULL;
    lista_liberar(lista_ordenada);
    lista_ordenada = NULL;

    exit(0);
}
