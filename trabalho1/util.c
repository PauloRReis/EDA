#include "util.h"

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

    novo->id = novo_id(lista);
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
    
    novo->id = novo_id(lista);

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
        printf("Inicio: %d:%d - %d/%d/%d\n", mov->registro.inicio.hora,mov->registro.inicio.minuto,mov->registro.inicio.dia,mov->registro.inicio.mes,mov->registro.inicio.ano);
        printf("Duracao: %d minutos\n", mov->registro.duracao);
        printf("Deadline: %d:%d - %d/%d/%d\n\n", mov->registro.deadline.hora,mov->registro.deadline.minuto,mov->registro.deadline.dia,mov->registro.deadline.mes,mov->registro.deadline.ano);
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

Dados * le_arquivo(Dados * lista){

    Dados * novo = NULL;

    FILE* nome_arq;
    nome_arq = fopen("agenda_exp.txt", "r");

    while(feof(nome_arq) == 0){

        novo = alok();

        fscanf(nome_arq, "%d, ", &novo->id);
        fscanf(nome_arq, "%[^,]s", novo->registro.nome);
        fscanf(nome_arq, ", %d:%d %d/%d/%d", &novo->registro.inicio.hora, &novo->registro.inicio.minuto, &novo->registro.inicio.dia, &novo->registro.inicio.mes, &novo->registro.inicio.ano);
        fscanf(nome_arq, ",%d ", &novo->registro.duracao);
        fscanf(nome_arq, ", %d:%d %d/%d/%d", &novo->registro.deadline.hora, &novo->registro.deadline.minuto, &novo->registro.deadline.dia, &novo->registro.deadline.mes, &novo->registro.deadline.ano);
        novo->prox = NULL;

        lista = insere(lista,novo);
    }

    fclose(nome_arq);

    return (lista);
}

Dados * alok(){

    Dados * novo;

    novo = (Dados *) malloc(sizeof(Dados));

    return (novo);
}

Dados * insere(Dados * lista, Dados * novo){

    Dados * mov = NULL;
    Dados * ant = NULL;

    mov = lista;

    if(mov == NULL){
        return(novo);
    }

    while(mov != NULL){
        ant = mov;
        mov = mov->prox;
    }

    if(mov == NULL){
        ant->prox = novo;
    }

    return(lista);
}

void gera_arq(Dados * lista){

    FILE * p_arq;
    Dados * mov = NULL;

    p_arq = fopen("arquivo_agenda.txt", "w");

    mov = lista;

    while(mov != NULL){

        fprintf(p_arq,"%d, ", mov->id);
        fprintf(p_arq,"%s", mov->registro.nome);
        fprintf(p_arq,", %d:%d %d/%d/%d",mov->registro.inicio.hora, mov->registro.inicio.minuto, mov->registro.inicio.dia, mov->registro.inicio.mes, mov->registro.inicio.ano);
        fprintf(p_arq,", %d", mov->registro.duracao);
        fprintf(p_arq,", %d:%d %d/%d/%d", mov->registro.deadline.hora, mov->registro.deadline.minuto, mov->registro.deadline.dia, mov->registro.deadline.mes, mov->registro.deadline.ano);
        fprintf(p_arq, "\n");

        mov = mov->prox;
    }

    fclose(p_arq);

}

void salva_agend_dia(Dados * lista){

    FILE * arquivo;
    Dados * mov = lista;

    arquivo = fopen("agenda_diaria.txt", "w");

    while(mov != NULL){

        fprintf(arquivo,"%d, ", mov->id);
        fprintf(arquivo,"%s", mov->registro.nome);
        fprintf(arquivo," %d:%d %d/%d/%d, ",mov->registro.inicio.hora, mov->registro.inicio.minuto, mov->registro.inicio.dia, mov->registro.inicio.mes, mov->registro.inicio.ano);
        fprintf(arquivo,"%d,", mov->registro.duracao);
        fprintf(arquivo," %d:%d %d/%d/%d", mov->registro.deadline.hora, mov->registro.deadline.minuto, mov->registro.deadline.dia, mov->registro.deadline.mes, mov->registro.deadline.ano);
        fprintf(arquivo, "\n");
        
        mov = mov->prox;
    }

    fclose(arquivo);

}

