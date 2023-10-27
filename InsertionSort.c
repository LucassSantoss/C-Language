#include <stdlib.h>
#include <stdio.h>

int insertionSort(int *vetor, int n)
{
    int i, j;
    int aux;
    int qtd_comparacao = 0;
    for (i=1;i<n;i++)
    {
        aux = vetor[i]; // guarda o elemento atual em aux
        //laço que percorre o elemento à esquerda do número até encontrar a posição
        for (j=i-1; j>=0 && aux<vetor[j]; j--)
        {
            qtd_comparacao += 1;
            vetor[j+1] = vetor[j]; // a cada passo o elemento da posição j é deslocado para a posição seguinte (direita)
        }
        vetor[j+1] = aux;
    }
    return qtd_comparacao;
}

void printVet(int vetor[], int n)
{
    printf("Imprimindo seu vetor: \n| ");
    for (int i=0; i<n; i++)
    {
        printf("%d | ", vetor[i]);
    }
}

int main()
{
    int vet[] = {117, 12, 93, 50, 44, 15, 101, 77, 33, 25, 02, 81};
    int qtd = 12;
    int qtd_comparacao = insertionSort(vet, qtd);
    printVet(vet, qtd);
    printf("\nQuantidade de comparações: %d\n", qtd_comparacao);
}