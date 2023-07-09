#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

#define TAM 94
//=====ESTRUTURAS=====
typedef struct cliente
{
    int key1;
    char nome[41];
    int x;
    int y;
} CLIENTE;

typedef struct hastable
{
    int key;
    CLIENTE *cliente[TAM];
} HASHTABLE;

typedef struct grafoM{
    int  **matriz;
    int  vertices;
    bool digrafo; // se sim true, caso contrário false
}GrafoMatriz;


//=====CABEÇALHOS=====
void inicializar_Hash(HASHTABLE *t);
int funcao_Hash(int num);
void insere(HASHTABLE *tabela, CLIENTE *cliente);
void ler_arquivo(HASHTABLE *tabela);
void imprimeHash(HASHTABLE *tabela);
void menu(HASHTABLE *tabela);
CLIENTE *busca(HASHTABLE *tabela, int chave);
float calcula_distancia(float x, float y);
void imprime_distancia(HASHTABLE *tabela);
void limpa_tela();
//=====MAIN====

int main()
{
    HASHTABLE tabela;
    GrafoMatriz grafo;

    menu(&tabela);

    inicializa(&grafo, TAM, false);
    inclue_grafo(&tabela, &grafo);

    return 0;
}

//=====FUNÇÕES=====
void menu(HASHTABLE *tabela)
{
    inicializar_Hash(&tabela);
    ler_arquivo(&tabela);

    int opc = 0, chave = 0;
    do
    {
        limpa_tela();
        printf("\t===SEJA BEM VINDO AO SISTEMA===\t\n");
        printf("\tDIGITE A OPÇÃO DESEJADA:\t\n");
        printf("\t[1]- para imprimir a tabela de clientes\t\n");
        printf("\t[2]- para buscar um cliente\t\n");
        printf("\t[3]- para imprimir a distancia entre os clientes\t\n"); // lembrar de arrumar pra fazer de 20 em 20
        printf("\t[0]- para sair do programa\t\n");
        scanf("%d", &opc);
        setbuf(stdin, NULL);
    } while (opc != 1 && opc != 2 && opc != 3 && opc != 0);

    switch (opc)
    {
    case 1:
        limpa_tela();
        opc = 0;
        imprimeHash(&tabela);
        do
        {
            printf("\tDIGITE 1 PARA VOLTAR AO MENU\t\n");
            printf("\tDIGITE 0 PARA SAIR DO PROGRAMA\t\n");
            scanf("%d", &opc);
            setbuf(stdin, NULL);
            limpa_tela();
        } while (opc != 1 && opc != 0);
        if (opc == 1)
        {
            menu(&tabela);
        }
        else
        {
            exit(1);
        }

        break;

    case 2:
        printf("\tDigite a chave do cliente que deseja buscar: \t\n");
        scanf("%d", &chave);
        setbuf(stdin, NULL);
        CLIENTE *clienteEncontrado = busca(&tabela, chave);

        if (clienteEncontrado != NULL)
        {
            limpa_tela();
            printf("|KEY|\t|NOME \t\t\t\t\t\t\t|COORDENADA X|\t|COORDENADA Y|\n");
            printf("|[%d]|\t|%-50s\t|    %-8d|\t|    %-8d|\n", clienteEncontrado->key1 % TAM, clienteEncontrado->nome, clienteEncontrado->x, clienteEncontrado->y);
            do
            {
                printf("\tDIGITE 1 PARA VOLTAR AO MENU\t\n");
                printf("\tDIGITE 0 PARA SAIR DO PROGRAMA\t\n");
                scanf("%d", &opc);
                setbuf(stdin, NULL);
                limpa_tela();
            } while (opc != 1 && opc != 0);
            if (opc == 1)
            {
                menu(&tabela);
            }
            else
            {
                exit(1);
            }
        }
        else
        {
            printf("Cliente nao encontrado\n");
            do
            {
                printf("\tDIGITE 1 PARA VOLTAR AO MENU\t\n");
                printf("\tDIGITE 0 PARA SAIR DO PROGRAMA\t\n");
                scanf("%d", &opc);
                setbuf(stdin, NULL);
                limpa_tela();
            } while (opc != 1 && opc != 0);
            if (opc == 1)
            {
                menu(&tabela);
            }
            else
            {
                exit(1);
            }
        }

        break;

    case 3:
        limpa_tela();
        imprime_distancia(&tabela);
        do
        {
            printf("\tDIGITE 1 PARA VOLTAR AO MENU\t\n");
            printf("\tDIGITE 0 PARA SAIR DO PROGRAMA\t\n");
            scanf("%d", &opc);
            setbuf(stdin, NULL);
            limpa_tela();
        } while (opc != 1 && opc != 0);
        if (opc == 1)
        {
            menu(&tabela);
        }
        else
        {
            exit(1);
        }
        break;

    case 0:
        exit(1);
        break;
    }
}

void inicializar_Hash(HASHTABLE *t)
{
    t->key = 0;
    for (int i = 0; i < TAM; i++)
    {
        t->cliente[i] = NULL;
    }
}

int funcao_Hash(int num)
{
    return num % TAM;
}

