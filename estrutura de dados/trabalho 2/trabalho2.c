/**
 * @file trabalho2.c
 * @author Luiz Fernando Rolim Vieira
 * @brief
 * @version 0.1
 * @date 2023-03-26
 *
 * @copyright Copyright (c) 2023
 *
 */
/*Elabore um programa que realize a convers ̃ao de n ́umeros decimais (n ̃ao negativos) para n ́umeros hexa-
decimais usando Pilha Dinˆamica. O programa deve permitir que:

• O usu ́ario digitar um n ́umero decimal (N ≥ 0);
• Efetuar sucessivas divis ̃oes por 16 e armazenar os restos destas divis ̃oes na pilha (veja o esbo ̧co da
ideia na Figura 1);
• Na  ́ultima divis ̃ao, armazenar tamb ́em o quociente que ser ́a o elemento do topo;
• Imprimir a pilha, pois ela conter ́a o valor de N em base hexadecimal.*/

#include <stdio.h>
#include <stdlib.h>

//=================structs=========================

// Definição da estrutura do nó
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Definição da estrutura da pilha
typedef struct Pilha {
    No *topo;
} Pilha;

//=================================================


//==============CABEÇALHO===========================
void incluir(Pilha *p, int valor);
int POP(Pilha *p);
void imprime_hexadecimal(Pilha *p);
//===============================================

//===================MAIN==========================

int main() {
    int decimal, resto;
    Pilha p;        
    p.topo = NULL;  // inicializa a pilha

    system("clear");
    printf("==================================\n");
    printf("Digite um numero decimal: ");
    scanf("%d", &decimal);
    printf("==================================\n");
    


    // se o valor for 0, inclui o valor 0 na pilha
    if (decimal == 0) {
        incluir(&p, 0);
    }

    // Converte decimal para hexadecimal e armazena os restos na pilha
    while (decimal != 0) {
        resto = decimal % 16;
        incluir(&p, resto);
        decimal /= 16;
    }

    imprime_hexadecimal(&p);

    return 0;
}
//=================================================


//================FUNÇÕES=========================

// Função para adicionar um elemento no topo da pilha
void incluir(Pilha *p, int valor) {
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->valor = valor;         // atribui o valor passado como parâmetro ao novo nó
    novo_no->prox = p->topo;        // faz o novo nó apontar para o nó que estava no topo da pilha anteriormente
    p->topo = novo_no;              //atualiza o topo da pilha para o novo nó
}

// Função para remover e retornar o elemento no topo da pilha
int POP(Pilha *p) {
    //confere se a pilha esta vazia
    if (p->topo == NULL) {
        printf("pilha vazia.\n");
        exit(1);
    }

    int valor = p->topo->valor;
    No *temp = p->topo;
    p->topo = p->topo->prox;        // atualiza o topo da pilha para o próximo nó

    free(temp);
    return valor;                   // retorna o valor do nó removido
}

// Função para imprimir os valores em hexadecimal
void imprime_hexadecimal(Pilha *p) {
    printf("==================================\n");

    printf("Valor em hexadecimal: ");
    while (p->topo != NULL) {
        int valor = POP(p);
        if (valor < 10) {                       // se o valor for menor que 10, imprime o valor
            printf("%d", valor);
        } else {
            printf("%c", 'A' + (valor - 10));   // se o valor for maior que 10, imprime o caractere correspondente
        }
    }
    printf("\n");
    printf("==================================\n");

}

// ==================REFERENCIAS:==================================
// https://www.youtube.com/watch?v=vQg_-RqTW8Y&t=12s&ab_channel=SenhorBizu
// https://www.youtube.com/watch?v=Bk2jGg4DT1s&ab_channel=SenhorBizu
// https://www.youtube.com/watch?v=DN2dMIULOQo&ab_channel=HugoO.Fante
// https://www.youtube.com/watch?v=Lbjy17DsRB0&ab_channel=Prof.MURAKAMI-MATEM%C3%81TICARAPIDOLA
