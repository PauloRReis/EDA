#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int cod;
    char nome[50];
    int salario;
}Dados;

void menu();
void le_funcionario(Dados *x);
void mostra_funcionario(Dados x);
int maior_salario(Dados *x, int n);
int menor_salario(Dados *x, int n);
int media_salarios(Dados *x, int n);

int main(){

    Dados *x = NULL;
    int i;
    int regra = -1;
    int n = 0;
    int pos = 0;

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

            n--;
            x = realloc(x, sizeof(Dados) * n);
            

        }


    }while(regra != 0);


}

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

    return (soma/6);
}
