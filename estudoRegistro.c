#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define max 3

/*Exercício 1
struct Funcionario
{
    int codigo;
    char cargo[40];
    int dependentes;
    float salario;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct Funcionario p;
    //cadastro
    printf("Vamos realizar seu cadastro...\n");
    printf("Digite seu código: ");
    scanf("%d", &p.codigo);
    printf("Digite seu cargo: ");
    fflush(stdin);
    gets(p.cargo);
    printf("Digite a quantidade de dependentes: ");
    scanf("%d", &p.dependentes);
    printf("Digite seu salário: ");
    scanf("%f", &p.salario);

    //imprimindo
    printf("Conferindo os dados...\n");
    printf("Código %d | Cargo: %s \n", p.codigo, p.cargo);
    printf("Dependentes: %d | Salário: %.2f\n", p.dependentes, p.salario);

    //editar
    int opcao;
    printf("Se deseja editar os dados, digite 1, caso contrário, 0: ");
    scanf("%d", &opcao);
    
    switch (opcao)
    {
        case 1:
            printf("Você escolheu editar os dados...\n");
            fflush(stdin);
            printf("Digite seu cargo: ");
            gets(p.cargo);
            printf("Digite seu salário: ");
            scanf("%f", &p.salario);
            //imprimindo
            printf("Dados finais...\n");
            printf("Código %d | Cargo: %s \n", p.codigo, p.cargo);
            printf("Dependentes: %d | Salário: %.2f\n", p.dependentes, p.salario);
            break;
        case 0:
            printf("Você escolheu não editar os dados...\n");
            printf("Dados finais...\n");
            printf("Código %d | Cargo: %s \n", p.codigo, p.cargo);
            printf("Dependentes: %d | Salário: %.2f\n", p.dependentes, p.salario);
            break;
        default:
            printf("Código inválido :(");
            break;
    }
}
*/

//Exercício 2
struct Pessoa
{
    float salario;
    char sexo;
    int idade;
    int filhos;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct Pessoa p[max];
    float maiorSalario, menorSalario, mediaSalarios=0, mediaFilhos=0, mulherSuperior=0;
    printf("Cadastrando pessoa 1...\n");
    printf("Salário: ");
    scanf("%f", &p[0].salario);
    fflush(stdin);
    printf("Sexo: ");
    scanf("%c", &p[0].sexo);
    printf("Idade: ");
    scanf("%d", &p[0].idade);
    printf("Quantidade de filhos: ");
    scanf("%d", &p[0].filhos);
    maiorSalario = p[0].salario;
    menorSalario = p[0].salario;
    mediaSalarios += p[0].salario;
    mediaFilhos += p[0].filhos;
    if (p[0].sexo == 'f' || p[0].sexo == 'F')
    {
        if (p[0].salario > 1500)
        {
            mulherSuperior += 1;
        }
    }
    int i;
    for (i=1;i<max;i++)
    {
        printf("Cadastrando pessoa %d...\n", i+1);
        printf("Salário: ");
        scanf("%f", &p[i].salario);
        fflush(stdin);
        printf("Sexo: ");
        scanf("%c", &p[i].sexo);
        printf("Idade: ");
        scanf("%d", &p[i].idade);
        printf("Quantidade de filhos: ");
        scanf("%d", &p[i].filhos);
        if (p[i].salario > maiorSalario)
        {
            maiorSalario = p[i].salario;
        }
        else
        {
            if (p[i].salario < menorSalario)
            {
                menorSalario = p[i].salario;
            }
        }
        if (p[i].sexo == 'f' || p[i].sexo == 'F')
        {
            if (p[i].salario > 1500)
            {
                mulherSuperior += 1;
            }
        }
        mediaSalarios += p[i].salario;
        mediaFilhos += p[i].filhos;
    }
    mediaSalarios = mediaSalarios / max;
    mediaFilhos = mediaFilhos / max;
    mulherSuperior = (mulherSuperior / max) * 100;

    //imprimindo
    printf("\nMédia de salários: %.2f\n", mediaSalarios);
    printf("Média de filhos: %.0f\n", mediaFilhos);
    printf("Maior salário: %.2f | Menor salário: %.2f\n", maiorSalario, menorSalario);
    printf("Porcentagem de mulheres que ganham mais de 1500: %.2f", mulherSuperior);
}