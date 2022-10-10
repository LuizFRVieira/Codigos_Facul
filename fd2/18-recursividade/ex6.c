#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int funcaox(int a);

int main(){
  setlocale(LC_ALL,"");

  int a;

  printf("Digite um número: ");
  scanf("%d",&a);

  int resultado = funcaox(a);

  printf("Resultado: %d\n",resultado);

  return 0;
}

int funcaox(int a){
  int soma = 0;

  for(a; a > 0; a--){
    soma = soma + a;
  }

  return soma;
}