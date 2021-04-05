int profundidade(NO * raiz, int ch){

  if(ch == raiz->chave){
    return (0);
  }

  if(ch > raiz->chave){
    return(1+profundidade(raiz->dir, ch));
  }

  if(ch < raiz->chave){
    return(1+profundidade(raiz->esq, ch));
  }

  return 0;
}

//estrutura
typedef struct aux{
  int chave;
  struct NO *esq;
  struct NO *dir;
}NO;