#include <stdio.h>
#include <locale.h>



/*Exercício 4
#define linha 3
#define coluna 3

int Identidade(int mat[][coluna])
{
    int i, j;
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            if (i == j && mat[i][j] != 1)
            {
                return 0;
            }
            else
            {
                if (i != j && mat[i][j] != 0)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void criaMatriz(int mat[][coluna])
{
    printf("Criando sua matriz: \n");
    int i, j;
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            printf("Digite o termo [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int mat[linha][coluna], identidade;
    criaMatriz(mat);
    identidade = Identidade(mat);
    if (identidade)
    {
        printf("\n Essa matriz é identidade\n");
    }
    else
    {
        printf("\nEssa matriz não é identidade\n");
    }
}
*/

//Exercício 5
#define linhaA 3
#define ColunaA_LinhaB 2
#define colunaB 3

void criaMatrizA(int mat[][ColunaA_LinhaB])
{
    printf("Criando sua matriz 1: \n");
    int i, j;
    for (i=0;i<linhaA;i++)
    {
        for (j=0;j<ColunaA_LinhaB;j++)
        {
            printf("Digite o termo [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n\n");
}

void criaMatrizB(int mat[][colunaB])
{
    printf("Criando sua matriz 2: \n");
    int i, j;
    for (i=0;i<ColunaA_LinhaB;i++)
    {
        for (j=0;j<colunaB;j++)
        {
            printf("Digite o termo [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n\n");
}

void multiplicaMatriz(int mat1[][ColunaA_LinhaB], int mat2[][colunaB], int mat3[][colunaB])
{
    int i, j, k;
    for (i=0;i<linhaA;i++)
    {
        for (j=0;j<colunaB;j++)
        {
            mat3[i][j] = 0;
            for (k=0;k<ColunaA_LinhaB;k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatriz(int mat[][colunaB])
{
    int i, j;
    printf("\nMatriz resultante da multiplicação: \n");
    for (i=0;i<linhaA;i++)
    {
        printf("| ");
        for (j=0;j<colunaB;j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("|\n");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int matA[linhaA][ColunaA_LinhaB], matB[ColunaA_LinhaB][colunaB];
    int matC[linhaA][colunaB];
    criaMatrizA(matA);
    criaMatrizB(matB);
    multiplicaMatriz(matA, matB, matC);
    printMatriz(matC);
    printf("\n");
}