#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    char valor;
    struct No* proximo_no;
} No;

No* criar_no(char valor, No* proximo_no);
void inserir_no(No* lista, No* novo_no);
void imprimir_lista(No* lista);
int contar_nos(No* lista);
No* copiar_lista(No* lista);
void concatenar_listas(No* lista, No* lista_concatenada);
void liberar_lista(No* lista);
int verificar_existencia(No* lista, char valor_busca);
int contar_ocorrencias(No* lista, char valor_busca);
void imprimir_inversa(No* lista);
void inserir_no_em_i(No* lista, int i, char valor);
void remover_no_em_i(No* lista, int i);
void remover_no(No* lista, char valor_busca);
//Função nova
void lista_inserir_no_ordenado(No* L, No* no);