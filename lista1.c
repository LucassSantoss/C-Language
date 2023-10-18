#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>


/*Exercício 1
int produtoEscalar(int lista1[], int lista2[])
{
    int i, resultado=0;
    for (i=0;i<3;i++)
    {
        resultado += lista1[i] * lista2[i];
    }
    return resultado;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //montando lista1
    int i, lista1[3], lista2[3], resultado;
    printf("Montando lista 1: \n");
    for (i=0;i<3;i++)
    {
        printf("número %d: ", i+1);
        scanf("%d", &lista1[i]);
    }
    //montando lista2
    printf("Montando lista 2: \n");
    for (i=0;i<3;i++)
    {
        printf("número %d: ", i+1);
        scanf("%d", &lista2[i]);
    }
    resultado = produtoEscalar(lista1, lista2);
    printf("O resultado do produto escalar dessas listas é: %d", resultado);
}
*/

/*Exercício 2
int verificaAcertos(int sortidos[], int aposta[])
{
    int i, j, acertos=0, achou;
    for (i=0;i<5;i++)
    {
        achou = 1;
        for (j=0;j<10 && achou==1;j++)
        {
            if (sortidos[i] == aposta[j])
            {
                acertos += 1;
                achou=0;
            }
        }
    }
    return acertos;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, sortidos[5], aposta[10], resultado;
    //apostas do usuário
    printf("Digite os 10 números em que quer apostar: \n");
    for (i=0;i<10;i++)
    {
        printf("Número %d: ", i+1);
        scanf("%d", &aposta[i]);
    }
    //gerando números aleatórios
    srand(time(NULL));
    printf("Os números sortidos foram: ");
    for (i=0;i<5;i++)
    {
        sortidos[i] = rand() %50;
        printf(" %d |", sortidos[i]);
    }
    resultado = verificaAcertos(sortidos, aposta);
    printf("\nVocê obteve um total de %d acertos :)\n", resultado);
}
*/

/*Exercício 3
int somaColuna(int matriz[][3])
{
    int i, j, col1=0, col2=0, col3=0;
    //coluna 1
    for (i=0;i<3;i++)
    {
        col1 += matriz[i][0];
    }
    //coluna 2
    for (i=0;i<3;i++)
    {
        col2 += matriz[i][1];
    }
    //coluna 3
    for (i=0;i<3;i++)
    {
        col3 += matriz[i][2];
    }
    if (col1 == col2 && col1 == col3)
    {
        return col1;
    }
    else
    {
        return 0;
    }
}

int somaDiagonalPrincipal(int matriz[3][3])
{
    int i, soma=0;
    for (i=0;i<3;i++)
    {
        soma += matriz[i][i];
    }
    return soma;
}

int somaDiagonalSecundaria(int matriz[3][3])
{
    int i=0, j=2, soma=0;
    for (i=0;i<3;i++)
    {
        soma += matriz[i][j];
        j--;
    }
    return soma;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //montando matriz
    printf("Montando sua matriz...\n");
    int i, j, matriz[3][3], quadradoMagico;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("Número da posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    if (somaColuna(matriz) == somaDiagonalPrincipal(matriz) && somaColuna(matriz) == somaDiagonalSecundaria(matriz))
    {
        printf("\nSua matriz é um quadrado mágico :)\n");
    }
    else
    {
        printf("\nSua matriz não é um quadrado mágico :(\n");
    }
}
*/

/*Exercício 4
void criaMatriz(int mat[][5])
{
    printf("Construindo sua matriz...\n");
    int i, j, linha=4, coluna=5;
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            printf("Insira o termo [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\nMatriz pronta :)\n");
}

void printMatriz(int mat[][5])
{
    printf("Demonstração da matriz: \n");
    int i, j, linha=4, coluna=5;

    for (i=0;i<linha;i++)
    {
        printf("| ");
        for (j=0;j<coluna;j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

int Minmax(int mat[][5])
{
    int i, j, linha=4, coluna=5, menor, minmax, menorLinha;
    menor = mat[0][0];
    menorLinha = 0;
    //menor número da matriz
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            if (mat[i][j] < menor)
            {
                menor = mat[i][j];
                menorLinha = i;
            }
        }
    }
    //maior número da linha
    minmax = mat[menorLinha][0];
    for (j=1;j<coluna;j++)
    {
        if (mat[menorLinha][j] > minmax)
        {
            minmax = mat[menorLinha][j];
        }
    }
    return minmax;
}


int main()
{
    setlocale(LC_ALL, "Portuguese");
    int mat[4][5];
    criaMatriz(mat);
    printMatriz(mat);
    int minmax;
    minmax = Minmax(mat);
    printf("\nO elemento MINMAX dessa matriz é: %d\n", minmax);
}
*/

