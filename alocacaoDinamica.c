#include <stdio.h>
#include <stdlib.h>

/*Exercício 1
typedef struct
{
    int dia, mes, ano;
} data;

int main()
{
    data *d; // cria ponteiro para o tipo data
    d = (data *) malloc(sizeof(data)); // aloca memória dinamicamente para o registro data
    d->ano = 2023; // ponteiro para o registro operador ->
    d->dia = 20;
    d->mes = 9;
    printf("Data de hoje: %d/%d/%d.\n", d->dia, d->mes, d->ano);
    free(d);
}
*/

/*Exercício 2
int main()
{
    int *v, n, i;
    scanf("%d", &n);
    v = (int *) calloc (n, sizeof (int)); // aloca n * sizeof(int)
    if (v != NULL)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d", &v[i]);
        }
        for (i=n;i>0;i--)
        {
            printf("%d", v[i-1]);
        }
        free(v);
    }
}
*/

//Exercício 3
int main()
{
    int *p, n, i;
    printf("Quantos números desja no vetor?\n");
    scanf("%d", &n);
    p = (int *) malloc(n * sizeof(int));
    if (!p)
    {
        printf("Erro: memória insuficiente");
        exit(0);
    }
    for (i=0;i<n;i++)
    {
        p[i] = i*i;
        printf("%d\n", p[i]);
    }
    printf("Quantos números deseja no vetor?\n");
    scanf("%d", &n);
    p = (int *) realloc (p, n*sizeof(int));
    for (i=0;i<n;i++)
    {
        p[i] = n*i;
        printf("%d\n", p[i]);
    }
    for (i=0;i<n;i++)
    {
        printf("%d, ", p[i]);
    }
    free(p);
}