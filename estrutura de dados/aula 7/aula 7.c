#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//=================structs-===========

typedef struct pessoa{
    int id;
    char nome[50];
    struct pessoa *prox;
    
}OBJETO;

typedef struct filaDinamica{
    OBJETO *ini;
    OBJETO *fim;
    int qtdeElem;
}FILA;

//========= cabeçalho=================
void incializaFila(FILA *f);
bool estaVAzia(FILA*f);
int qtdElementos(FILA *f);
void inserirElemeFila(FILA *f, int id, char nome[]);
void destroiFila(FILA *f);
void imprimeElementos(FILA *f);

//==========main======================

int main(){
    FILA f;
    incializaFila(&f);
    inserirElemeFila(&f,1234,"Tamara");
    inserirElemeFila(&f,5678,"Joao");
    inserirElemeFila(&f,4566,"Livia");
    destroiFila(&f);
    imprimeElementos(&f);


    return 0;
}

//============funções================
void incializaFila(FILA *f){
    f->qtdeElem =0;
    f->fim = f->ini = NULL;

}

bool estaVAzia(FILA*f){
    return(f->qtdeElem==0);
    
}

int qtdElementos(FILA *f){
    return(f->qtdeElem);
}

void inserirElemeFila(FILA *f, int id, char nome[]){
    OBJETO *aux = NULL;
    //alocando memoria para um novo objeto pessoa
    aux = (OBJETO*)malloc(sizeof(OBJETO));
    aux->id = id;
    strcpy(aux->nome,nome);
    aux->prox = NULL;
    //insere um novo obejto na fila
    if (estaVAzia(f) == true){
        f->ini=f->fim=aux;
    }
    else{
        f->fim->prox=aux;
        f->fim = aux;
    }
    f->qtdeElem++;
    

}

void imprimeElementos(FILA *f){
for (OBJETO *aux = f->ini; aux!=NULL, aux=aux->prox){
    printf("\n[id=%d] Nome=[%s]",aux->id,aux->nome);
}
}


void destroiFila(FILA *f){
    OBJETO *aux = NULL;

    while (f->ini!=NULL){
        aux = f->ini;
        f->ini = aux->prox;
        free(aux);
    }
    f->qtdeElem =0;

}