/*Exercício 5
void criaMatriz(int mat[][7])
{
    printf("Construindo sua matriz...\n");
    int i, j, linha=7, coluna=7;
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            printf("Insira o termo [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\nMatriz pronta :)\n");
}

void printMatriz(int mat[][7])
{
    printf("Demonstração da matriz: \n");
    int i, j, linha=7, coluna=7;

    for (i=0;i<linha;i++)
    {
        printf("| ");
        for (j=0;j<coluna;j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

void Menores(int menores[], int mat[][7])
{
    int i, j, menor, linha=7, coluna=7;

    for (i=0;i<linha;i++)
    {
        menor = mat[i][0];
        for (j=1;j<coluna;j++)
        {
            if (mat[i][j] < menor)
            {
                menor = mat[i][j];
            }
        }
        menores[i] = menor;
    }
}

void Maiores(int maiores[], int mat[][7])
{
    int i, j, maior, linha=7, coluna=7;

    for (i=0;i<linha;i++)
    {
        maior = mat[i][0];
        for (j=1;j<coluna;j++)
        {
            if (mat[i][j] > maior)
            {
                maior = mat[i][j];
            }
        }
        maiores[i] = maior;
    }
}

void printLista(int lista[])
{
    int i, len=7;
    printf("| ");
    for (i=0;i<len;i++)
    {
        printf("%d ", lista[i]);
    }
    printf("|\n\n");
}


int main()
{
    setlocale(LC_ALL, "Portuguese");
    int mat[7][7], maiores[7], menores[7];
    criaMatriz(mat);
    printMatriz(mat);
    Menores(menores, mat);
    Maiores(maiores, mat);
    printf("\nOs menores números de cada linha são:\n");
    printLista(menores);
    printf("Os maiores números de cada linha são:\n");
    printLista(maiores);
}
*/


/*Exercício 6
#define linha 2
#define coluna 4

void criaMatriz(int mat[][coluna])
{
    printf("Construindo sua matriz...\n");
    int i, j;
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            printf("Insira o termo [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\nMatriz pronta :)\n");
}

void printMatriz(int mat[][coluna])
{
    printf("Demonstração da matriz: \n");
    int i, j;

    for (i=0;i<linha;i++)
    {
        printf("| ");
        for (j=0;j<coluna;j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

void somaLinhas(int mat[][coluna], int vet_soma[])
{
    //somando cada linha e atribuindo ao vetor de somas
    int i, j;
    for (i=0;i<linha;i++)
    {
        vet_soma[i] = 0;
        for (j=0;j<coluna;j++)
        {
            vet_soma[i] += mat[i][j];
        }
    }
}

void multiplica_matriz_vetor(int mat[][coluna], int vet[])
{
    int i, j;
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            mat[i][j] *= vet[i];
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int mat[linha][coluna], vet_soma[linha];
    criaMatriz(mat);
    printMatriz(mat);
    somaLinhas(mat, vet_soma);
    multiplica_matriz_vetor(mat, vet_soma);
    printf("\nMATRIZ MODIFICADA :)\n\n");
    printMatriz(mat);
}
*/

/*Exercício 7
#define linha 3
#define coluna 4

void criaMatriz(int mat[][coluna])
{
    int i, j;
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            mat[i][j] = rand() %100;
        }
    }
}

int busca(int numero, int mat[][coluna])
{
    int i, j;
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            if (numero == mat[i][j])
            {
                return numero;
            }
        }
    }
    return -1;
}

void printMatriz(int mat[][coluna])
{
    printf("Demonstração da matriz: \n");
    int i, j;

    for (i=0;i<linha;i++)
    {
        printf("| ");
        for (j=0;j<coluna;j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int mat[linha][coluna], mat2[linha][coluna], i, j, achou;
    printf("Gerando matriz 1...\n");
    criaMatriz(mat);
    printMatriz(mat);
    printf("Gerando matriz 2...\n");
    criaMatriz(mat2);
    printMatriz(mat2);
    printf("\nNúmeros existentes nas duas matrizes:\n");
    printf("| ");
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            achou = busca(mat[i][j], mat2);
            if (achou != -1)
            {
                printf("%d ", achou);
            }
        }
    }
    printf("|");
}
*/

/*Exercício 8
void contaEspaço(char string[], int *contador)
{
    *contador = 1;
    int i;
    for (i=0;i<strlen(string);i++)
    {
        if (string[i] == ' ')
        {
            *contador += 1;
        }
    }
}

int main()
{
    int contador=0;
    char string[50];
    printf("Digite uma frase: ");
    gets(string);
    contaEspaço(string, &contador);
    printf("\nA frase digitada possui %d palavras.\n", contador);
}
*/
