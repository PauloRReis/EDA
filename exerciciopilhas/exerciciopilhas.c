#include "eda_exerciciopilhas.h"

struct NO{
    int valor;
    struct NO * prox;
};

int main(){

    NO * lista = NULL;
    int regra = 0;
    int v = 0;
    int elemento = 0;

    lista = inicializa();

    do{
    
        menu();

        scanf(" %d", &regra);

        switch(regra){

            case 1:
                imprime(lista);
                break;

            case 2:
                printf("%d\n", conta_ced(lista));
                break;

            case 3:
                printf("Digite o valor: ");
                scanf(" %d", &v);
                printf("%d\n",profundidade(lista, v));
                break;

            case 4:
                printf("Digite o valor: ");
                scanf(" %d", &v);

                lista = insere_inicio(lista, v);
    
                break;

            case 5:
                printf("Digite o valor: ");
                scanf(" %d", &elemento);

                lista = insere_ordenado(lista, elemento);

                break;

            case 6:
                printf("Digite o valor: ");
                scanf(" %d", &elemento);

                lista = insere_fim(lista , elemento);

                break;

            case 7:
                
                lista = libera_lst(lista);

                break;

            case 8:
                printf("Qual elemento remover: ");
                scanf(" %d", &elemento);

                busca_rmv(lista, elemento);

                break;
        }

    }while(regra != 0);

    return 0;
}