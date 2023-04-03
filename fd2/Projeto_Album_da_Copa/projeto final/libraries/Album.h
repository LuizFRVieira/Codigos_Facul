#ifndef ALBUM_H
#define ALBUM_H

#include <stdlib.h>
#include "main.h"

void iniciarArquivo();
int retornaInt(int index);
Album* inicializarAlbum();
void carrega_figurinhasArquivoProAlbum(Album *album);
void salva_albumArquivo(Album *album);
void mudar_valorTxt(int index, int valor);
void colar_figurinhas(Album *album);
void folhear_album(Figurinha* figurinhasTotais, Album *album);
void mostrar_repetidas(Album *album);
void exportar_csv(Album *album);

#endif