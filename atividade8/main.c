#include <stdio.h>
#include <stdlib.h>
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

    exit(0);
}
