#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Main.h"
#include "Menu.h"
#include "Figurinhas.h"
#include "Album.h"
#include "Pacotinho.h"

void Menu(Figurinha *figurinhaTotais, Album *album) {
    int opcao;

    printf("Menu do album de figurinhas\n1 - Editar figurinhas\n2 - Comprar pacotinhos\n3 - Editar album\n4 - Exportar CSV do album\n0 - Sair do Programa e Salvar Tudo\nInsira sua opcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        system("cls");
        MenuFigurinha(figurinhaTotais, album);
        Menu(figurinhaTotais, album);
        break;
    case 2:
        system("cls");
        abrir_pacotinho(album, figurinhaTotais);
        system("cls");
        Menu(figurinhaTotais, album);
        break;
    case 3:
        system("cls");
        MenuAlbum(figurinhaTotais, album);
        Menu(figurinhaTotais, album);
        break;
    case 4:
        system("cls");
        exportar_csv(album);
        Menu(figurinhaTotais, album);
        break;
    case 0:
        system("cls");
        printf("Saindo do programa e salvando tudo\n");
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
}

void MenuAlbum(Figurinha *figurinhaTotais, Album *album) { 
    printf("Menu do album de figurinhas\n1 - Folhear o album\n2 - Ver figurinhas repetidas\n3 - Colar figurinhas\n0 - Voltar para o menu principal\nInsira sua opcao: ");

    int opcao;
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        system("cls");
        folhear_album(figurinhaTotais, album);
        MenuAlbum(figurinhaTotais, album);
        break;
    case 2:
        system("cls");
        mostrar_repetidas(album);
        MenuAlbum(figurinhaTotais, album);
        break;
    case 3:
        system("cls");
        colar_figurinhas(album);
        MenuAlbum(figurinhaTotais, album);
        break;
    case 0:
        system("cls");
        Menu(figurinhaTotais, album);
        break;  
    default:
        printf("Opcao invalida!\n");
        MenuAlbum(figurinhaTotais, album);
        break;
    }
}

void MenuFigurinha(Figurinha *figurinhaTotais, Album *album) {
    int opcao;

    printf("Menu das figurinhas\n1 - Adicionar figurinha\n2 - Editar figurinha\n3 - Deletar figurinha\n4 - Listar figurinhas\n0 - Voltar para o menu principal\nInsira sua opcao: ");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        system("cls");
        figurinhaTotais = adicionar_figurinha(figurinhaTotais);
        system("cls");
        MenuFigurinha(figurinhaTotais, album);
        break;
    case 2:
        system("cls");
        figurinhaTotais = edita_figurinha(figurinhaTotais);
        system("cls");
        MenuFigurinha(figurinhaTotais, album);
        break;
    case 3:
        system("cls");
        figurinhaTotais = deleta_figurinha(figurinhaTotais);
        system("cls");
        MenuFigurinha(figurinhaTotais, album);
        break;
    case 4:
        system("cls");
        lista_figurinhas(figurinhaTotais);
        system("cls");
        MenuFigurinha(figurinhaTotais, album);
        break;
    case 0:
        system("cls");
        Menu(figurinhaTotais, album);
        system("cls");
        break;
    default:
        printf("Opcao invalida!\n");
        MenuFigurinha(figurinhaTotais, album);
        break;
    }
}