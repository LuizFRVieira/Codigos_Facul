#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Main.h"
#include "Album.h"
#include "Figurinhas.h"


//confere se tem repetidas
int verifica_figurinhaRepetida(Album *album, Figurinha* figurinhaVerificar) {
    for (size_t i = 0; i < album->figurinhasObtidasCount; i++)
    {
        if (strcmp(album->figurinhasObtidas[i].codigo, figurinhaVerificar->codigo) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void abrir_pacotinho(Album *album, Figurinha* figurinhasTotais) {
    int quantidade, figurinhaObtida, indiceAux = 0;
    Figurinha *figurinhaTemp;
    printf("Insira a quantidade pacotinhos voce quer comprar e abrir: ");
    scanf("%d", &quantidade);

    figurinhaTemp = (Figurinha*) malloc(sizeof(Figurinha) * quantidade * 5);


    srand(time(NULL));
    for (size_t i = 0; i < quantidade; i++)
    {
        for (size_t i = 0; i < 5; i++)
        {            
            figurinhaObtida = rand() % conta_figurinhas();
            //confere se é reptida
            if(verifica_figurinhaRepetida(album, &figurinhasTotais[figurinhaObtida])) {
                album->figurinhasRepetidasCount++;
                album->figurinhasRepetidas = (Figurinha*) realloc(album->figurinhasRepetidas, sizeof(Figurinha) * album->figurinhasRepetidasCount);
                album->figurinhasRepetidas[album->figurinhasRepetidasCount - 1] = figurinhasTotais[figurinhaObtida];
                printf("Voce obteve uma figurinha repetida: %s - %s - %s - %s\n", figurinhasTotais[figurinhaObtida].codigo, figurinhasTotais[figurinhaObtida].nome, figurinhasTotais[figurinhaObtida].secao, figurinhasTotais[figurinhaObtida].tipo);
                mudar_valorTxt(1, album->figurinhasRepetidasCount);
            } else { // vai por nas figurinhas obtidas
                album->figurinhasObtidasCount++;
                album->figurinhasObtidas = (Figurinha*) realloc(album->figurinhasObtidas, sizeof(Figurinha) * album->figurinhasObtidasCount);
                album->figurinhasObtidas[album->figurinhasObtidasCount - 1] = figurinhasTotais[figurinhaObtida];
                printf("Voce obteve uma figurinha nova: %s - %s - %s - %s\n", figurinhasTotais[figurinhaObtida].codigo, figurinhasTotais[figurinhaObtida].nome, figurinhasTotais[figurinhaObtida].secao, figurinhasTotais[figurinhaObtida].tipo);
                mudar_valorTxt(0, album->figurinhasObtidasCount);

                figurinhaTemp[indiceAux] = figurinhasTotais[figurinhaObtida];
                indiceAux++;
            }
        }
    }

    printf("Você deseja colar todas suas figurinhas obtidas? (1 - Sim, 2 - Não): ");
    scanf("%d", &quantidade);

    if (quantidade == 1) { // vai colar
        for (size_t i = 0; i < indiceAux; i++)
        {
            album->figurinhasColadasCount++;
            album->figurinhasColadas = (Figurinha*) realloc(album->figurinhasColadas, sizeof(Figurinha) * album->figurinhasColadasCount);
            album->figurinhasColadas[album->figurinhasColadasCount - 1] = figurinhaTemp[i];
            mudar_valorTxt(2, album->figurinhasColadasCount);
        }
    }
    else{// colocar pra colar
        for (size_t i = 0; i < indiceAux; i++)
        {
            album->figurinhasParaColarCount++;
            album->figurinhasParaColar = (Figurinha*) realloc(album->figurinhasParaColar, sizeof(Figurinha) * album->figurinhasParaColarCount);
            album->figurinhasParaColar[album->figurinhasParaColarCount - 1] = figurinhaTemp[i];
            mudar_valorTxt(3, album->figurinhasParaColarCount);
        }
    }
    for(size_t i = 0; i < indiceAux; i++) {
        free(&figurinhaTemp[i]);
    }
    salva_albumArquivo(album);
}