#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define TABLE_SIZE 100

void hash_table_init();
char* hash_table_get(char* key);
void hash_table_put(char* key, char* value);
int hash_table_contains(char* key);
void hash_table_remove(char* key);

#endif
