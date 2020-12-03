#include <stdlib.h>
#include <stdio.h>

struct reg{
    int valor;
    struct reg * prox;
};

typedef struct reg NO;

void imprime(NO * lista);
int conta_ced(NO * lista);
int profundidade(NO * lista, int v);

int main(){

    NO * lista;
    NO m2,m3;
    int regra = 0;
    int v = 0;

    lista = (NO *)malloc(sizeof(NO));
    lista->valor = 5;
    lista->prox = &m2;

    m2.valor = 6;
    m2.prox = &m3;
    m3.valor = 7;
    m3.prox = NULL;

    printf("| 1 - IMPRIMIR LISTA             |\n");
    printf("| 2 - CONTAR TAMANHO LISTA       |\n");
    printf("| 3 - PROFUNDIDADE DE TAL VALOR  |\n");

    scanf(" %d", &regra);

    switch(regra){

        case 1:
            imprime(lista);
            break;

        case 2:
            printf("%d", conta_ced(lista));
            break;

        case 3:
            printf("Digite o valor: ");
            scanf("%d", &v);
            printf("%d",profundidade(lista, v));
            break;

    }

    return 0;
}

void imprime(NO * lista){

    NO * mov;

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

    while(mov->valor != v){
        cont++;
        mov = mov->prox;
    }

    return cont;
}