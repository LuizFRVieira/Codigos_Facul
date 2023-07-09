/**
 * @file trabalho3e4.c
 * @Luiz Fernando Rolim Vieira, a2419939
 * @Queise Élen Santos Santana, a2207257
 * @brief
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// cliente
typedef struct cliente{
    char NOME[61];
    char DIA[10];
    char MES[10];
    char ANO[10];
    char DOENCA[21];
} CLIENTE;

// nó
typedef struct no{
    struct no *anterior;
    CLIENTE Clt;
    struct no *proximo;
} NO;

//NoFila
typedef struct No {
    char cliente[100];
    struct No* next;
}NoFila;

//Fila
typedef struct fila {
    NoFila* inicio;
    NoFila* fim;
}Fila;

//========CABEÇALHO=======
CLIENTE cadastrar_cliente(CLIENTE cliente);
void inserir_ordenando(NO **lista, CLIENTE cliente);
void ler_cadastro(char *arquivo, NO **lista);
void arquivo_ordenado(NO *no);
void alterar_cliente(NO *lista, char *arquivo);
void buscar_cliente(NO *lista, char *arquivo);
void Le_espera(char *arquivo, NO *lista);
int confere_idade(char pessoa[]);
void imprime_espera(char *arquivo);
void liberarMemoriaFila(Fila* fila);
void limpa_tela();



void inicializarFila(Fila* fila);
int filaVazia(Fila* fila);
void enfileirar(Fila* fila, const char* cliente);
char* desenfileirar(Fila* fila);
void lerListaEspera(Fila* fila);
void proximoBuffet(Fila* fila);
//void atualizarProximoBuffet(Fila* fila);
void atualizarListaEspera(Fila* fila);


void exibirClientesDiabeticos(Fila* fila);
void exibirClientesHipertensos(Fila* fila);
void exibirClientesSaudaveis(Fila* fila);
void imprimirFila(Fila* fila);
void imprimirFilas(Fila* fila, Fila* filaDiabeticos, Fila* filaHipertensos, Fila* filaSaudaveis);
void obterQuantidades(Fila* fila, int* qtdDiabeticos, int* qtdHipertensos, int* qtdSaudaveis);
void exibirRelatorio(Fila* fila);

//========MAIN==========
int main(){

    CLIENTE novo_cliente, lista_espera;
    NO *lista = NULL;
    int opc1, opc2, opc3;
    Fila fila;
    Fila filaDiabeticos;
    Fila filaHipertensos;
    Fila filaSaudaveis;

    // le o cadastro e ordena
    ler_cadastro("dados.csv", &lista);
    arquivo_ordenado(lista);
    //limpa_tela();

    printf("BEM VINDO O SISTEMA\n");
    printf("SELECIONE A OPÇAO DESEJADA:\n");
    printf("(1)- SOU CLIENTE\n(2)- SOU ADMINISTRADOR\n\n");
    scanf("%d", &opc1);
    setbuf(stdin, NULL);
    limpa_tela();

    switch (opc1){
    case 1:
        // parte do cliente
        do{
            printf("SEJA BEM VINDO CLIENTE:\n");
            printf("(1)-REALIZAR UM NOVO CADASTRO\n(2)-BUSCAR UM CADASTROS\n(3)-ALTERAR DADOS DO CADASTRO\n(0)-SAIR DO PROGRAMA\n\n");
            printf("DIGITE A OPCAO DESEJADA: \n\n");
            scanf("%d", &opc2);
            setbuf(stdin, NULL);

            limpa_tela();

            switch (opc2){
                // insere um novo usuario
            case 1:
                inserir_ordenando(&lista,(novo_cliente=cadastrar_cliente(novo_cliente)));
                arquivo_ordenado(lista);
                break;

            case 2:
                buscar_cliente(lista, "dados.csv");

                break;
            case 3:
                arquivo_ordenado(lista); // GERA O ARQUIVO
                alterar_cliente(lista, "dados.csv");
                arquivo_ordenado(lista); // ATUALIZA O ARQUIVO
                limpa_tela();
                break;
            case 0:
                limpa_tela();
                printf("Saindo...\n");
                break;
            default:
                break;
            }
        } while (opc2 != 0);
        break;
        //==================================ADMINISTRAÇÃO====================================================
    case 2:
        Le_espera("DadosChegada.txt", lista);
        //inicializarFila(&fila);
        limpa_tela();

        do
        {
            printf("SEJA BEM VINDO ADMINISTRADOR\n");
            printf("DIGITE A OPÇÃO DESEJADA\n");
            printf("(1)-MONTAR FILA DE ESPERA\n(2)-PROXIMOS A IREM AO BUFFET\n(3)-SAIR DO RESTAURANTE\n(4)- IMPRIMIR FILA D\n(5)- IMPRIMIR FILA H\n(6)- IMPRIMIR FILA N\n(7)- IMPRIMIR FILA DE ESPERA\n(8)- IMPRIMIR TODAS AS FILAS\n(9)-SAIR\n");
            scanf("%d", &opc3);
            setbuf(stdin, NULL);

            limpa_tela();

            switch (opc3){
            //TEM QUE IMPRIMIR OS QUE NÃO ENTRARAM NO ARQUIVO DE LISTA_ESPERA.TXT
            case 1:
                imprime_espera("lista_espera.txt");
                break;

            case 2:
                // PROXIMO A IR AO BUFFET
                inicializarFila(&fila);
                // Ler os dados do arquivo "lista_espera.txt" e adicionar à fila
                lerListaEspera(&fila);
                // Remover os próximos 15 clientes da fila e exibir seus nomes
                proximoBuffet(&fila);
                break;

            //PROBLEMA: SE EXECUTADO ANTES DO CASE 2 OS DADOS SAO APAGADOS
            case 3:
                // PESSOA QUE SAIU DO RESTAURANTE
                //atualizarProximoBuffet(&fila);
                // Atualizar o arquivo "lista_espera.txt" com os dados da fila
                atualizarListaEspera(&fila);
                // Liberar a memória alocada pela fila
                liberarMemoriaFila(&fila);
                break;

            case 4:
                // IMPRIMIR FILA D
                // Chamar função para atualizar o arquivo "lista_espera.txt" com os dados da fila
                //atualizarListaEspera(&fila);

                // Chamar função para exibir os clientes diabéticos
                exibirClientesDiabeticos(&fila);
                printf("\n\n");
                printf("DIGITE QUALQUE TECLA PARA VOLTAR AO MENU:\n");
                getchar();
                limpa_tela();
                break;

            case 5:
                // IMPRIMIR FILA H
                exibirClientesHipertensos(&fila);
                printf("\n\n");
                printf("DIGITE QUALQUE TECLA PARA VOLTAR AO MENU:\n");
                getchar();
                limpa_tela();
                break;

            case 6:
                // IMPRIMIR FILA N
                exibirClientesSaudaveis(&fila);
                printf("\n\n");
                printf("DIGITE QUALQUE TECLA PARA VOLTAR AO MENU:\n");
                getchar();
                limpa_tela();
                break;

            case 7:
                // PROXIMO A IR AO BUFFETinicializarFila(&fila);
                inicializarFila(&fila);
                // Ler os dados do arquivo "lista_espera.txt" e adicionar à fila
                lerListaEspera(&fila);
                // IMPRIMIR FILA DE ESPERA
                imprimirFila(&fila);
                break;

            case 8:
                // PROXIMO A IR AO BUFFET
                inicializarFila(&fila);
                // Ler os dados do arquivo "lista_espera.txt" e adicionar à fila
                lerListaEspera(&fila);
                // IMPRIMIR TODAS AS FILAS
                imprimirFilas(&fila, &filaDiabeticos, &filaHipertensos, &filaSaudaveis);
                break;

            case 9:
                exibirRelatorio(&fila);
                printf("SAINDO....");
                break;

            default:
                printf("opcao invalida\n");
                break;
            }

        } while (opc3 != 9);
    }

    return 0;
}//main

//============FUNÇÕES==================

CLIENTE cadastrar_cliente(CLIENTE cliente){
    //recebe o nome
    printf("Digite o seu nome:");
    setbuf(stdin, NULL);
    fgets(cliente.NOME, 60, stdin);
    cliente.NOME[strcspn(cliente.NOME, "\n")] = '\0';
    setbuf(stdin, NULL);
    int tamanho;
    tamanho = strlen(cliente.NOME);
    for (int i = 0; i < tamanho; i++){
        cliente.NOME[i] = toupper(cliente.NOME[i]);
    }

    limpa_tela();

    // recebe a data de nascimento
    printf("Digite a sua data de nascimento \n");
    printf("Digite o dia:\n");
    setbuf(stdin, NULL);
    fgets(cliente.DIA, 10, stdin);
    cliente.DIA[strcspn(cliente.DIA, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("Digite o mes:\n");
    setbuf(stdin, NULL);
    fgets(cliente.MES, 10, stdin);
    cliente.MES[strcspn(cliente.MES, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("Digite o ano:\n");
    setbuf(stdin, NULL);
    fgets(cliente.ANO, 10, stdin);
    cliente.ANO[strcspn(cliente.ANO, "\n")] = '\0';
    setbuf(stdin, NULL);

    limpa_tela();
    // recebe a condição de saude
    printf("Digite N para saúdavel\nH para hipertenso\nD para diabetico:\n");
    setbuf(stdin, NULL);
    fgets(cliente.DOENCA, 20, stdin);
    cliente.DOENCA[strcspn(cliente.DOENCA, "\n")] = '\0';
    setbuf(stdin, NULL);
    // converte nome para maiusculo
    tamanho = strlen(cliente.DOENCA);
    for (int i = 0; i < tamanho; i++)
    {
        cliente.DOENCA[i] = toupper(cliente.DOENCA[i]);
    }

    limpa_tela();
    return cliente;


} // cadastrar_cliente


//Função para ordenar lista de clientes em ordem alfabetica
void inserir_ordenando(NO **lista, CLIENTE cliente){
    NO *novo = malloc(sizeof(NO));
    if (novo != NULL){
        // Aloca memória para um novo nó e verifica se a alocação foi bem-sucedida
        novo->Clt = cliente;
        novo->proximo = NULL;
        novo->anterior = NULL;

        if (*lista == NULL){
            // Se a lista estiver vazia, o novo nó se torna o primeiro elemento da lista
            *lista = novo;
        }
        else if (strcmp(cliente.NOME, (*lista)->Clt.NOME) < 0){
            // Se o nome do cliente for menor que o nome do primeiro elemento da lista,
            // o novo nó é inserido no início da lista
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else{
            // Caso contrário, percorre a lista até encontrar a posição correta para inserir o novo nó
            NO *atual = *lista;

            while (atual->proximo != NULL && strcmp(cliente.NOME, atual->proximo->Clt.NOME) > 0){
                atual = atual->proximo;
            }

            // Insere o novo nó na posição correta, ajustando os ponteiros dos nós adjacentes
            novo->proximo = atual->proximo;
            novo->anterior = atual;
            if (atual->proximo != NULL){
                atual->proximo->anterior = novo;
            }
            atual->proximo = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }
}//inserir_ordenando

void ler_cadastro(char *arquivo, NO **lista) {
    CLIENTE cliente;
    FILE *f = fopen(arquivo, "r");

    if (f == NULL) {
        printf("Erro ao ler o arquivo\n");
        exit(1);
    }

    //lê as informações de clientes do arquivo e os insere na lista de forma ordenada
    while (!feof(f)) {
        fscanf(f, "%40[^\t]\t%[^/]/%[^/]/%[^\t]\t%[^\n]\n", cliente.NOME, cliente.DIA,cliente.MES,cliente.ANO, cliente.DOENCA);
        inserir_ordenando(lista, cliente);
    }

    fclose(f);
}//ler_cadastro

void arquivo_ordenado(NO* no) {
    FILE* arq = fopen("dados.csv", "w");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    // Percorre a lista e escreve as informações dos clientes no arquivo
    while (no != NULL) {
        fprintf(arq, "%s\t%s/%s/%s\t%s\n", no->Clt.NOME, no->Clt.DIA, no->Clt.MES, no->Clt.ANO, no->Clt.DOENCA);
        no = no->proximo;
    }

    fclose(arq);
}//arquivo_ordenado

void alterar_cliente(NO *lista, char *arquivo){

    char nome[61], dia[10],mes[10],ano[10], doenca[21];
    int opcao;

    // Solicitação do nome do cliente que será alterado
    printf("Digite o nome do cliente que deseja alterar:\n");
    setbuf(stdin, NULL);
    fgets(nome, 60, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    limpa_tela();

    // converte nome para maiusculo
    int tamanho;
    tamanho = strlen(nome);
    for (int i = 0; i < tamanho; i++){
        nome[i] = toupper(nome[i]);
    }

    // buscando o cliente na lista encadeada
    NO *atual = lista; // inicializada com o primeiro NO da lista
    while (atual != NULL && strcmp(nome, atual->Clt.NOME) != 0){
        atual = atual->proximo;
    }


    // caso nâo encontre o cadastro
    if (atual == NULL){
        limpa_tela();
        printf("Você ainda não tem cadastro!\n");
        return;
    }

    // solicitando o que deseja alterar
    printf("O que deseja alterar?\n");
    printf("1 - Nome\n");
    printf("2 - Data de Nascimento\n");
    printf("3 - Condição de Saúde\n");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

        limpa_tela();

    switch (opcao)
    {
        //altera o nome
    case 1:
        printf("Digite o novo nome do cliente:\n");
        fgets(nome, 60, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        // de minusculo para maiusculo
        tamanho = strlen(nome);
        for (int i = 0; i < tamanho; i++){
            nome[i] = toupper(nome[i]);
        }
        strcpy(atual->Clt.NOME, nome);

        limpa_tela();

        break;

        //altera a data de nascimento
    case 2:
        printf("Digite a nova data de nascimento do cliente:\n");
        printf("Digite o dia:\n");
        fgets(dia, 10, stdin);
        dia[strcspn(dia, "\n")] = '\0';
        strcpy(atual->Clt.DIA, dia);
        limpa_tela();

        printf("Digite o mes:\n");
        fgets(mes, 10, stdin);
        mes[strcspn(mes, "\n")] = '\0';
        strcpy(atual->Clt.MES, mes);
        limpa_tela();

        printf("Digite o ano:\n");
        fgets(ano, 10, stdin);
        ano[strcspn(ano, "\n")] = '\0';
        strcpy(atual->Clt.ANO, ano);
        limpa_tela();

        break;

        //altera a condição de saúde
    case 3:
        printf("Digite a nova condição de saúde do cliente:\n");
        fgets(doenca, 20, stdin);
        doenca[strcspn(doenca, "\n")] = '\0';
        // de minusculo para maiusculo
        tamanho = strlen(doenca);
        for (int i = 0; i < tamanho; i++){
            doenca[i] = toupper(doenca[i]);
        }
        strcpy(atual->Clt.DOENCA, doenca);
        limpa_tela();
        break;
    default:
        printf("Opção inválida!\n");
        return;
    }

    NO *no = lista;
    FILE *arq = fopen(arquivo, "w");
    if (arq == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while (no){
        fprintf(arq, "%s\t%s/%s/%s\t%s\n",no->Clt.NOME,no->Clt.DIA,no->Clt.MES,no->Clt.ANO,no->Clt.DOENCA);
        no = no->proximo;
    }
    fclose(arq);

    limpa_tela();

    printf("Cliente alterado com sucesso!\n");
    printf("\n\n");
    printf("Pressione qualquer tecla para continuar...");
    getchar();


}//alterar_cliente

void buscar_cliente(NO *lista, char *arquivo){

    char nome[61];

    printf("Digite o nome do cliente que deseja buscar\n");
    fgets(nome, 60, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    // converte nome para maiusculo
    int tamanho;
    tamanho = strlen(nome);
    for (int i = 0; i < tamanho; i++)
    {
        nome[i] = toupper(nome[i]);
    }
    //printf("%s", nome);

    NO *atual = lista;

    // Percorre a lista até encontrar o cliente com o nome desejado
    while (atual != NULL && strcmp(nome, atual->Clt.NOME) != 0){
        atual = atual->proximo;
    }

    if (atual == NULL){
        printf("Cliente não encontrado!\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        return;
    }

    limpa_tela();

    // Imprime as informações do cliente encontrado
    printf("Nome do cliente: %s\n", atual->Clt.NOME);
    printf("Data de nascimento: %s/%s/%s\n", atual->Clt.DIA,atual->Clt.MES,atual->Clt.ANO);
    printf("Condição de saúde do cliente: %s\n", atual->Clt.DOENCA);

    printf("digite qualquer tecla para continuar...");
    getchar();
    limpa_tela();

} // buscar_cliente

void Le_espera(char *arquivo, NO *lista) {
    CLIENTE espera[100];
    FILE *f = fopen(arquivo, "r");
    FILE *f2;
    int i = 0;

    if (f != NULL) {
        // Lê as informações de clientes do arquivo e armazena no vetor espera[]
        while (!feof(f)) {
            fscanf(f, "%39[^\n]\n", espera[i].NOME);
            i++;

        }

        fclose(f);
        // Abre dois arquivos para escrita
        f = fopen("lista_espera.txt", "w");
        f2 = fopen("copia_lista.txt", "w");

        for (i = 0; i < 100; i++) {
            NO *aux = lista;

            // Percorre a lista para encontrar o cliente correspondente ao nome em espera[]
            while (aux != NULL) {
                if (strcmp(aux->Clt.NOME, espera[i].NOME) == 0) {
                    // Verifica se a idade do cliente é maior que 12
                    if(confere_idade(aux->Clt.ANO)>12){
                    // Escreve o nome do cliente e sua doença no arquivo "lista_espera.txt"
                    fprintf(f, "%s,%s\n", espera[i].NOME,aux->Clt.DOENCA);
                     // Escreve o nome do cliente e sua doença no arquivo "copia_lista.txt"
                    fprintf(f2, "%s,%s\n", espera[i].NOME,aux->Clt.DOENCA);
                    break;
                    }//if da idade
                }//if do nome
                aux = aux->proximo;
            }
        }

        fclose(f);
        fclose(f2);
    } else {
        printf("Arquivo não encontrado");
        exit(1);
    }
}//Le_espera

int confere_idade(char pessoa[]){
        int idade_pessoa = atoi(pessoa); // Converte a string para inteiro
        int year;
        time_t now;
        time(&now);
        struct tm *local = localtime(&now);

         year = local->tm_year + 1900;   // obtém o ano desde 1900

        return year - idade_pessoa; // Retorna a diferença entre o ano atual e o ano de nascimento, representando a idade da pessoa

}//confere_idade

void imprime_espera(char *arquivo) {
    CLIENTE espera[100];
    FILE *f = fopen(arquivo, "r");
    int i = 0;

    if (f != NULL) {
        // Lê as informações de clientes do arquivo e armazena no vetor espera[]
        while (!feof(f)) {
            fscanf(f, "%39[^,],%[^\n]\n", espera[i].NOME, espera[i].DOENCA);
            i++;
        }
        fclose(f);
    }

    int aux = i;

    // Imprime as 15 primeiras pessoas do vetor espera[] que irão entrar imediatamente
    printf("AS 15 PESSOAS ABAIXO IRÃO ENTRAR IMEDIATAMENTE:\n\n");
    for (i = 0; i < 15 && i < aux; i++) {
        printf("%d - %s | Estado de saúde: %s\n", i + 1, espera[i].NOME, espera[i].DOENCA);
        fflush(stdout);
    }

    printf("\n\n");

    // Imprime as pessoas restantes na lista de espera
    printf("AS PESSOAS ABAIXO ESTÃO NA LISTA DE ESPERA:\n\n");
    for (i = 15; i < aux; i++) {
        printf("%d - %s | Estado de saúde: %s\n", i + 1, espera[i].NOME, espera[i].DOENCA);
        fflush(stdout);
    }
    printf("\n\n");
    printf("DIGITE QUALQUE TECLA PARA VOLTAR AO MENU:\n");
    getchar();
    limpa_tela();
}//imprime_espera


//===============================================================
//------------------------FILAS----------------------------------
//===============================================================

void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}//inicializarFila

int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}//filaVazia

void enfileirar(Fila* fila, const char* cliente) {
    NoFila* novoNo = (NoFila*)malloc(sizeof(NoFila));
    strncpy(novoNo->cliente, cliente, sizeof(novoNo->cliente)); // Copia a string cliente para o campo cliente do novo nó
    novoNo->next = NULL;

    if (fila->fim == NULL) {
        // Se o ponteiro de fim da fila for NULL, significa que a fila está vazia
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        // Se a fila não estiver vazia, atualiza o próximo ponteiro do último nó existente para apontar para o novo nó
        fila->fim->next = novoNo;
        fila->fim = novoNo;
    }
}//enfileirar

char* desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        return NULL;
    }

    NoFila* temp = fila->inicio; // Armazena o ponteiro do primeiro nó em uma variável temporária
    char* cliente = strdup(temp->cliente); // Copia a string cliente do primeiro nó para uma nova string

    fila->inicio = fila->inicio->next; // Atualiza o ponteiro de início para o próximo nó da fila
    if (fila->inicio == NULL) {
        fila->fim = NULL; // Se o ponteiro de início se tornar NULL, significa que a fila está vazia, então o ponteiro de fim também é atualizado para NULL
    }

    free(temp);

    return cliente; // Retorna a cópia da string cliente
}//desinfileirar

void lerListaEspera(Fila* fila) {
    FILE* arquivo = fopen("lista_espera.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo lista_espera.txt\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0'; // Remove o caractere de nova linha do final da linha lida
        enfileirar(fila, linha); // Enfileira a linha na fila
    }

    fclose(arquivo);
}//lerListaEspera

void proximoBuffet(Fila* fila){

    for (int i = 0; i < 15; i++) {
        char* cliente = desenfileirar(fila); // Desenfileira o próximo cliente da fila
        if (cliente != NULL) {
            printf("Cliente atendido: %s\n", cliente); // Imprime o cliente que está sendo atendido
            free(cliente);
        } else {
            printf("Não há mais clientes na fila.\n"); // Se não houver mais clientes na fila, exibe uma mensagem
            break;
        }
    }

    printf("\n\n");
    printf("DIGITE QUALQUE TECLA PARA VOLTAR AO MENU:\n");
    getchar();
    limpa_tela();
}//proximoBuffet

/*void atualizarProximoBuffet(Fila* fila){

    for (int i = 0; i < 15; i++) {
        char* cliente = desenfileirar(fila); // Desenfileira o próximo cliente da fila
    }
}*///atualizarProximoBuffet

