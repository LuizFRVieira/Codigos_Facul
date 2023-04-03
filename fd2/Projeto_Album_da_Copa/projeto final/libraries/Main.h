#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>


typedef struct {
   char codigo[10];
   char nome[50];
   char secao[50];
   char tipo[20];
} Figurinha;

typedef struct {
    Figurinha *figurinhasColadas;
    Figurinha *figurinhasFaltantes;
    Figurinha *figurinhasParaColar;
    Figurinha *figurinhasRepetidas;
    Figurinha *figurinhasObtidas;
    int figurinhasColadasCount;
    int figurinhasFaltantesCount;
    int figurinhasParaColarCount;
    int figurinhasRepetidasCount;
    int figurinhasObtidasCount;
    int pacoteFigurinha;
    char nomeUsuario[50];
    char telefoneUsuario[50];
} Album;

#endif