void insere(HASHTABLE *tabela, CLIENTE *cliente)
{
    int posicao = funcao_Hash(cliente->key1);

    while (tabela->cliente[posicao] != NULL)
    {
        posicao++;
        if (posicao == TAM)
        {
            posicao = 0;
        }
    }
    tabela->cliente[posicao] = cliente;
    tabela->key++;
}
// le o arquivo e insere na tabela hash
void ler_arquivo(HASHTABLE *tabela)
{
    FILE *f = fopen("coordenadas_clientes.csv", "r");
    CLIENTE aux[TAM];
    int i = 0;
    if (f == NULL)
    {
        printf("Erro na abertura do arquivo 1\n");
        exit(1);
    }
    char buffer[1000];
    fgets(buffer, sizeof(buffer), f);
    while (!feof(f))
    {
        CLIENTE *cliente = (CLIENTE *)malloc(sizeof(CLIENTE)); // Aloca memória para cada cliente
        fscanf(f, "%[^,],%d,%d\n", cliente->nome, &cliente->x, &cliente->y);
        cliente->key1 = i++; // Atribui um valor de chave para cada cliente (usando o índice)
        insere(tabela, cliente);
    }

    fclose(f);
}
// imprime a tabela hash
void imprimeHash(HASHTABLE *tabela)
{
    limpa_tela();
    printf("                  ============COORDENADA DOS CLIENTES====================\n\n");
    printf("|KEY|\t|NOME \t\t\t\t\t\t\t|COORDENADA X|\t|COORDENADA Y|\n");
    for (int i = 0; i < TAM; i++)
    {
        if (tabela->cliente[i] == NULL)
        {
            printf("[%d]-null\n", i);
        }
        else
        {
            printf("|[%d]|\t|%-50s\t|    %-8d|\t|    %-8d|\n", tabela->cliente[i]->key1 % TAM, tabela->cliente[i]->nome, tabela->cliente[i]->x, tabela->cliente[i]->y);
        }
    }
    printf("\n\n");
}

CLIENTE *busca(HASHTABLE *tabela, int chave)
{
    int posicao = funcao_Hash(chave);

    while (tabela->cliente[posicao] != NULL)
    {
        if (tabela->cliente[posicao]->key1 == chave)
        {
            return tabela->cliente[posicao]; // Retorna o cliente encontrado
        }

        posicao++;
        if (posicao == TAM)
        {
            posicao = 0;
        }
    }

    return NULL; // Retorna NULL se o cliente não for encontrado
}

float calcula_distancia(float x, float y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

void imprime_distancia(HASHTABLE *tabela)
{
    float matriz[TAM][TAM];
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            matriz[i][j] = 0.0;
        }
    }
    for (int i = 0; i < TAM; i++)
    {
        if (tabela->cliente[i] != NULL)
        {
            for (int j = 0; j < TAM; j++)
            {
                if (tabela->cliente[j] != NULL)
                {
                    float distancia = calcula_distancia(tabela->cliente[i]->x - tabela->cliente[j]->x, tabela->cliente[i]->y - tabela->cliente[j]->y);
                    matriz[i][j] = distancia;
                }
            }
        }
    }
    printf("                  ============MATRIZ DE DISTANCIA====================\n\n");
   
   
    for (int i = 0; i < TAM-1; i++)
    {
        //printf("%d  ", i);
        for (int j = 0; j < TAM-1; j++)
        {
            printf("X|%d| Y|%d| Distancia:|%.2f|\t\n ",i,j, matriz[i][j]);
        }

        if(i==10 || i==20 || i == 30 || i==40 || i == 50 || i == 60|| i == 70|| i == 80|| i==90){
            int a;

            

            printf("\nDigite 1 para continuar e 2 para sair:");
            scanf("%d",&a);

           
            if(a == 2){
                break;
            }

        }



        //printf("\n");
    }
    printf("\n");
}

void inicializa(GrafoMatriz *grafo, int N, bool eh_digrafo){
    grafo->vertices = N;
    grafo->digrafo = eh_digrafo;

    grafo->matriz=(int**) malloc(N*sizeof(int*));
    for(int i=0; i<N; i++){
         grafo->matriz[i]= (int*) malloc(N*sizeof(int));
         for(int j=0; j<N; j++){
            grafo->matriz[i][j]=0;
         }
    }
}

void conecta(GrafoMatriz *grafo, int v1, int v2, float peso){
    grafo->matriz[v1][v2]=peso;
    if(grafo->digrafo==false)  grafo->matriz[v2][v1]=peso;
}


void inclue_grafo(HASHTABLE *tabela, GrafoMatriz *grafo){
        char aux [35];
        int auxpeso;
        int v1,v2,i = 0, j = 0;
        float distancia,peso;

        FILE *f = fopen("clientes adjacencia.csv", "r");
        if (f == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

        char buffer[1000];
        fgets(buffer, sizeof(buffer), f);

      while (!feof(f))
    {
        for (j = 0; j < TAM - 1; j++)
        {
            fscanf(f, "%[^,],", aux);
            fscanf(f, "%d,", &auxpeso);
            if (auxpeso != 0)
            {
                distancia = calcula_distancia(tabela->cliente[i]->x - tabela->cliente[j]->x, tabela->cliente[i]->y - tabela->cliente[j]->y);
                conecta(grafo, i, j, distancia);
            }
        }
        j++;
        fscanf(f, "%[^,],", aux);
        fscanf(f, "%d\n", &auxpeso);
        if (auxpeso != 0)
        {
            distancia = calcula_distancia(tabela->cliente[i]->x - tabela->cliente[j]->x, tabela->cliente[i]->y - tabela->cliente[j]->y);
            conecta(grafo, i, j, distancia);
        }

        i++;
    }

    fclose(f);
}

        

    



void limpa_tela()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else defined(__linux__) || defined(__unix__)
    system("clear");
#endif
}