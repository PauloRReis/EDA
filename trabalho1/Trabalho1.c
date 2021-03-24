#include <stdlib.h>
#include <stdio.h>
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
int verifica_id(Dados * lista, int valor);

int main(){

    Dados * lista = NULL;
    int regra=0;
    int cont=0;
    int valor = 0;

    do{

        menu();

        printf("Escolha uma opcao de 1 a 4 do menu: ");
        scanf(" %d", &regra);

        if(regra != 1 && regra != 2 && regra != 3 && regra != 4 && regra != 0){
            printf("------OPCAO NAO DISPONIVEL------");
        }

        switch(regra){

            case 1:
                
                if(cont == 0){
                    lista = insere_inicio(lista);
                }else{
                    lista = insere_fim(lista);
                }

                break;

            case 2:

                if(cont == 0){
                    printf("\n\nNenhuma tarefa cadastrada!!!\n\n");
                    break;
                }

                visualizar_tarefas(lista);
                printf("-------------------------------\n");
                break;

            case 3:
                
                if(cont == 0){
                    printf("\n\nNenhuma tarefa cadastrada!!!\n\n");
                    break;
                }

                printf("Digite o ID da tarefa a ser removida: ");
                scanf(" %d", &valor);

                lista = excluir_tarefa(lista, valor);
                break;
            
            case 4:
                
                if(cont == 0){
                    printf("\n\nNenhuma tarefa cadastrada!!!\n\n");
                    break;
                }

                editar_tarefa(lista);
                break;
        }

        cont++;
    }while(regra != 0);


    return 0;
}

void menu(){
    printf("|-----------------------------------------|\n");
    printf("|          CADASTRO DE TAREFAS            |\n");
    printf("|_________________________________________|\n");
    printf("|            MENU DE OPCOES               |\n");
    printf("|-----------------------------------------|\n");
    printf("| 1 - INCLUIR NOVA TAREFA                 |\n");
    printf("| 2 - VISUALIZAR TAREFAS CADASTRADAS      |\n");
    printf("| 3 - EXCLUIR TAREFA                      |\n");
    printf("| 4 - EDITAR TAREFA                       |\n");
    printf("| 5 - CARREGAR ARQUIVO DE TAREFAS         |\n");
    printf("| 6 - GERAR ARQUIVO DE TAREFAS            |\n");
    printf("| 7 - COMPUTAR AGENDA DO DIA              |\n");
    printf("| 8 - SALVAR A AGENDA DO DIA              |\n");
    printf("| 0 - SAIR                                |\n");
    printf("|-----------------------------------------|\n");
}

Dados * insere_inicio(Dados * lista){

    Dados * novo = NULL;

    novo = (Dados *) malloc(sizeof(Dados));

    printf("Digite o id: ");
    scanf(" %d", &novo->id);
    printf("Digite o nome da tarefa: ");
    fflush(stdin);
    gets(novo->registro.nome);
    printf("Digite o horario de inicio(H MIN):");
    scanf(" %d %d", &novo->registro.inicio.hora, &novo->registro.inicio.minuto);
    printf("Digite o dia de inicio(D M A): ");
    scanf(" %d %d %d", &novo->registro.inicio.dia, &novo->registro.inicio.mes,&novo->registro.inicio.ano);
    printf("Digite a duracao(em minutos): ");
    scanf(" %d", &novo->registro.duracao);
    printf("Digite a hora da deadline(H MIN): ");
    scanf(" %d %d", &novo->registro.deadline.hora, &novo->registro.deadline.minuto);
    printf("Digite o dia da deadline(D M A): ");
    scanf(" %d %d %d", &novo->registro.deadline.dia, &novo->registro.deadline.mes,&novo->registro.deadline.ano);
    novo->prox = NULL;

    return (novo);
}

