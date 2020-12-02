#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "exbiblio.h"

struct Dados{
    int cod;
    char nome[50];
    int salario;
};

int main(){

    Dados *x = NULL;
    int i;
    int regra = -1;
    int n = 0;
    int pos = 0;
    int p = 0;

    do{

        menu();

        printf("\nDigite um numero para selecionar o comando: ");
        scanf(" %d", &regra);

        if(regra == 1){

            printf("\nQuantos funcionarios deseja incluir: ");
            scanf(" %d", &n);

            x = realloc(x, sizeof(Dados) * n);

            for(i = 0 ; i < n ; i++){
                le_funcionario(&x[i]);
            }

        }

        if(regra == 2){

            for(i = 0; i < n ; i++){
                printf("\n----Funcionario %d----\n", i+1);
                mostra_funcionario(x[i]);
            }

        }

        if(regra == 3){

            printf("\nPosicao(1..) do funcionario a ser imprimido: ");
            scanf(" %d", &pos);

            printf("\n----Funcionario %d----\n", pos);
            mostra_funcionario(x[pos-1]);

        }

        if(regra == 4){

            printf("\nMaior salario do funcionario: %d\n\n", maior_salario(x, n));

        }

        if(regra == 5){

            printf("\nMenor salario do funcionario: %d\n\n", menor_salario(x, n));

        }

        if(regra == 6){

            printf("\nMedia dos salarios: %d\n\n", media_salarios(x, n));

        }

        if(regra == 7){

            n++;
            x = realloc(x, sizeof(Dados) * n);

            le_funcionario(&x[n-1]);

        }

        if(regra == 8){

            printf("\nPosicao do funcionario a ser removido: ");
            scanf(" %d", &p);

            remover_funcionario(x, p, n);

            n--;

            x = realloc(x, sizeof(Dados) * n);
            
        }

    }while(regra != 0);

    free(x);

    return 0;
}