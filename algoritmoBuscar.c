#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//Algoritmo Sequencial
int algoritmoSequencial(int vetor[], int numero)
{
    int achou = 0, i;
    for (i=0;i<500 && achou == 0;i++)
    {
        if (vetor[i] == numero)
        {
            return i;
        }
    }
    return -1;
}

//Função que ordena vetores
void ordena(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i; j < tamanho; j++)
        {
            if (vetor[i] > vetor[j])
            {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

//Algoritmo binário
int binario(int vetor[], int elemento, int inicio, int fim)
{
    if (inicio > fim)
        return -1;
    int meio = (inicio + fim) / 2; // ponto médio
    if (elemento == vetor[meio])
        return meio;
    else if (elemento > vetor[meio])
        return binario (vetor, elemento, meio + 1, fim);
    else if (elemento < vetor[meio])
        return binario(vetor, elemento, inicio, meio - 1);
    else
        return -1;
}


int main()
{
    srand(time(NULL));
    int vetor[500], i, resultado;
    for (i=0;i<500;i++)
    {
        vetor[i] = rand() % 500;
    }

    int numero;
    printf("Digite o número que deseja procurar: ");
    scanf("%d", &numero);

    //Algoritmo sequencial
    printf("\nAlgoritmo Sequencial:\n");
    resultado = algoritmoSequencial(vetor, numero);
    if (resultado != -1)
    {
        printf("\nO número que você digitou está no índice %d\n", resultado);
    }
    else
    {
        printf("\nEsse número não está na lista :(\n");
    }

    //Algoritmo Binário
    printf("\nAlgoritmo Binário:\n");
    ordena(vetor, 500);
    resultado = binario(vetor, numero, 0, 500);
    if (resultado != -1)
    {
        printf("\nO número que você digitou está no índice %d\n", resultado);
    }
    else
    {
        printf("\nEsse número não está na lista :(\n");
    }
}

