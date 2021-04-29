#include<stdio.h>
#include<stdlib.h>
#define S 20

int main (){
  
  int v[20] = {0,1,0,2,3,4,0,0,5,6,2,6,7,8,10,11,12,13};
  int i, j;
  int aux;

  for(j = 0; j < 19 ; j++){
    for(i = 0 ; i < 19; i++){
      if(v[i] == 0){
        aux = v[i];
        v[i] = v[i+1];
        v[i+1] = aux;
      }
    }
  }

  for(i=0 ; i < 20;i++){
    printf("%d ", v[i]);
  }

return 0;
}