void atualizarListaEspera(Fila* fila) {
    FILE* arquivo = fopen("lista_espera.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo lista_espera.txt\n");
        return;
    }

    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        fprintf(arquivo, "%s\n", atual->cliente); // Escreve o nome do cliente no arquivo
        atual = atual->next; // Move para o próximo nó da fila
    }

    printf("Fila atualizada com sucesso!\n\n");

    fclose(arquivo);
}//atualizarListaEspera



void liberarMemoriaFila(Fila* fila){
    NoFila* atual = fila->inicio;
                while (atual != NULL) {
                    NoFila* temp = atual;
                    atual = atual->next;
                    free(temp); // Libera a memória ocupada por cada nó da fila
                }
                fila->inicio = NULL; // Define o ponteiro de início da fila como NULL
                fila->fim = NULL; // Define o ponteiro de fim da fila como NULL

}//liberarMemoriaFila






//-------------------------Diabete-----------------

void exibirClientesDiabeticos(Fila* fila) {
    FILE* arquivo = fopen("lista_espera.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome[100];
        char doenca[100];
        sscanf(linha, "%[^,],%s", nome, doenca); // Lê o nome e a doença da linha formatada no arquivo

        if (strcmp(doenca, "D") == 0) {
            printf("Nome: %s\n", nome); // Se a doença for "D" (diabetes), imprime o nome do cliente
        }
    }

    fclose(arquivo);


}//exibirClientesDiabeticos