Dados * comp_agenda_dia(Dados * lista){

    Dados * agenda_dia = NULL;
    Dados * temp;
    Dados * mov = lista;
    Dados * aux = NULL;
    struct tm *data_atual;
    time_t seg;

    time(&seg);

    data_atual = localtime(&seg);

    while(mov != NULL){
        
        if(mov->registro.inicio.dia == data_atual->tm_mday && mov->registro.inicio.mes == (data_atual->tm_mon+1) && mov->registro.inicio.ano == (data_atual->tm_year+1900)){

            temp = alok();

            temp->id = mov->id;
            strcpy(temp->registro.nome, mov->registro.nome);
            temp->registro.inicio.hora = mov->registro.inicio.hora;
            temp->registro.inicio.minuto = mov->registro.inicio.minuto;
            temp->registro.inicio.dia =  mov->registro.inicio.dia;
            temp->registro.inicio.mes =  mov->registro.inicio.mes;
            temp->registro.inicio.ano =  mov->registro.inicio.ano;
            temp->registro.duracao = mov->registro.duracao;
            temp->registro.deadline.hora = mov->registro.deadline.hora;
            temp->registro.deadline.minuto = mov->registro.deadline.minuto;
            temp->registro.deadline.dia = mov->registro.deadline.hora;
            temp->registro.deadline.mes = mov->registro.deadline.mes;
            temp->registro.deadline.ano = mov->registro.deadline.ano;
            temp->prox = NULL;

            agenda_dia = insere(agenda_dia, temp);
        }

        mov = mov->prox;
    }

    agenda_dia = merge_sort(agenda_dia);

    mov = agenda_dia;
    aux = mov->prox;

    while(aux != NULL){
        
            if(((mov->registro.deadline.hora*60 + mov->registro.deadline.minuto) - mov->registro.duracao) < (aux->registro.deadline.hora*60 + aux->registro.deadline.minuto)){
                agenda_dia = excluir_tarefa(agenda_dia, mov->id);
            }
        
            if((mov->registro.deadline.hora*60+mov->registro.deadline.minuto) == ((aux->registro.deadline.hora*60)+aux->registro.deadline.minuto)){
                if(mov->registro.duracao < aux->registro.duracao){
                    agenda_dia = excluir_tarefa(agenda_dia, aux->id);
                }else{
                    agenda_dia = excluir_tarefa(agenda_dia, mov->id);
                }
            }

        mov = mov->prox;
        aux = aux->prox;
    }

    return(agenda_dia);
}

Dados * merge_sort(Dados * lista){

    Dados * e;
    Dados * d;
    Dados * mid;

    if(lista == NULL || lista->prox == NULL){
        return(lista);
    }
    mid = meio(lista);
    e = merge_sort(lista);
    d = merge_sort(mid);
    lista = merge(e,d);

    return(lista);
}

Dados * meio(Dados * lista){

    Dados * x;
    Dados * y;
    Dados * p;
    x = lista;
    y = lista;

    if(lista == NULL){
        return(lista);
    }

    while(y->prox == NULL){
        y = y->prox;
        
        if(y->prox != NULL){
            x = x->prox;
            y = y->prox;
        }
    }
    
    p = x->prox;
    x->prox = NULL;
    
    return(p);
}

Dados * merge(Dados * e, Dados * d){
    
    Dados * l;
    Dados * p; 
    l = NULL;

    while(e != NULL && d != NULL){
        if((e->registro.deadline.hora*60 + e->registro.deadline.minuto) > (d->registro.deadline.hora*60+d->registro.deadline.minuto)){
            if(l == NULL){
                p = l = e;
                e = e->prox;
            }else{
                p->prox = e;
                e = e->prox;
                p = p->prox;
            }
        }else{
            if(l == NULL){
                p = l = d;
                d = d->prox;
            }else{
                p->prox = d;
                d = d->prox;
                p = p->prox;
            }
        }
    }

    if(e == NULL){
        while(d != NULL){
            p->prox = d;
            d = d->prox;
            p = p->prox;
        }
    }
    if(d == NULL){
        while(e != NULL){
            p->prox = e;
            e = e->prox;
            p = p->prox;
        }
    }

    return(l);
}

int novo_id(Dados * lista){

    Dados * mov = lista;
    int cod = 0;

    if(mov == NULL){
        return (cod);
    }

    while(mov->prox != NULL){
        mov = mov->prox;
    }

    cod = mov->id;

    return (cod+1);
}

void escreve_id(Dados * lista){

    Dados * mov = lista;

    while(mov == NULL){
        mov->id = novo_id(lista);
        mov = mov->prox;
    }

}
