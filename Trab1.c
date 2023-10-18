#include <stdio.h>
#include <stdlib.h>
#define max 100
#include <locale.h>

typedef struct
{
    int codigo;
    char nome[40], cargo[40];
} Funcionario;

int menu()
{
    int opcao;
    printf("Menu de opções:\n");
    printf("\t1. Inserir funcionário\n\t2. Consultar funcionário\n");
    printf("\t3. Excluir funcionário\n\t4. Alterar funcionário\n\t5. Sair\n");
    scanf("%d", &opcao);
    return opcao;
}

int inserir_funcionario(Funcionario vet_func[], int *cont)
{
    if (*cont < max)
    {
        printf("Entre com o código do funcionário: ");
        scanf("%d", &vet_func[*cont].codigo);
        fflush(stdin);
        printf("\nEntre com o nome do funcionário: ");
        scanf("%s", vet_func[*cont].nome);
        printf("\nEntre com o cargo do funcionário: ");
        scanf("%s", vet_func[*cont].cargo);
        (*cont)++;
        return 1;
    }
    return 0;
}

int buscar(Funcionario vet_func[], int codigo, int cont)
{
    int i;
    for (i = 0; i < cont; i++)
    {
        if (vet_func[i].codigo == codigo)
        {
            return i;
        }
    }
    return -1;
}

int alterar_funcionarios(Funcionario vet_func[], int codigo, int cont)
{
    int num_funcionario;
    num_funcionario = buscar(vet_func, codigo, cont);
    if (num_funcionario != -1)
    {
        printf("\nDigite o nome do funcionário: ");
        scanf("%s", vet_func[num_funcionario].nome);
        printf("\nDigite o cargo do funcionário: ");
        scanf("%s", vet_func[num_funcionario].cargo);
        return 1;
    }
    else
    {
        return 0;
    }
}

int excluir_funcionarios(Funcionario vet_func[], int codigo, int *cont)
{
	int num_funcionario, i, proximo;
	num_funcionario = buscar(vet_func, codigo, *cont);
	if (num_funcionario != -1)
	{
		for (i=num_funcionario;i-1<(*cont);i++)
		{
			vet_func[i] = vet_func[i+1];
		}
		(*cont)--;
		return 1;
	}
	else
	{
		return 0;
	}
}


void imprimir_funcionarios(Funcionario vet_func[], int cont)
{
    int i;
    //system("cls");
    for (i = 0; i < cont; i++)
    {
        printf("Código: %d | Nome: %s | Cargo: %s\n", vet_func[i].codigo, vet_func[i].nome, vet_func[i].cargo);
    }
    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Funcionario func[max];
    int result, cont = 0, opcao, codigo;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            printf("Inserindo um funcionário...\n");
            result = inserir_funcionario(func, &cont);
            if (result)
            {
                printf("Funcionário inserido com sucesso!\n");
            }
            else
            {
                printf("Não foi possível inserir o funcionário.\n");
            }
            break;
        case 2:
            printf("Imprimindo funcionários...\n");
            imprimir_funcionarios(func, cont);
            break;
        case 3:
            printf("Excluindo um funcionário...\n");
            printf("Insira o código do funcionário que quer excluir: ");
            scanf("%d", &codigo);
            result = excluir_funcionarios(func, codigo, &cont);
            if (result)
            {
                printf("\nFuncionário excluído com sucesso!\n");
            }
            else
            {
                printf("\nNão foi possível excluir o funcionário.\n");
            }
            break;
        case 4:
            printf("Alterando um funcionário...\n");
            printf("Insira o código do funcionário que quer alterar: ");
            scanf("%d", &codigo);
            result = alterar_funcionarios(func, codigo, cont);
            if (result)
            {
                printf("\nFuncionário alterado com sucesso!\n");
            }
            else
            {
                printf("\nNão foi possível alterar o funcionário.\n");
            }
            break;
        case 5:
            printf("\nEncerrando o programa...\n");
            break;
        default:
            printf("\nOpção inválida...\n");
        }
    } while (opcao != 5);
}