#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

/*Exercício 2
struct Habitante
{
	int idade, filhos;
	float salario;
	char sexo;
};
 
int main()
{
	setlocale(LC_ALL, "Portuguese");
	struct Habitante habitantes[20];
	int i;
	float mediaSalarios=0, mediaFilhos=0, maiorSalario=0, menorSalario, mulherSuperior=0;
	printf("Habitante 1:\n");
	printf("Idade: ");
	scanf("%d", habitantes[0].idade);
	printf("\nQuantidade de filhos: ");
	scanf("%d", &habitantes[0].filhos);
	printf("\nSalário: ");
	scanf("%f", &habitantes[0].salario);
	printf("Sexo: ");
	scanf("%c", habitantes[0].sexo);
	maiorSalario = habitantes[0].salario;
	menorSalario = habitantes[0].salario;
	mediaSalarios += habitantes[0].salario;
	mediaFilhos += habitantes[0].filhos;
	if (habitantes[0].sexo == 'F' && habitantes[0].salario > 1500)
	{
		mulherSuperior += 1;
	}
	for (i=1;i<20;i++)
	{
		printf("Habitante %d:\n", i+1);
		printf("Idade: ");
		scanf("%d", habitantes[i].idade);
		printf("\nQuantidade de filhos: ");
		scanf("%d", &habitantes[i].filhos);
		printf("\nSalário: ");
		scanf("%f", &habitantes[i].salario);
		printf("\nSexo: ");
		scanf("%c", &habitantes[i].sexo);
		if (habitantes[i].salario > maiorSalario)
		{
			maiorSalario = habitantes[i].salario;
			else
			{
			if (habitantes[i].salario < menorSalario)
			{
				menorSalario = habitantes[i].salario;
			}
		}
	}
	mediaSalarios += habitantes[i].salario;
	mediaFilhos += habitantes[i].filhos;
	if (habitantes[i].sexo == 'F' && habitantes[i].salario > 1500)
	{
		mulherSuperior += 1;
	}
	} 
	mediaSalarios = mediaSalarios/20;
	mediaFilhos = mediaFilhos/20;
	printf("Media de salário: %f\n", mediaSalarios);
	printf("Media de filhos: %f\n", mediaFilhos);
	printf("Maior salário: %d | Menor salário: %f\n", maiorSalario, menorSalario);
	printf("Quantidade de mulheres que recebem mais de 1500: %d", mulherSuperior);
}

*/

/*Exercício 3
int buscar(char string[], char letra)
{
    int i;
    for (i=0;i<(strlen(string)-1);i++)
    {
        if (string[i] == letra)
        {
            return i;
        }
    }
    return -1;
}

void remover(char string[], int indice)
{
    int i;
    for (i=indice;i<strlen(string)-1;i++)
    {
        string[i] = string[i+1];
    }
	string[strlen(string)-1] = '\0';
}


int main()
{
    char string[50], letra;
    printf("Digite uma palavra: ");
    gets(string);
    printf("Digite a letra que quer remover dessa palavra: ");
    scanf("%c", &letra);
    int resultadoBuscar;
    resultadoBuscar = buscar(string, letra);
    if (resultadoBuscar != -1)
    {
        remover(string, resultadoBuscar);
        printf("\nA sua palavra com a letra removida é: %s\n", string);
    }
    else
    {
        printf("\nEssa palavra não contém essa letra...\n");
    }
    system("pause");
}
*/

/*Exercício 4
int negativos(int lista[])
{
	int i;
	for (i=0;i<10;i++)
	{
		if (lista[i] < 0)
		{
			lista[i] = 0;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int lista[10], i;
	printf("Digite 10 números inteiros: \n");
	for (i=0;i<10;i++)
	{
		printf("%d: ", i+1);
		scanf("%d", &lista[i]);
	}
	negativos(lista);
	//print
	for (i=0;i<10;i++)
	{
		printf(" %d |", lista[i]);
	}
}
*/

//Exercício 5
/*
int fatorial(int numero)
{
	int fatorial = 1;
	if (numero != 0)
	{
		int i;
		fatorial = numero;
		for (i=numero-1;i>0;i--)
		{
			fatorial *= i;
		}
	}
	return fatorial;
}
*/

