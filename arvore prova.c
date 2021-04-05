#include <stdio.h>
#include <stdlib.h>

typedef struct aux{
  int chave;
  struct NO *esq;
  struct NO *dir;
}NO;

NO * adiciona(NO * raiz, NO * no);
NO * cria(int ch);
int profundidade(NO * raiz, int ch);

int main(void) {

  NO * A = NULL;
  NO * aux = NULL;
  int i, n;

  for(i = 0 ; i < 6 ; i++){
    scanf("%d", &n);
    aux = cria(n);
    adiciona(A, aux);
  }




  return 0;
}

NO * adiciona(NO * raiz, NO * no){

  if(raiz == NULL)
    return(no);

  if(no->chave < raiz->chave){
    raiz->esq = adiciona(raiz->esq, no);
  }else{
    raiz->dir = adiciona(raiz->dir, no);
  }

  return(raiz);
}

NO * cria(int ch){
  NO * novo = (NO *) malloc(sizeof(NO));
  novo->esq = NULL;
  novo->dir = NULL;
  novo->chave = ch;
  return(novo);
}

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