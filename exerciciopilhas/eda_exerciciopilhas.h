#include <stdlib.h>
#include <stdio.h>

typedef struct NO NO;

void menu();
void imprime(NO * lista);
int conta_ced(NO * lista);
int profundidade(NO * lista, int v);
NO * insere_inicio(NO * lista, int v);
NO * insere_ordenado(NO * lista, int v);
NO * insere_fim(NO *lista, int valor);
NO * libera_lst(NO *lista);
NO * busca_rmv(NO *lista, int valor);
NO * inicializa();