/*
int fatorial(int numero)
{
	if (numero == 0)
	{
		return 1;
	}
	return numero * fatorial(numero-1);
}

float calcularSerie(int termos)
{
	int i, numerador = 100;
	float resultado = 0;
	printf("Soma = ");
	for (i=0;i<termos;i++)
	{
		resultado += numerador / fatorial(i);
		printf("%d/%d! + ", numerador, i);
	}
	return resultado;
}

int main()
{
	float resultado;
	resultado = calcularSerie(10);
	printf("\nResultado: %.2f\n", resultado);
}
*/



//Exercicio 6
/*
int anagrama(char str1[], char str2[])
{
	int anagrama=1, contador1=0, contador2=0;

	int i, j, k;
	//converte para minuscula
	str1 = strlwr(str1);
	str2 = strlwr(str2);
	for (i=0;i<(strlen(str1)) && anagrama == 1;i++)
	{
		contador1 = 0;
		contador2 = 0;
		//remove espaço
		if (str1[i] == ' ')
		{
			i++;
		}
		for (j=0;j<strlen(str1);j++)
		{
			//remove espaço
			if (str1[j] == ' ')
			{
				j++;
			}
			if (str1[i] == str1[j])
			{
				contador1++;
			}
		}
		for (k=0;k<strlen(str2);k++)
		{
			//remove espaço
			if (str2[k] == ' ')
			{
				k++;
			}
			if (str1[i] == str2[k])
			{
				contador2++;
			}
		}
		if (contador1 != contador2)
		{
			anagrama = 0;
		}
	}
	return anagrama;
}
*/

int contarCaracteres(char caractere, char string[])
{
	int i, cont=0;
	for (i=0;i<strlen(string);i++)
	{
		if (caractere == string[i])
		{
			cont++;
		}
	}
	return cont;
}

int anagrama(char str1[], char str2[])
{
	int i=0, cont1=0, cont2=0;
	while(i < strlen(str1)){
		if(str1[i] != ' ')
		{
			cont2 = contarCaracteres(str1[i], str2);
			if(cont2 == 0)
			{
				return 0;
			}
			else
			{
				cont1 = contarCaracteres(str1[i], str1);
				if(cont1 != cont2)
				{
					return 0;                                      
				}
			}	
		}
		i++;
	}
	return 1;
}


int main()
{
	setlocale(LC_ALL, "Portuguese");
	char string1[50], string2[50];
	printf("Digite uma palavra: ");
	gets(string1);
	printf("\nDigite outra palavra: ");
	gets(string2);
	strlwr(string1);
	strlwr(string2);
	if (anagrama(string1, string2) == 1)
	{
		printf("\nEssas palavras são anagramas!!\n");
	}
	else
	{
		printf("\nEssas palavras não são anagramas :(\n");
	}
}




/*Exercício de fixação
int Delta(float a, float b, float c)
{
	float resultado;
	resultado = (pow(b, 2)) - (4 * a * c);
	return resultado;
}

int Raiz(float a, float b)
{
	float resultado;
	resultado = (-b) / (2*a);
	return resultado;
}

int DuasRaizes(float delta, float a, float b, float resultado[2])
{
	resultado[0] = (-b + sqrt(delta)) / (2 * a);
	resultado[1] = (-b - sqrt(delta)) / (2 * a);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	float a, b, c, delta, duasRaizes[2], raiz;
	printf("Digite o A da sua função quadrada: ");
	scanf("%f", &a);
	printf("Digite o B da sua função quadrada: ");
	scanf("%f", &b);
	printf("Digite o C da sua função quadrada: ");
	scanf("%f", &c);

	delta = Delta(a, b, c);

	if (delta > 0)
	{
		DuasRaizes(delta, a, b, duasRaizes);
		printf("Existem duas raízes reais, que são %.2f e %.2f", duasRaizes[0], duasRaizes[1]);
	}
	else
	{
		if (delta == 0)
		{
			raiz = Raiz(a, b);
			printf("A raiz real é = %.2f", raiz);
		}
		else
		{
			printf("Não existe raiz real :(");	
		}
	}
}
*/