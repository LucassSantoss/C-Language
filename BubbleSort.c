#include <stdlib.h>
#include <stdio.h>

int bubbleSort(int *vetor, int n)
{
    int i, j, aux, qtd_comparacao = 0;
    int trocou = 1; //indica se houve troca
    //Ordenando de forma crescente
    for (i=n-1; i>=1 && trocou; i--)
    {
        trocou = 0;
        for (j=0; j<i; j++)
        {
            qtd_comparacao += 1;
            if (vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                trocou = 1;
            }
        }
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
    int qtd_comparacao = bubbleSort(vet, qtd);
    printVet(vet, qtd);
    printf("\nQuantidade de comparações: %d\n", qtd_comparacao);
}