#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int dado;
    struct no *prox;
}NO;

typedef struct fila{
    NO * ini;
    NO * fim;
}fila;

//carro igual a 1
//caminhao igual a 2

void movimentaAté(fila * f, NO * c);
NO * criaNo(int dado);

int main(){

    fila * f;
    f->ini = NULL;
    f->fim = NULL;

}

NO * criaNo(int dado){
    
    NO * novo = (NO*) malloc(sizeof(NO));
    novo->dado = dado;
    novo->prox = NULL;

    return (novo);
}


void movimentaAté(fila * f, NO * c){

    NO * mov = NULL;
    NO * ant = NULL;
    NO * aux = NULL;
    NO * escape1 = NULL;
    NO * escape2 = NULL;
    NO * novo = NULL;

    mov = f->ini;
    aux = escape1;

    while(mov != NULL){
        
        if(mov->dado != c->dado){
            
            if(escape1 == NULL){
                
                escape1 = criaNo(1);
            
            }else{
               
                novo = criaNo(1);
                
                while(aux != NULL){
                    ant = aux;
                    aux = aux->prox;
                }                
                if(aux == NULL){
                    ant->prox = novo;
                }

            }
        }

        if(mov->dado == c->dado){
            ant->prox = mov->prox;
            free(mov);
        }
        mov = mov->prox;
    }

}