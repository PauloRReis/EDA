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