//------------------------Hipertenso---------------

void exibirClientesHipertensos(Fila* fila) {
    FILE* arquivo = fopen("lista_espera.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome[100];
        char doenca[100];
        sscanf(linha, "%[^,],%s", nome, doenca); // Lê o nome e a doença da linha formatada no arquivo

        if (strcmp(doenca, "H") == 0) {
            printf("Nome: %s\n", nome); // Se a doença for "H" (hipertensão), imprime o nome do cliente
        }
    }

    fclose(arquivo);

}//exibirClientesHipertensos

//------------------------Saudavel-----------------

void exibirClientesSaudaveis(Fila* fila) {
    FILE* arquivo = fopen("lista_espera.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome[100];
        char doenca[100];
        sscanf(linha, "%[^,],%s", nome, doenca);

        if (strcmp(doenca, "N") == 0) {
            printf("Nome: %s\n", nome); // Se a doença for "N" (saúdavel), imprime o nome do cliente
        }
    }

    fclose(arquivo);

}//exibirClientesSaudaveis


//imprime a fila dinâmica
void imprimirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila de espera esta vazia.\n");
        return;
    }

    printf("Fila de Espera:\n");
    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->cliente); // Imprime o nome de cada cliente na fila
        atual = atual->next; // Move para o próximo nó da fila
    }
    printf("\n\n");
    printf("DIGITE QUALQUE TECLA PARA VOLTAR AO MENU:\n");
    getchar();
    limpa_tela();

}

