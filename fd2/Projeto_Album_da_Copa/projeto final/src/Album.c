// adiciona as blibiotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Main.h"
#include "Album.h"
#include "Figurinhas.h"
#include "Cores.h"

// incia o arquivo pela primeira vez
void iniciarArquivo()
{
    FILE *arquivo, *file;
    char Nome[50], Telefone[50];

    arquivo = fopen("database/album/album.txt", "w");
    fprintf(arquivo, "0 0 0 0 0");
    fclose(arquivo);
    // arquivo pra obtidas
    file = fopen("database/album/obtidas.dat", "wb");
    // arquivo pra repitidas
    file = fopen("database/album/repetidas.dat", "wb");

    file = fopen("database/album/coladas.dat", "wb");

    file = fopen("database/album/paraColar.dat", "wb");

    file = fopen("database/album/faltantes.dat", "wb");
    // por se o ultime sobreescreve
    file = fopen("database/album/infos.txt", "w");

    // pega os dados do usuario
    printf("Qual o seu nome: ");
    setbuf(stdin, NULL);
    fgets(Nome, 50, stdin);
    Nome[strlen(Nome) - 1] = '\0';

    printf("Qual o seu telefone: ");
    setbuf(stdin, NULL);
    fgets(Telefone, 50, stdin);
    Telefone[strlen(Telefone) - 1] = '\0';

    fprintf(file, "%s,%s,", Nome, Telefone);

    fclose(file);
}
// pegar os tamanhos do vetores salvos no txt vulgo 0000
int retornaInt(int index)
{
    FILE *file = fopen("database/album/album.txt", "r");

    if (file == NULL)
    {
        fclose(file);
        iniciarArquivo();
        file = fopen("database/album/album.txt", "r");
    }

    int Obtidas, Repetidas, Coladas, paraColar, Faltantes;
    // le o tamanho do vetor no arquivo txt
    fscanf(file, "%d %d %d %d %d", &Obtidas, &Repetidas, &Coladas, &paraColar, &Faltantes);
    fclose(file);

    switch (index)
    {
    case 0:
        return Obtidas;
        break;
    case 1:
        return Repetidas;
        break;
    case 2:
        return Coladas;
        break;
    case 3:
        return paraColar;
        break;
    case 4:
        return Faltantes;
        break;
    default:
        return -1;
        break;
    }
}
// edita o tamanho do vetor no txt
void mudar_valorTxt(int index, int valor)
{
    FILE *file = fopen("database/album/album.txt", "r");

    int Obtidas, Repetidas, Coladas, paraColar, Faltantes;
    fscanf(file, "%d %d %d %d %d", &Obtidas, &Repetidas, &Coladas, &paraColar, &Faltantes);
    fclose(file);

    switch (index)
    {
    case 0:
        Obtidas = valor;
        break;
    case 1:
        Repetidas = valor;
        break;
    case 2:
        Coladas = valor;
        break;
    case 3:
        paraColar = valor;
        break;
    case 4:
        Faltantes = valor;
        break;
    default:
        break;
    }

    file = fopen("database/album/album.txt", "w");
    fprintf(file, "%d %d %d %d %d", Obtidas, Repetidas, Coladas, paraColar, Faltantes);
    fclose(file);
}