Dados * insere_fim(Dados * lista){

    Dados * mov = NULL;
    Dados * novo = NULL;
    Dados * anterior = NULL;

    mov = lista;

    novo = (Dados *) malloc(sizeof(Dados));
    
    printf("Digite o id: ");
    scanf("%d", &novo->id);

    if(verifica_id(lista, novo->id) == 1){
        printf("\nEsse ID ja existe!!!\n\n");
        free(novo);
        return 0;
    }

    printf("Digite o nome da tarefa: ");
    fflush(stdin);
    gets(novo->registro.nome);

    printf("Digite o horario de inicio(H MIN):");
    scanf(" %d %d", &novo->registro.inicio.hora, &novo->registro.inicio.minuto);

    printf("Digite o dia de inicio(D M A): ");
    scanf(" %d %d %d", &novo->registro.inicio.dia, &novo->registro.inicio.mes,&novo->registro.inicio.ano);

    printf("Digite a duracao(em minutos): ");
    scanf(" %d", &novo->registro.duracao);

    printf("Digite a hora da deadline(H MIN): ");
    scanf(" %d %d", &novo->registro.deadline.hora, &novo->registro.deadline.minuto);

    printf("Digite o dia da deadline(D M A): ");
    scanf(" %d %d %d", &novo->registro.deadline.dia, &novo->registro.deadline.mes,&novo->registro.deadline.ano);
    novo->prox = NULL;

    while(mov != NULL){
        anterior = mov;
        mov = mov->prox;
    }

    if(mov == NULL){
        anterior->prox = novo;
    }

    return(lista);
}

void visualizar_tarefas(Dados * lista){

    Dados * mov = NULL;

    mov = lista;

    printf("\n-------------------------------\n\n");
    
    while(mov != NULL){
        printf("ID : %d\n", mov->id);
        printf("Nome: %s\n", mov->registro.nome);
        printf("Inicio: %d:%d %d/%d/%d\n", mov->registro.inicio.hora,mov->registro.inicio.minuto,mov->registro.inicio.dia,mov->registro.inicio.mes,mov->registro.inicio.ano);
        printf("Duracao: %d\n", mov->registro.duracao);
        printf("Deadline: %d:%d %d/%d/%d\n\n", mov->registro.deadline.hora,mov->registro.deadline.minuto,mov->registro.deadline.dia,mov->registro.deadline.mes,mov->registro.deadline.ano);
        mov = mov->prox;
    }

}

Dados * excluir_tarefa(Dados * lista, int valor){

    Dados * mov = NULL;
    Dados * ant = NULL;

    mov = lista;

    if(mov->id == valor){
        return (lista->prox);
    }

    while(mov->id != valor || mov == NULL){
        ant = mov;
        mov = mov->prox;
    }

    if(mov->id == valor){
        ant->prox = mov->prox;
        free(mov);
    }

    if(mov == NULL){
        printf("ID nao encontrado!!!\n");
    }

    return(lista);
}

int editar_tarefa(Dados * lista){

    int vedit = 0;
    int alte = 0;
    Dados * mov = NULL;

    mov = lista;

    printf("Qual o id da tarefa voce deseja editar? ");
    scanf(" %d", &vedit);

    while(mov->id != vedit || mov == NULL){
        mov = mov->prox;
    }

    if(mov->id == vedit){
        
        printf("Qual dos itens voce deseja alterar? \n");
        printf("|1-Nome da tarefa      |\n");
        printf("|2-Horario de inicio   |\n");
        printf("|3-Data do inicio      |\n");
        printf("|4-Duracao             |\n");
        printf("|5-Horario da deadline |\n");
        printf("|6-Data da deadline    |\n");

        scanf("%d", &alte);

        switch(alte){
            
            case 1:
                printf("Digite o novo nome da tarefa: ");
                fflush(stdin);
                gets(mov->registro.nome);
                break;

            case 2:
                printf("Digite o novo horario de inicio(H MIN): ");
                scanf("%d %d", &mov->registro.inicio.hora, &mov->registro.inicio.minuto);
                break;

            case 3:
                printf("Digite o novo dia de inicio(D M A): ");
                scanf("%d %d %d", &mov->registro.inicio.dia, &mov->registro.inicio.mes, &mov->registro.inicio.ano);
                break;

            case 4:
                printf("Digite a duracao: ");
                scanf(" %d", &mov->registro.duracao);
                break;

            case 5:
                printf("Qual o novo horario da deadline(H MIN): ");
                scanf("%d %d", &mov->registro.deadline.hora, &mov->registro.deadline.minuto);
                break;

            case 6:
                printf("Digite o novo dia de deadline(D M A): ");
                scanf("%d %d %d", &mov->registro.deadline.dia, &mov->registro.deadline.mes, &mov->registro.deadline.ano);
                break;

        }
    }

    return 0;
}

int verifica_id(Dados * lista,int valor){

    Dados * mov = NULL;

    mov = lista;

    while(mov->id != valor || mov == NULL){
        mov = mov->prox;
    }

    if(mov->id == valor){
        return 1;
    }

    return 0;
}