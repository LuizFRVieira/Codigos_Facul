#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>


typedef struct aluno{
    int RA;
    char nome[50];
    struct aluno *prox;
} ALUNO;

typedef struct PilhaDinamica{
    ALUNO *topo;
    int qtdeElem;

} PILHA;

void incializaPilha(PILHA *p){
    p->topo = NULL;
    p->qtdeElem = 0;
}

bool inseElemenPilha(PILHA *p, int RA, char nome[]){
    ALUNO *a =NULL;
    
//Criando um novo elemento do tipo ALUNO
    a=(ALUNO*) malloc(sizeof(ALUNO));
    if (a==NULL) return false;
    a->RA = RA;
    strcpy(a->nome,nome);
    a->prox = p-> topo;

    //colocando o novo elemento na pilha
    p->qtdeElem++;
    p->topo = a;
    

    return true;
}

void qtdemPilha(PILHA *p){
    printf("\n--->>>A qtde de elementos na PILHA e %d <<<---\n",p->qtdeElem);
}

bool estaVazia(PILHA *p){
    return(p->topo==NULL);
}

void DestroiPilha(PILHA *p){
    ALUNO *a = p->topo;
    while(a!=NULL){
        p->topo = a->prox;
        free(a);
        a = p->topo;
    }
    p->qtdeElem = 0;
}

void ImprimePilha(PILHA *p){
    ALUNO *aux ;

   for (aux = p; aux!=NULL; aux =aux->prox ){
    printf("\n Nome=%s -- RA=%d",aux->nome,aux->RA);
   }
   
    
    

    }
int main(){
    PILHA p;
    incializaPilha(&p);
    inseElemenPilha(&p,1234,"Tamara Baldo");
    inseElemenPilha(&p,5678,"Rafael");
    inseElemenPilha(&p,7891,"Lucas");
    inseElemenPilha(&p,3456,"João");
    qtdemPilha(&p);

    ImprimePilha(&p);
    //-----
    DestroiPilha(&p);
    return 0;

}