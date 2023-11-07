#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main() {
    hash_table_init();

    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    hash_table_put("chave3", "valor3");

    printf("Valor associado à chave1: %s\n", hash_table_get("chave1"));
    printf("Valor associado à chave2: %s\n", hash_table_get("chave2"));
    printf("Valor associado à chave3: %s\n", hash_table_get("chave3"));

    if (hash_table_contains("chave1")) {
        printf("A tabela contém a chave1.\n");
    } else {
        printf("A tabela não contém a chave1.\n");
    }

    hash_table_remove("chave2");

    if (hash_table_contains("chave2")) {
        printf("A tabela contém a chave2.\n");
    } else {
        printf("A tabela não contém a chave2.\n");
    }

    return 0;
}
