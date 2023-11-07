#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabela_hash.h"

struct HashNode {
    char* key;
    char* value;
    struct HashNode* next;
};

struct HashNode* tabela[TABLE_SIZE];

unsigned int hash(char* key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = hash * 31 + key[i];
    }
    return hash % TABLE_SIZE;
}

void hash_table_init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i] = NULL;
    }
}

char* hash_table_get(char* key) {
    int index = hash(key);
    struct HashNode* current = tabela[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void hash_table_put(char* key, char* value) {
    int index = hash(key);
    struct HashNode* new_node = (struct HashNode*)malloc(sizeof(struct HashNode));
    if (new_node == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o novo nó.\n");
        exit(1);
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = tabela[index];
    tabela[index] = new_node;
}

int hash_table_contains(char* key) {
    int index = hash(key);
    struct HashNode* current = tabela[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void hash_table_remove(char* key) {
    int index = hash(key);
    struct HashNode* current = tabela[index];
    struct HashNode* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                tabela[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
