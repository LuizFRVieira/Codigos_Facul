#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int binario(int num);

int main(){
  setlocale(LC_ALL,"");

  int num;

  printf("Digite um número: ");
  scanf("%d",&num);

  int result = binario(num);

  printf("Número %d em binários: %d\n",num,result);

  return 0;
}

int binario(int num){
  if(num == 0){ //caso base
    return 0;
  } else{ //caso recursivo
    return binario(num/2)*10 + num%2;
  }
}