void imprimirFilas(Fila* fila, Fila* filaDiabeticos, Fila* filaHipertensos, Fila* filaSaudaveis) {

    if (filaVazia(fila)) {
        printf("A fila de espera esta vazia.\n");
        printf("\n\n");
        printf("DIGITE QUALQUE TECLA PARA VOLTAR AO MENU:\n");
        getchar();
        limpa_tela();
        return;
    }

    printf("----------------Clientes Diabeticos----------------\n\n");
    exibirClientesDiabeticos(filaDiabeticos); // Exibe os clientes com diabetes presentes na fila de diabéticos
    printf("\n\n");
    printf("----------------Clientes Hipertensos----------------\n\n");
    exibirClientesHipertensos(filaHipertensos); // Exibe os clientes com hipertensão presentes na fila de hipertensos
    printf("\n\n");
    printf("----------------Clientes Saudaveis----------------\n\n");
    exibirClientesSaudaveis(filaSaudaveis); // Exibe os clientes saudáveis presentes na fila de saudáveis

    printf("\n\n");
    printf("DIGITE QUALQUE TECLA PARA VOLTAR AO MENU:\n");
    getchar();
    limpa_tela();
}



void obterQuantidades(Fila* fila, int* qtdDiabeticos, int* qtdHipertensos, int* qtdSaudaveis) {
    // Inicializa as quantidades como zero
    *qtdDiabeticos = 0;
    *qtdHipertensos = 0;
    *qtdSaudaveis = 0;

    // Abre o arquivo para leitura
    FILE* arquivo = fopen("copia_lista.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Lê cada linha do arquivo e atualiza as quantidades de acordo com a doença de cada cliente
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome[100];
        char doenca[100];
        sscanf(linha, "%[^,],%s", nome, doenca);

        if (strcmp(doenca, "D") == 0) {
            (*qtdDiabeticos)++;
        } else if (strcmp(doenca, "H") == 0) {
            (*qtdHipertensos)++;
        } else if (strcmp(doenca, "N") == 0) {
            (*qtdSaudaveis)++;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);
}


void exibirRelatorio(Fila* fila){
    int qtdDiabeticos, qtdHipertensos, qtdSaudaveis;
    int entrada, despesa, lucro;
    //FILE *arquivo;

    obterQuantidades(fila, &qtdDiabeticos, &qtdHipertensos, &qtdSaudaveis);
    entrada = qtdHipertensos*50+qtdDiabeticos*55+qtdSaudaveis*40;
    despesa = qtdHipertensos*30+qtdDiabeticos*35+qtdSaudaveis*25;
    lucro = entrada - despesa;

    // Obtém a data atual
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    // Formata a data atual no formato desejado
    char nome_arquivo[100];
    strftime(nome_arquivo, sizeof(nome_arquivo), "relatorio_%d-%m-%Y.txt", local);

    // Abre o arquivo para escrita
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de relatório\n");
        return;
    }

    fprintf(arquivo, "Relatório do Dia %02d/%02d/%04d\n\n\n", local->tm_mday, local->tm_mon+1, local->tm_year+1900);
    fprintf(arquivo, "Total de Atendimento: %d\n", qtdDiabeticos+qtdHipertensos+qtdSaudaveis);
    fprintf(arquivo, "Hipertensos:%d\n", qtdHipertensos);
    fprintf(arquivo, "Diabeticos:%d\n", qtdDiabeticos);
    fprintf(arquivo, "Saudáveis:%d\n", qtdSaudaveis);
    fprintf(arquivo, "\nTotal de entrada:%d\n", entrada);
    fprintf(arquivo, "Total de custos de despesas:%d\n", despesa);
    fprintf(arquivo, "Lucro:%d\n", lucro);

    fclose(arquivo); // fecha o arquivo

    remove("copia_lista.txt");

}






void limpa_tela(){
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else defined(__linux__) || defined(__unix__)
    system("clear");
#endif
}
