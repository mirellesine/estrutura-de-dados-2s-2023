#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_no(char valor, No* proximo_no) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo_no = proximo_no;
    return novo_no;
}

void inserir_no(No* lista, No* novo_no) {
    if (lista != NULL) {
        if (lista->proximo_no == NULL) {
            lista->proximo_no = novo_no;
        } else {
            inserir_no(lista->proximo_no, novo_no);
        }
    }
}

void imprimir_lista(No* lista) {
    if (lista != NULL) {
        printf("%c ", lista->valor);
        imprimir_lista(lista->proximo_no);
    }
}

int contar_nos(No* lista) {
    if (lista != NULL) {
        return 1 + contar_nos(lista->proximo_no);
    }
    return 0;
}

No* copiar_lista(No* lista) {
    if (lista != NULL) {
        return criar_no(lista->valor, copiar_lista(lista->proximo_no));
    }
    return NULL;
}

void concatenar_listas(No* lista, No* lista_concatenada) {
    inserir_no(lista, lista_concatenada);
}

void liberar_lista(No* lista) {
    if (lista != NULL) {
        liberar_lista(lista->proximo_no);
        free(lista);
    }
}

int verificar_existencia(No* lista, char valor_busca) {
    if (lista != NULL) {
        if (lista->valor == valor_busca) {
            return 1;
        }
        return verificar_existencia(lista->proximo_no, valor_busca);
    }
    return 0;
}

int contar_ocorrencias(No* lista, char valor_busca) {
    if (lista != NULL) {
        int ocorrencias = contar_ocorrencias(lista->proximo_no, valor_busca);
        if (lista->valor == valor_busca) {
            return 1 + ocorrencias;
        }
        return ocorrencias;
    }
    return 0;
}

void imprimir_inversa(No* lista) {
    if (lista != NULL) {
        imprimir_inversa(lista->proximo_no);
        printf("%c ", lista->valor);
    }
}

void inserir_no_em_i(No* lista, int i, char valor) {
    if (lista != NULL && i >= 0) {
        if (i == 0) {
            No* novo_no = criar_no(valor, lista->proximo_no);
            lista->proximo_no = novo_no;
        } else {
            inserir_no_em_i(lista->proximo_no, i - 1, valor);
        }
    }
}

void remover_no_em_i(No* lista, int i) {
    if (lista != NULL && i >= 0) {
        if (i == 0 && lista->proximo_no != NULL) {
            No* no_remover = lista->proximo_no;
            lista->proximo_no = lista->proximo_no->proximo_no;
            free(no_remover);
        } else {
            remover_no_em_i(lista->proximo_no, i - 1);
        }
    }
}

void remover_no(No* lista, char valor_busca) {
    if (lista != NULL) {
        if (lista->proximo_no != NULL && lista->proximo_no->valor == valor_busca) {
            No* no_remover = lista->proximo_no;
            lista->proximo_no = lista->proximo_no->proximo_no;
            free(no_remover);
        } else {
            remover_no(lista->proximo_no, valor_busca);
        }
    }
}

//Função nova 
void lista_inserir_no_ordenado(No* L, No* no) {
    if (L == NULL || no->valor <= L->valor) {
        no->proximo_no = L;
        L = no;
    } else {
        lista_inserir_no_ordenado(L->proximo_no, no);
    }
}