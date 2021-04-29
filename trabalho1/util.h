#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct{
    int hora;
    int minuto;
    int dia;
    int mes;
    int ano;
}tempo;

typedef struct{
    char nome[50];
    tempo inicio;
    int duracao;
    tempo deadline;
}reg;

struct Dados{
    int id;
    reg registro;
    struct Dados * prox;
};

typedef struct Dados Dados;

void menu();
Dados * insere_inicio(Dados * lista);
Dados * insere_fim(Dados * lista);
void visualizar_tarefas(Dados * lista);
Dados * excluir_tarefa(Dados * lista, int valor);
int editar_tarefa(Dados * lista);
Dados * le_arquivo(Dados * lista);
void gera_arq(Dados * lista);
void salva_agend_dia(Dados * lista);
Dados * comp_agenda_dia(Dados * lista);

Dados * merge_sort(Dados * lista);
Dados * meio(Dados * lista);
Dados * merge(Dados * e, Dados * d);
int novo_id(Dados * lista);
void escreve_id(Dados * lista);
Dados * alok();
Dados * insere(Dados * lista, Dados * novo);