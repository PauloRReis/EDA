#include "eda_exerciciopilhas.h"

struct NO{
    int valor;
    struct NO * prox;
};

void menu(){
    printf("| 1 - IMPRIMIR LISTA             |\n");
    printf("| 2 - CONTAR TAMANHO LISTA       |\n");
    printf("| 3 - PROFUNDIDADE DE TAL VALOR  |\n");
    printf("| 4 - INSERIR UM VALOR INICIO    |\n");
    printf("| 5 - INSERIR ORDENADO           |\n");
    printf("| 6 - INSERIR UM VALOR FIM       |\n");
    printf("| 7 - LIBERAR LISTA              |\n");
    printf("| 8 - REMOVER ELEMENTO           |\n");
    printf("| 0 - SAIR                       |\n");
}

void imprime(NO * lista){

    NO * mov = NULL;

    mov = lista;
    
    while(mov != NULL){
        printf("%d\n", mov->valor);
        mov = mov->prox;
    }

}

int conta_ced(NO * lista){

    NO * mov;
    int cont = 0;

    mov = lista;

    if(lista == NULL){
        return 0;
    }

    while(mov != NULL){
        cont++;
        mov = mov->prox;
    }

    return cont;
}

int profundidade(NO * lista, int v){

    NO * mov;
    int cont = 0;

    mov = lista;

    while(mov->valor != v || mov != NULL){
        cont++;
        mov = mov->prox;
    }

    if(mov == NULL){
        return(-1);
    }else{
        return cont;
    }


    return cont;
}

NO * insere_inicio(NO * lista, int v){

    NO * novo = NULL;

    novo = (NO *) malloc(sizeof(NO));
    novo->valor = v;
    novo->prox = lista;

    return (novo);
}

NO * insere_ordenado(NO * lista, int v){

    NO * mov = NULL;
    NO * novo = NULL;
    NO * anterior = NULL;

    mov = lista;
    
    novo = (NO *) malloc(sizeof(NO));
    novo->valor = v;
    novo->prox = NULL;

    while(mov->valor < novo->valor || mov != NULL){
        anterior = mov;
        mov = mov->prox;
    }

    if(mov == NULL){
        free(novo);
        insere_fim(lista, v);
    }

    if(anterior == NULL){
        novo->prox = mov;
        lista = novo;
    }else{
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }

    return (lista);
}

NO * insere_fim(NO *lista, int valor){

    NO * mov = NULL;
    NO * novo = NULL;
    NO * anterior = NULL;

    mov = lista;

    novo = (NO *)malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    while(mov != NULL){
        anterior = mov;
        mov = mov->prox;
    }

    if(mov == NULL){
        anterior->prox = novo;
    }

    return (lista);
}

NO * libera_lst(NO *lista){

    NO * mov = NULL;
    NO * proxelem = NULL;

    mov = lista;

    while(mov != NULL){
        proxelem = mov->prox;
        free(mov);
        mov = proxelem;
    }

    lista = NULL;

    return (lista);
}

NO * busca_rmv(NO *lista, int valor){

    NO * mov = NULL;
    NO * ant = NULL;

    mov = lista;

    while(mov->valor != valor || mov == NULL){
        ant = mov;
        mov = mov->prox;
    }

    if(mov->valor == valor){
        ant->prox = mov->prox;
        free(mov);
    }
    
    if(mov == NULL){
        printf("Valor nao encontrado!!!\n");
    }

    return (lista);
}

NO * inicializa(){

    NO * lista;
    int v = 0;

    printf("Digite um valor: ");
    scanf(" %d", &v);

    lista = (NO *)malloc(sizeof(NO));
    lista->valor = v;
    lista->prox = NULL;

    return lista;
}