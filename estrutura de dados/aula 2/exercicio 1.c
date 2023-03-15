#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char marca[20];
    char modelo[20];
    char cor[20];
    int ano;
    int km_rodado;
    int valor;
    int codigo;
} CARRO;

void incializa_carro(CARRO *c)
{
    printf("Digite a marca : \n");
    scanf("%s", c->marca);
    fflush(stdin);

    printf("Digite o Modelo : \n");
    scanf("%s", c->modelo);
    fflush(stdin);

    printf("Digite a km rodadas : \n");
    scanf("%d", &c->km_rodado);
    fflush(stdin);

    printf("Digite o ano : \n");
    scanf("%d", &c->ano);
    fflush(stdin);

    printf("Digite a cor : \n");
    scanf("%s", c->cor);
    fflush(stdin);

    printf("Digite a valor : \n");
    scanf("%d", &c->valor);
    fflush(stdin);
}

void Imprime(CARRO c)
{
    printf("Marca : %s\n", c.marca);
    printf("Modelo : %s\n", c.modelo);
    printf("Km_rodado : %s\n", c.km_rodado);
    printf("Ano : %d\n", c.ano);
    printf("cor : %s\n", c.cor);
    printf("Valor %s\n", c.valor);
}

int main()
{
    CARRO c;
    system("clear");
    incializa_carro(&c);
    system("clear");
    Imprime (c);

    return 0;
}