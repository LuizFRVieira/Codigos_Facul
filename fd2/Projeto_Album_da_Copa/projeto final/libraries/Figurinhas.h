#ifndef FIGURINHAS_H
#define FIGURINHAS_H

#include <stdlib.h>
#include "main.h"

int conta_figurinhas();
Figurinha *carrega_figurinhas_arquivos();
void atualiza_arquivo(Figurinha figurinha);
void reescreve_arquivo(Figurinha *figurinhas, int count);
Figurinha *deleta_figurinha(Figurinha *figurinhas);
Figurinha* adicionar_figurinha(Figurinha *figurinhaTotais);
void lista_figurinhas(Figurinha *figurinhas);
Figurinha* edita_figurinha(Figurinha *figurinhasTotais);

#endif