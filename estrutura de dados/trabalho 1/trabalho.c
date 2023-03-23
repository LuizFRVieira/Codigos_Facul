/**
 * @file trabalho.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2023-03-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*[Arquivos, Structs, Aloca ̧c ̃ao Dinˆamica e Ponteiros] A empresa Matrix precisa melhorar o sistema de
armazenamento de informa ̧c ̃oes de seus funcion ́arios. MuriNeo, o gerente, entrou em contato contigo e
pediu para que vocˆe seja o respons ́avel por desenvolver este novo sistema.
MuriNeo descreveu que as informa ̧c ̃oes dos funcion ́arios est ̃ao armazenadas em um arquivo denominado
funcionarios.txt e que consta, na primeira linha, um n ́umero que indica a quantidade de funcion ́arios.

Pediu para que se utilizasse estruturas de modo a representar as demais informa ̧c ̃oes, conforme esquema-
tizadas abaixo:

i) CADASTRO: nome, endere ̧co, sal ́ario, estado civil, idade, sexo;
ii) ENDERE  ̧CO: rua, cidade, estado.
Continuou suas explica ̧c ̃oes mostrando que no arquivo funcionarios.txt, a partir da segunda linha, cada
linha cont ́em os dados de um funcion ́ario. As informa ̧c ̃oes dos funcion ́arios est ̃ao dispostas como no
exemplo:
{Persephone Belluci; {Rua Revolutions,12 ; Apucarana; Parana} ; 3200; solteiro; 30; F}
Referente as respectivas informa ̧c ̃oes:

{nome; {rua; cidade; estado} ; sal ́ario ; estado civil ; idade; sexo}
Exemplo de arquivo: encurtador.com.br/nqrMV

1

MuriNeo ainda esclareceu que seu sistema ser ́a compartilhado com outras filiais da empresa que pos-
suem suas informa ̧c ̃oes armazenadas de modo similar, ou seja, cada filial tem seu respectivo quadro de

funcion ́arios (e quantidade tamb ́em!).
O programa dever ́a:
• ordenar por sal ́ario (utilizando o algoritmo Heapsort), em ordem decrescente, imprimir em TELA
e em ARQUIVO.txt o nome o sal ́ario, a idade e o sexo do funcion ́ario (nesta ordem).
Obs 1: Utilizar a main apenas para realizar as chamadas das fun ̧c ̃oes e procedimentos dos itens listados
logo acima (ou seja, n ̃ao de implementar a main gigantesca).
Obs 2: Lembre-se de limpar a mem ́oria antes de encerrar a execu ̧c ̃ao do programa (evitar memory leak).
Vocˆe precisa utilizar aloca ̧c ̃ao dinˆamica de mem ́oria, certo?!
Obs 3: Utilizar passagem de parˆametros (argC e argV) para receber o nome do arquivo de entrada e de
sa ́ıda.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===============ESTRUUTURAS================
typedef struct endereco
{
    char rua[50];
    char cidade[50];
    char estado[50];
} ENDERECO;

typedef struct cadastro
{
    char nome[50];
    ENDERECO endereco;
    float salario;
    char estadoCivil[50];
    int idade;
    char sexo;
} CADASTRO;

// ===============CABEÇALHO================
CADASTRO *lerFuncionarios(char *arquivo, CADASTRO *funcionarios, int *qtdFuncionarios);
void imprimirFuncionarios(CADASTRO *funcionarios, int qtdFuncionarios);
void heapSort(CADASTRO *funcionarios, int qtdFuncionarios);
void heapify(CADASTRO *funcionarios, int qtdFuncionarios, int i);

// ===============MAIN================
int main(int argc, char *argv[])
{
    CADASTRO *funcionarios;
    int qtdFuncionarios;

    // não deixa o programa rodar sem os argumentos
    if (argc != 3)
    {
        printf("Use: %s <funcionarios.txt> <arquivo.txt>\n", argv[0]);
        exit(1);
    }
    // chamada das funções
    funcionarios = lerFuncionarios(argv[1], funcionarios, &qtdFuncionarios);

    heapSort(funcionarios, qtdFuncionarios);

    imprimirFuncionarios(funcionarios, qtdFuncionarios);
    free(funcionarios);

    return 0;
}

// ===============FUNÇÕES  ================

// Essa função lê o arquivo e retorna um vetor de funcionários
CADASTRO *lerFuncionarios(char *arquivo, CADASTRO *funcionarios, int *qtdFuncionarios)
{
    FILE *f = fopen(arquivo, "r");

    if (f == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    // recebe a quantidade de funcionários do arquivo e aloca a memoria do tamnho necessario
    fscanf(f, "%i\n", qtdFuncionarios);
    funcionarios = (CADASTRO *)malloc(sizeof(CADASTRO) * (*qtdFuncionarios));

    for (int i = 0; i < *qtdFuncionarios; i++)
    {
        //{Persephone Belluci; {Rua Revolutions,12 ; Apucarana; Parana} ; 3200; solteiro; 30; F}
        fscanf(f, "{%[^;]; {%[^;]; %[^;]; %[^}]} ; %f; %[^;]; %i; %c}\n", funcionarios[i].nome, funcionarios[i].endereco.rua, funcionarios[i].endereco.cidade, funcionarios[i].endereco.estado, &funcionarios[i].salario, funcionarios[i].estadoCivil, &funcionarios[i].idade, &funcionarios[i].sexo);
    }

    fclose(f);
    return funcionarios;
}

// Essa função imprime os funcionários no arquivo e no terminal
void imprimirFuncionarios(CADASTRO *funcionarios, int qtdFuncionarios)
{
    FILE *f = fopen("ARQUIVO.txt", "w");

    if (f == NULL)
    {
        printf("Erro ao criar arquivo de saída!\n");
        exit(1);
    }
    // imprime no terminal
    printf("Quantidade de funcionários: %d\n", qtdFuncionarios);
    fprintf(f, "Quantidade de funcionários: %d\n", qtdFuncionarios);
    for (int i = 0; i < qtdFuncionarios; i++)
    {
        printf("Nome: %s - Salario: %.2f - Idade: %d - Sexo: %c \n",
               funcionarios[i].nome, funcionarios[i].salario,
               funcionarios[i].idade, funcionarios[i].sexo);
        // imprime no arquivo
        fprintf(f, "Nome: %s - Salario: %.2f - Idade: %d - Sexo: %c \n",
                funcionarios[i].nome, funcionarios[i].salario,
                funcionarios[i].idade, funcionarios[i].sexo);
    }
    fclose(f);
}

// Essas funções são para ordenar o vetor de funcionários utilizando o heapSort
// Função recursiva para ordenar o vetor
void heapify(CADASTRO *funcionarios, int n, int i)
{
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    // faz a comparação dos salários e troca de lugar que foram salvos no vetor
    if (esquerda < n && funcionarios[esquerda].salario < funcionarios[maior].salario)
        maior = esquerda;

    if (direita < n && funcionarios[direita].salario < funcionarios[maior].salario)
        maior = direita;

    if (maior != i)
    {
        CADASTRO temp = funcionarios[i];
        funcionarios[i] = funcionarios[maior];
        funcionarios[maior] = temp;
        // repete a função ate que o vetor esteja ordenado
        heapify(funcionarios, n, maior);
    }
}
// Função que chama a função recursiva
void heapSort(CADASTRO *funcionarios, int n)
{
    // começa a ordenar a partir do meio do vetor
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(funcionarios, n, i);
    // faz a troca de lugar dos salários
    for (int i = n - 1; i >= 0; i--)
    {
        CADASTRO temp = funcionarios[0];
        funcionarios[0] = funcionarios[i];
        funcionarios[i] = temp;
        // repete a função ate que o vetor esteja ordenado
        heapify(funcionarios, i, 0);
    }
}

//===== material de apoio =====
//https://www.geeksforgeeks.org/heap-sort/
//https://www.youtube.com/watch?v=zSYOMJ1E52A&t=101s
//https://www.youtube.com/watch?v=6B2YyPuxItg&t=380s