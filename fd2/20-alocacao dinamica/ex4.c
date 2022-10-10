/**
 * @file 2.c
 * @author luiz fernando rolim vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void matriz(int l, int c);

int main(){
  int l;
  int c;

  printf("Digite dois valores: ");
  scanf("%d""%d",&l,&c);

  matriz(l,c);

  return  0;
}

void matriz(int l, int c){
  int **matriz = malloc(l * sizeof(int*));

  for (int i = 0; i < l; i++){
    matriz[l] = (int*) malloc(4 * sizeof(int));
  }// for

  for(size_t j = 0; j < l; j++){
    for(size_t k = 0; k < c; k++){
      printf("0",matriz[j][k]);
    }
    printf("\n");
  }

  for (int i = 0; i < l; i++){
    free(matriz[l]);
  }// for

  free(matriz);

  return;
}
