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

void funcao(int a[], int b[], int n);

int main(){
  int n;

  printf("Digite um valor: ");
  scanf("%d",&n);

  int a[n];
  int b[n];

  funcao(a,b,n);

  return 0;
}

void funcao(int a[], int b[], int n){
  int *c;
  c = malloc(n * sizeof(int));

  for(int i = 0; i < n; i++){
    c[i] = a[i] * b[i];
    printf("Valor %d do vetor C: %p \n", i+1, c);
  }

  if(c == NULL){
    printf("Erro: Memória Insuficiente!\n");
    exit(1);
  }//if

  free(c);

  return;
}
