/**
 * @file exercicio 3.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Escreva um procedimento que recebe por parâmetro as 3 notas de um aluno e uma letra. Se a letra for A, 
o procedimento calcula a média aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2) e se for S, 
a soma das notas. O valor calculado também deve ser retornado e exibido na função main. */
#include <stdio.h>
#include <stdlib.h>

float Matematica(char op, float n1, float n2, float n3) {
switch(op) {
    case 'A':
    case 'a':
    return (n1 + n2 + n3) / 3;
    break;
    case 'B':
    case 'b':
    return (n1 * 5 + n2 * 3 + n3 *2) / 10;
    break;
    case 'C':
    case 'c':
    return n1 + n2 + n3;
    break;
}
return 0;
}

int main() {
float n1 = 0, n2 = 0, n3 = 0;


printf("Insira as 3 notas (1 a 10): ");
scanf("%f %f %f", &n1, &n2, &n3);
while(n1 > 10  || n1 < 0) {
    printf("Insira a nota 1 novamente: ");
    scanf("%f", &n1);
}
while(n2 > 10  || n2 < 0) {
    printf("Insira a nota 2 novamente: ");
    scanf("%f", &n2);
}
while(n3 > 10 || n3 < 0) {
    printf("Insira a nota 3 novamente: ");
    scanf("%f", &n3);
}

printf("Operaçoes:\nA - Média aritmética das notas\nB - Média ponderada, sendo a 1° nota peso 5, a 2° nota peso 3 e a 3° nota peso 2\nC - Soma de todas as notas\n\nInsira o caractére de operaç?o: ");
setbuf(stdin,NULL);
char op = getchar();
printf("Resultado: %.2f", Matematica(op, n1, n2, n3));
return 0;
}