#include <stdlib.h>
#include <stdio.h>

int selectionSort(int *vetor, int n)
{
    int i, j, aux;
    int indice_menor;
    int qtd_comparacao = 0;
    //Ordenando de forma crescente
    for (i=0;i<n-1;i++) // laço com a quantiade de elementos do vetor -1
    {
        indice_menor = i; //guarda a posição do menor elemento de cada iteração
        for (j=i+1;j<n;j++)
        {
            qtd_comparacao += 1;
            if (vetor[j] < vetor[indice_menor])
                indice_menor = j;
        }
        aux = vetor[i];
        vetor[i] = vetor[indice_menor];
        vetor[indice_menor] = aux;
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
    int qtd_comparacao = selectionSort(vet, qtd);
    printVet(vet, qtd);
    printf("\nQuantidade de comparações: %d\n", qtd_comparacao);
}