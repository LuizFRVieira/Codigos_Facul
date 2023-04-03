/**
 * @file Main.c
 * @Luiz Fernando Rolim Vieira, Victor Ramos Bernardes, joão Drummond
 * @brief 
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Main.h"
#include "Figurinhas.h"
#include "Album.h"
#include "Menu.h"
#include "Pacotinho.h"


int main(int argc, char const *argv[])
{
    Figurinha *figurinhaTotais = carrega_figurinhas_arquivos();
    Album *album;

    album = inicializarAlbum();

    printf("Bem vindo ao album de figurinhas do %s!\n", album->nomeUsuario);
    Menu(figurinhaTotais, album);

    return 0;
}
