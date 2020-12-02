#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "exbiblio.h"

struct Dados{
    int cod;
    char nome[50];
    int salario;
};

void menu(){
    
    printf("\n");
    printf("|      CADASTRO DE FUNCIONARIOS      |\n");
    printf("|____________________________________|\n");
    printf("|           MENU DE OPCOES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - INSERIR n VALORES NO VETOR     |\n");
    printf("| 2 - IMPRIMIR TODOS OS FUNCIONARIOS |\n");
    printf("| 3 - IMPRIMIR FUNCIONARIO DA POSICAO|\n");
    printf("| 4 - RETORNAR POS. DO MAIOR SALARIO |\n");
    printf("| 5 - RETORNAR POS. DO MENOR SALARIO |\n");
    printf("| 6 - RETORNAR A MEDIA DOS SALARIOS  |\n");
    printf("| 7 - INCLUIR FUNCIONARIO            |\n");
    printf("| 8 - REMOVER UM FUNCIONARIO         |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");

}

void le_funcionario(Dados *x){

    printf("\n");

    printf("Digite o codigo do funcionario: ");
    scanf(" %d", &x->cod);

    printf("Digite o nome do funcionario: ");
    fflush(stdin);
    gets(x->nome);

    printf("Digite o valor do salario do funcionario: ");
    scanf(" %d", &x->salario);

}

void mostra_funcionario(Dados x){

    printf("\n");
    printf("Codigo: %d", x.cod);

    printf("\n");
    printf("Nome: %s", x.nome);

    printf("\n");
    printf("Salario: %d", x.salario);

    printf("\n");
}

int maior_salario(Dados *x, int n){

    int i;
    int sal = 0;
    int p = 0;

    for(i = 0 ; i < n ; i++){
        if(x[i].salario > sal){
            sal = x[i].salario;
            p = i;
        }
    }

    return (p+1);
}

int menor_salario(Dados *x, int n){

    int i;
    int salario = x[0].salario;
    int p = 0;

    for(i = 0 ; i < n ; i++){
        if(x[i].salario < salario){
            salario = x[i].salario;
            p = i;
        }
    }

    return (p+1);
}

int media_salarios(Dados *x, int n){

    int i;
    int soma;

    for(i = 0 ; i < n ; i++){
        soma += x[i].salario; 
    }

    return (soma/n);
}

void remover_funcionario(Dados *x, int p, int n){

    int i, j;
    Dados auxiliar;

    for(i = 0 ; i < n ; i++){
        if(i == (p-1)){
            for(j = i ; j < (n-1) ; j++){
                auxiliar = x[j];
                x[j] = x[j+1];
                x[j+1] = auxiliar;
            }
        }
    }

}