// le todos os arquivos
Album *inicializarAlbum()
{
    char Nome[50], Telefone[50];
    FILE *file = fopen("database/album/infos.txt", "r");
    Album *album = (Album *)malloc(sizeof(Album));

    // aloca o tamanho das figurinhas
    album->figurinhasObtidasCount = retornaInt(0);
    album->figurinhasRepetidasCount = retornaInt(1);
    album->figurinhasColadasCount = retornaInt(2);
    album->figurinhasParaColarCount = retornaInt(3);
    album->figurinhasFaltantesCount = retornaInt(4);

    album->figurinhasObtidas = (Figurinha *)malloc(retornaInt(0) * sizeof(Figurinha));
    album->figurinhasRepetidas = (Figurinha *)malloc(retornaInt(1) * sizeof(Figurinha));
    album->figurinhasColadas = (Figurinha *)malloc(retornaInt(2) * sizeof(Figurinha));
    album->figurinhasParaColar = (Figurinha *)malloc(retornaInt(3) * sizeof(Figurinha));
    album->figurinhasFaltantes = (Figurinha *)malloc(retornaInt(4) * sizeof(Figurinha));
    carrega_figurinhasArquivoProAlbum(album);

    fscanf(file, "%[^,],%[^,],", Nome, Telefone);
    fclose(file);

    strcpy(album->nomeUsuario, Nome);
    strcpy(album->telefoneUsuario, Telefone);

    return album;
}
// pegar que ta no arquivo e colocar no album
void carrega_figurinhasArquivoProAlbum(Album *album)
{
    FILE *file = fopen("database/album/obtidas.dat", "rb");
    fread(album->figurinhasObtidas, sizeof(Figurinha), retornaInt(0), file);

    file = fopen("database/album/repetidas.dat", "rb");
    fread(album->figurinhasRepetidas, sizeof(Figurinha), retornaInt(1), file);

    file = fopen("database/album/coladas.dat", "rb");
    fread(album->figurinhasColadas, sizeof(Figurinha), retornaInt(2), file);

    file = fopen("database/album/paraColar.dat", "rb");
    fread(album->figurinhasParaColar, sizeof(Figurinha), retornaInt(3), file);

    file = fopen("database/album/faltantes.dat", "rb");
    fread(album->figurinhasFaltantes, sizeof(Figurinha), retornaInt(4), file);
    fclose(file);
}

// pegar o que ta no album e por no arquivo
void salva_albumArquivo(Album *album)
{
    FILE *file = fopen("database/album/obtidas.dat", "w+b");
    fwrite(album->figurinhasObtidas, sizeof(Figurinha), retornaInt(0), file);

    file = fopen("database/album/repetidas.dat", "w+b");
    fwrite(album->figurinhasRepetidas, sizeof(Figurinha), retornaInt(1), file);

    file = fopen("database/album/coladas.dat", "w+b");
    fwrite(album->figurinhasColadas, sizeof(Figurinha), retornaInt(2), file);

    file = fopen("database/album/paraColar.dat", "w+b");
    fwrite(album->figurinhasParaColar, sizeof(Figurinha), retornaInt(3), file);

    file = fopen("database/album/faltantes.dat", "w+b");
    fwrite(album->figurinhasFaltantes, sizeof(Figurinha), retornaInt(4), file);
    fclose(file);
}

void colar_figurinhas(Album *album)
{
    int index = -1;
    char codigo[10];

    if (album->figurinhasParaColarCount == 0)
    {
        printf("Nao ha figurinhas para colar!\n");
        return;
    }

    printf("Figurinhas para colar:\n");

    for (int i = 0; i < album->figurinhasParaColarCount; i++)
    {
        printf("%s - %s\n", album->figurinhasParaColar[i].codigo, album->figurinhasParaColar[i].nome);
    }

    printf("\nDigite o codigo da figurinha que deseja colar: ");

    setbuf(stdin, NULL);
    fgets(codigo, 10, stdin);
    codigo[strlen(codigo) - 1] = '\0';

    // compra se a fugrinha existe
    for (int i = 0; i < album->figurinhasParaColarCount; i++)
    {
        if (!strcmp(codigo, album->figurinhasParaColar[i].codigo))
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Figurinha nao encontrada!\n");
        return;
    }
    // caso exista, coloca no album
    album->figurinhasColadasCount++;
    album->figurinhasParaColarCount--;
    album->figurinhasColadas = (Figurinha *)realloc(album->figurinhasColadas, album->figurinhasColadasCount * sizeof(Figurinha));
    album->figurinhasColadas[album->figurinhasColadasCount - 1] = album->figurinhasParaColar[index];
    mudar_valorTxt(2, album->figurinhasColadasCount);
    mudar_valorTxt(3, album->figurinhasParaColarCount);

    salva_albumArquivo(album);
}

