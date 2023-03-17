#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 10
//===========STRUCTS=======
typedef struct
{
    int RA;
    char nome[20];
} ALUNO;

typedef struct
{
    ALUNO Alunos[N];
    int topo;
} PILHA;
// ========================

// ===========CABEÇALHO===========
void InicializaPilha(PILHA *P);
bool EstaVazia(PILHA *P);
bool EstaCheia(PILHA *P);
bool InserePilha(PILHA *P, int RA, char nome[100]);
void ImprimePilha(PILHA *P);
bool Desempilha(PILHA *P);
// ================================

//=======MAIN=============
int main(void){
    PILHA P;
    InicializaPilha(&P);

    InserePilha(&P, 1234, "murilo Garrido");
    InserePilha(&P, 4312, "Marcos Tadao");
    InserePilha(&P, 5671, "Vitor viana");
    InserePilha(&P, 4312, "Maria Eduarda");

    ImprimePilha(&P);
    Desempilha(&P);
    printf("\n -->TOPO - %d\n", P.topo);
    return 0;
}

//===============FUNÇÕES==============
void InicializaPilha(PILHA *P){
    P->topo = 0;
}

bool EstaVazia(PILHA *P){
    return (P->topo == 0);
}

bool EstaCheia(PILHA *P){
    return (P->topo >= N);
}

bool InserePilha(PILHA *P, int RA, char nome[100]){
    if (EstaCheia(P) == true)
        return false;

    strcpy(P->Alunos[P->topo].nome, nome);
    P->Alunos[P->topo].RA = RA;

    P->topo++;
    return true;
}

void ImprimePilha(PILHA *P){
    if (EstaVazia(P)==true){
        printf("A pilha esta vazia");
        return;
    }
    for (int i = P->topo-1 ; i>=0 ; i--){
        printf("\n [posicao= %d] RA =%d NOME = %s",i,P->Alunos[i].RA,P->Alunos[i].nome);
        printf("\n");
    }
        printf("\n\n");   

}

bool Desempilha(PILHA *P){
    if (EstaVazia(P)== true) return false;

    P->topo --;
    return true;

}


//====================================
