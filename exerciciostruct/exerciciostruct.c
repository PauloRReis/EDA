#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int cod;
    char nome[50];
    int salario;
}Dados;

void le_funcionario(Dados *x);
void mostra_funcionario(Dados x);
int maior_salario(Dados *x);
int menor_salario(Dados *x);
int media_salarios(Dados *x);

int main(){

    Dados x[6];
    int i, j = 0;
    int regra = 0;

    printf("\nDigite o cadastro dos funcionarios\n\n");

    for(i = 0 ; i < 6 ; i++){
        printf("\n----Funcionario %d----\n", i+1);
        le_funcionario(&x[i]);
    }

    do{

        printf("\n-----MENU DE ACOES-----\n");
        printf("1. Retornar a posicao do vetor que armazena o funcionario de maior salario;\n");
        printf("2. Retornar a posicao do vetor que armazena o funcionario de menor salario;\n");
        printf("3. Imprimir os dados de um funcionario de acordo com sua posicao no vetor;\n");
        printf("4. Retornar a media dos salarios dos funcionarios; \n");
        printf("5. Imprimir os dados de todos os funcionarios;\n");
        printf("6. Sair do programa;\n");

        printf("\nDigite um numero para selecionar o comando: ");
        scanf(" %d", &regra);

        if(regra == 1){

            printf("\nMaior salario do funcionario: %d\n\n", maior_salario(x));

        }

        if(regra == 2){

            printf("\nMenor salario do funcionario: %d\n\n", menor_salario(x));

        }

        if(regra == 3){

            printf("Digite a posicao do vetor: ");
            scanf(" %d", &j);

            printf("\n----Funcionario %d----\n", j);
            mostra_funcionario(x[j]);


        }

        if(regra == 4){

            printf("\nMedia dos salarios: %d\n\n", media_salarios(x));

        }

        if(regra == 5){

            for(i= 0 ; i < 3 ; i++){
                printf("\n----Funcionario %d----\n", i+1);
                mostra_funcionario(x[i]);
            }

        }



    }while(regra != 6);


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

    printf("\n");
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

int maior_salario(Dados *x){

    int i;
    int sal = 0;
    int p = 0;

    for(i = 0 ; i < 6 ; i++){
        if(x[i].salario > sal){
            sal = x[i].salario;
            p = i;
        }
    }

    return (p+1);
}

int menor_salario(Dados *x){

    int i;
    int salar = 0;
    int p = 0;

    for(i = 0 ; i < 6 ; i++){
        if(x[i].salario < salar){
            salar = x[i].salario;
            p = i;
        }
    }

    return (p+1);
}

int media_salarios(Dados *x){

    int i;
    int soma;

    for(i = 0 ; i < 6 ; i++){
        soma += x[i].salario; 
    }

    return (soma/6);
}