// folhar o album
void folhear_album(Figurinha *figurinhasTotais, Album *album)
{
    char Paginas[37][50] = {"Content", "Stadiums", "Official Match Ball", "Qatar", "Ecuador", "Senegal", "Netherlands", "England", "Iran", "USA", "Wales", "Argentina", "Saudi Arabia", "Mexico", "Poland", "France", "Australia", "Denmark", "Tunisia", "Spain", "Costa Rica", "Germany", "Japan", "Belgium", "Canada", "Morocco", "Croatia", "Brazil", "Serbia", "Switzerland", "Cameroon", "Portugal", "Ghana", "Uruguay", "Korea Republic", "FIFA Museum", "CocanormalCola Team Believers"};
    int pagina = 0, opcao, controle;
    // cada char é uma pagina
    // content e o 0;

    while (opcao != -1)
    {
        system("cls");
        printf("\nPagina atual: %s\nFigurinhas desta pagina:\n", Paginas[pagina]);
        for (size_t i = 0; i < conta_figurinhas(); i++)
        {
            if (!strcmp(figurinhasTotais[i].secao, Paginas[pagina]))
            {
                controle = 0;
                for (size_t j = 0; j < album->figurinhasColadasCount; j++)
                {
                    if (!strcmp(figurinhasTotais[i].codigo, album->figurinhasColadas[j].codigo))
                    {
                        controle = 1;
                        break;
                    }
                }
                if (controle)
                {
                    Verde(figurinhasTotais[i].codigo);
                    Verde(" - ");
                    Verde(figurinhasTotais[i].nome);
                    Verde(" - ");
                    Verde(figurinhasTotais[i].secao);
                    Verde(" - ");
                    Verde(figurinhasTotais[i].tipo);
                    printf("\n");
                }
                else
                {
                    Vermelho(figurinhasTotais[i].codigo);
                    Vermelho(" - ");
                    Vermelho(figurinhasTotais[i].nome);
                    Vermelho(" - ");
                    Vermelho(figurinhasTotais[i].secao);
                    Vermelho(" - ");
                    Vermelho(figurinhasTotais[i].tipo);
                    printf("\n");
                }
            }
        }

        printf("\n1 - Proxima página\n2 - Página anterior\n3 - Voltar ao menu\nInsira sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {

            pagina++;
            if (pagina == 37)
            {
                pagina = 0;
            }
        }
        else if (opcao == 2)
        {

            pagina--;
            if (pagina == -1)
            {
                pagina = 36;
            }
        }
        else if (opcao == 3)
        {

            return;
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    }
}

// printar o vetor que ta no vetor de repitidas
void mostrar_repetidas(Album *album)
{
    printf("FIgurinhas repetidas:\n");
    for (size_t i = 0; i < album->figurinhasRepetidasCount; i++)
    {
        printf("%s - %s - %s - %s\n", album->figurinhasRepetidas[i].codigo, album->figurinhasRepetidas[i].nome, album->figurinhasRepetidas[i].secao, album->figurinhasRepetidas[i].tipo);
    }
}

void exportar_csv(Album *album)
{
    FILE *file = fopen("album.csv", "w");

    fprintf(file, "Album de figurinhas!\nFigurinhas obtidas:\n");
    for (size_t i = 0; i < album->figurinhasObtidasCount; i++)
    {
        fprintf(file, "%s - %s - %s - %s\n", album->figurinhasObtidas[i].codigo, album->figurinhasObtidas[i].nome, album->figurinhasObtidas[i].secao, album->figurinhasObtidas[i].tipo);
    }
    fprintf(file, "Figurinhas repetidas:\n");
    for (size_t i = 0; i < album->figurinhasRepetidasCount; i++)
    {
        fprintf(file, "%s - %s - %s - %s\n", album->figurinhasRepetidas[i].codigo, album->figurinhasRepetidas[i].nome, album->figurinhasRepetidas[i].secao, album->figurinhasRepetidas[i].tipo);
    }
    fprintf(file, "Figurinhas para colar:\n");
    for (size_t i = 0; i < album->figurinhasParaColarCount; i++)
    {
        fprintf(file, "%s - %s - %s - %s\n", album->figurinhasParaColar[i].codigo, album->figurinhasParaColar[i].nome, album->figurinhasParaColar[i].secao, album->figurinhasParaColar[i].tipo);
    }
    fprintf(file, "Figurinhas coladas:\n");
    for (size_t i = 0; i < album->figurinhasColadasCount; i++)
    {
        fprintf(file, "%s - %s - %s - %s\n", album->figurinhasColadas[i].codigo, album->figurinhasColadas[i].nome, album->figurinhasColadas[i].secao, album->figurinhasColadas[i].tipo);
    }
    fclose(file);
}