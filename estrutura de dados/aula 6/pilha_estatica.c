#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 4

typedef struct OBJETO{
    int chave;
}OBJETO;

typedef struct filaEstatica{
    OBJETO fila[N];
    int ini;
    int fim;
    int qtdeElem;

}FILA;

void incializaFila(FILA *f){
    f->ini = f->fim = -1;
    f->qtdeElem =0;
}

bool estaVazia(FILA *f){
    return(f->qtdeElem==0);
}

bool estaCheia(FILA *f){
    return(f->qtdeElem==N);
}

bool insereElemFila(FILA *f,int ch){
    if(estaCheia(f)==true){
        return false;
    }
    if(estaVazia(f)==true){
        f-> fim = f->ini=0;
        f->fila[0].chave = ch;
        f-> qtdeElem++;
        return true;
    }

    f->fim=(f->fim+1)%N;
    f->fila[f->fim].chave = ch;
    f->qtdeElem++;
    
    return true;
}

void removeElemFila(FILA *f){
    if(estaVazia(f)==true){
        printf("\n\n-----------..........nao foi possivel remover o elemento\n\n");
        return;
    }
    f->qtdeElem--;
    f->ini = (f->ini+1)%N;
}

void imprimeFila(FILA *f){
int pos = f->ini;
    for(int i=0;i<f->qtdeElem;i++){
        printf("\n\n[%d] : %d\n\n",i,f->fila[pos].chave);
    }
}

int main(){
    FILA f;
    incializaFila(&f);

    insereElemFila(&f,10);
    insereElemFila(&f,5);
    insereElemFila(&f,3);
    insereElemFila(&f,20);

    removeElemFila(&f);
    return 0;
}