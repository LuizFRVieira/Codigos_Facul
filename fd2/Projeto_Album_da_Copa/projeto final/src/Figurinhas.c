#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Main.h"
#include "Figurinhas.h"

int conta_figurinhas() {
    FILE *file = fopen("database/figurinhas_sem_acento.csv", "r");
    char aux;
    int count = 1;
    while((aux = fgetc(file)) !=  EOF) {
        if(aux == '\n') count++;
    }
    fclose(file);
    return count;
}

Figurinha *carrega_figurinhas_arquivos() {
    Figurinha *figurinhaTotais = (Figurinha*) malloc(conta_figurinhas() * sizeof(Figurinha));
    FILE *file = fopen("database/figurinhas_sem_acento.csv", "r");

    for (size_t i = 0; i < conta_figurinhas(); i++)
    {
        fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", figurinhaTotais[i].codigo, figurinhaTotais[i].nome, figurinhaTotais[i].secao, figurinhaTotais[i].tipo);

    }
    return figurinhaTotais;
}

void atualiza_arquivo(Figurinha figurinha) {
    FILE *file = fopen("database/figurinhas_sem_acento.csv", "a");
    fprintf(file, "\n%s,%s,%s,%s", figurinha.codigo, figurinha.nome, figurinha.secao, figurinha.tipo);
    fclose(file);
}

void reescreve_arquivo(Figurinha *figurinhas, int count) {
    FILE *file = fopen("database/figurinhas_sem_acento.csv", "w");
    for (size_t i = 0; i < count; i++)
    {
        fprintf(file, "%s,%s,%s,%s", figurinhas[i].codigo, figurinhas[i].nome, figurinhas[i].secao, figurinhas[i].tipo);
        if(i != count - 1) fprintf(file, "\n");
    }
    fclose(file);
}

Figurinha *deleta_figurinha(Figurinha *figurinhas) {
    char codigo[10];

    printf("Digite o codigo da figurinha que deseja deletar: ");
    setbuf(stdin, NULL);
    fgets(codigo, 10, stdin);
    codigo[strlen(codigo) - 1] = '\0';

    int count = conta_figurinhas();
    int index = -1;

    for (size_t i = 0; i < count; i++)
    {
        if(strcmp(figurinhas[i].codigo, codigo) == 0) {
            index = i;
            break;
        }
    }

    for (size_t i = index; i < count - 1; i++)
    {
        strcpy(figurinhas[i].codigo, figurinhas[i + 1].codigo);
        strcpy(figurinhas[i].nome, figurinhas[i + 1].nome);
        strcpy(figurinhas[i].secao, figurinhas[i + 1].secao);
        strcpy(figurinhas[i].tipo, figurinhas[i + 1].tipo);
    }

    if(index != -1) {
        figurinhas = (Figurinha*) realloc(figurinhas, (count - 1) * sizeof(Figurinha));
        reescreve_arquivo(figurinhas, count - 1);
    }

    if(index == -1) printf("Figurinha nao encontrada!\n");
    return figurinhas;
}

Figurinha* adicionar_figurinha(Figurinha *figurinhaTotais) {
    Figurinha aux;
    printf("Digite o codigo da figurinha: ");
    setbuf(stdin, NULL);
    fgets(aux.codigo, 10, stdin);
    aux.codigo[strlen(aux.codigo) - 1] = '\0';

    printf("Digite o nome da figurinha: ");
    setbuf(stdin, NULL);
    fgets(aux.nome, 50, stdin);
    aux.nome[strlen(aux.nome) - 1] = '\0';

    printf("Digite a secao da figurinha: ");
    setbuf(stdin, NULL);
    fgets(aux.secao, 20, stdin);
    aux.secao[strlen(aux.secao) - 1] = '\0';

    printf("Digite o tipo da figurinha: ");
    setbuf(stdin, NULL);
    fgets(aux.tipo, 10, stdin);
    aux.tipo[strlen(aux.tipo) - 1] = '\0';

    atualiza_arquivo(aux);
    
    figurinhaTotais = realloc(figurinhaTotais, conta_figurinhas() * sizeof(Figurinha));
    figurinhaTotais[conta_figurinhas() - 1] = aux;

    return figurinhaTotais;
}

void lista_figurinhas(Figurinha *figurinhas) {
    for (size_t i = 0; i < conta_figurinhas(); i++)
    {
        printf("%s,%s,%s,%s\n", figurinhas[i].codigo, figurinhas[i].nome, figurinhas[i].secao, figurinhas[i].tipo);
    }
}

Figurinha* edita_figurinha(Figurinha *figurinhasTotais) {
    char codigo[10];
    printf("Digite o codigo da figurinha que deseja editar: ");
    setbuf(stdin, NULL);
    fgets(codigo, 10, stdin);
    codigo[strlen(codigo) - 1] = '\0';

    for (size_t i = 0; i < conta_figurinhas(); i++)
    {   
        if(!strcmp(codigo, figurinhasTotais[i].codigo)) {
            printf("Digite o novo nome da figurinha: ");
            setbuf(stdin, NULL);
            fgets(figurinhasTotais[i].nome, 50, stdin);
            figurinhasTotais[i].nome[strlen(figurinhasTotais[i].nome) - 1] = '\0';

            printf("Digite a nova secao da figurinha: ");
            setbuf(stdin, NULL);
            fgets(figurinhasTotais[i].secao, 50, stdin);
            figurinhasTotais[i].secao[strlen(figurinhasTotais[i].secao) - 1] = '\0';

            printf("Digite o novo tipo da figurinha: ");
            setbuf(stdin, NULL);
            fgets(figurinhasTotais[i].tipo, 20, stdin);
            figurinhasTotais[i].tipo[strlen(figurinhasTotais[i].tipo) - 1] = '\0';

            reescreve_arquivo(figurinhasTotais, conta_figurinhas());
            return figurinhasTotais;
        }
    }
    printf("Não foi encontrada nenhuma figurinha com esse codigo!\n");
    return figurinhasTotais;
}
