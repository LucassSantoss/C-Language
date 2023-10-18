#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Exercício 1
int *criaVetor(int n)
{
    int *vet;
    vet = (int *) malloc(n * sizeof(int));
    int i;
    printf("Preenchendo a lista...\n");
    for (i=0;i<n;i++)
    {
        printf("Número %d: ", i+1);
        scanf("%d", vet+i);
    }
    return vet;
}

void printPonteiro(int *ponteiro, int n)
{
    int i;
    printf("\n| ");
    for (i=0;i<n;i++)
    {
        printf("%d | ", *(ponteiro+i));
    }
    printf("\n");

}

void limpaMem(int *ponteiro)
{
    free(ponteiro);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n, *ponteiroLista;
    printf("Digite a quantidade de elementos da sua lista: ");
    scanf("%d", &n);
    ponteiroLista = criaVetor(n);
    printf("\nPonteiro da lista: %d\n", ponteiroLista);

    printPonteiro(ponteiroLista, n);

    limpaMem(ponteiroLista);
}
*/

//Exercício 2
int *criaMatriz(int m, int n)
{
    int *mat;
    mat = (int *) malloc(m * n * sizeof(int));
    int i;
    for (i=0;i<(m*n);i++)
    {
        printf("Elemento %d: ", i+1);
        scanf("%d", mat+i);
    }
    return mat;
}

void limpaMem(int *ponteiro)
{
    free(ponteiro);
    printf("Memória liberada!!\n");
}

void printMat(int *ponteiro, int m, int n)
{
    int i, cont=0;
    for (i=0;i<(m*n);i++)
    {
        if (i % n == 0)
        {
            printf("\n| ");
        }
        printf("%d | ", *(ponteiro + i));
    }
    printf("\n\n\n");
}

int main()
{
    int m, n, *pontMatriz;
    printf("Insira a quantidade de linhas da matriz: ");
    scanf("%d", &m);
    printf("Insira a quantidade de colunas da matriz: ");
    scanf("%d", &n);
    pontMatriz = criaMatriz(m, n);
    printf("\nPonteiro da matriz: %d\n\n", pontMatriz);
    printMat(pontMatriz, m, n);
    limpaMem(pontMatriz);
}