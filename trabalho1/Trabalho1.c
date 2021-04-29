#include "util.h"

int main(){

    Dados * lista = NULL;
    Dados * agenda_dia = NULL;
    int regra=0;
    int cont=0;
    int valor = 0;

    do{

        menu();

        printf("Escolha uma opcao de 1 a 8 do menu: ");
        scanf(" %d", &regra);

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

                printf("\n------Tarefa excluida!!------\n\n");

                break;
            
            case 4:
                
                if(cont == 0){
                    printf("\n\nNenhuma tarefa cadastrada!!!\n\n");
                    break;
                }
                
                editar_tarefa(lista);
                break;

            case 5:

                lista = le_arquivo(lista);

                escreve_id(lista);

                printf("\n------Arquivo carregado!!------\n\n");

                break;

            case 6:

                if(cont == 0){
                    printf("\n\nNenhuma tarefa cadastrada!!!\n\n");
                    break;
                }

                gera_arq(lista);

                printf("\n------Arquivo gerado!!------\n\n");

                break;

            case 7:

                agenda_dia = comp_agenda_dia(lista);

                printf("\n------Agenda do dia computada!!------\n\n");

                break;

            case 8:

                if(agenda_dia == NULL){
                    printf("\n------Nenhuma agenda programada!!-----\n\n");
                }else{
                    salva_agend_dia(agenda_dia);
                    printf("\n------Agenda do dia salva!!------\n\n");
                }

                break;          
        }

        cont++;
    }while(regra != 0);

    free(lista);

    return 0;
}