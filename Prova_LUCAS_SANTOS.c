/* PROVA DE APR2 - Bacharelado em Engenharia de Software - II sem de 2023

	Lucas Pereira dos Santos | SC 3037916
	
	ATEN��O: VOC� N�O DEVE MODIFICAR OS PROT�TIPOS DAS FUN��ES. 
	N�o ser� permitido o uso de vari�veis globais dentro das fun��es. 
*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#define n 3

typedef struct {
	int cod_passagem;
	int num_poltrona;
	char nome[40];
	char origem[30], destino[30]; 
} Passageiro;

void printMatriz(int mat[][n])
{
	int i, j;
	printf("\n");
	for (i=0;i<n;i++)
	{
		printf("| ");
		for (j=0;j<n;j++)
		{
				printf("%d ", mat[i][j]);
		}
		printf("|\n");
	}
	printf("\n\n");
}

/*QUEST�O 1 (2.0): Fa�a uma fun��o que receba por par�metro uma frase e verifica
se ela � um pal�ndromo. A fun��o dever� retornar 1, se for uma frase pal�ndromo e 0, 
caso contr�rio. A mensagem indicando se � ou n�o um pal�ndromo dever� ser impressa
pelo programa principal. OBS: Ignore mai�sculas e min�sculas, acentua��o, espa�os, h�fen e pontua��o.
Exemplos: 'Anotaram a data da maratona', 'Socorram-me subi no �nibus em Marrocos', 'A grama � amarga' */ 

int palindromo(char string[])
{
	strlwr(string);
	int i, j = strlen(string) - 1;
	for (i=0;i<strlen(string);i++)
	{
		if (string[i] == ' ')
		{
			i++;
		}
		if (string[j] == ' ')
		{
			j--;
		}
		if (string[i] != string[j])
			{
				return 0;
			}
		j--;
	}
	return 1;
}

/*QUEST�O 2 (1.5): Fa�a uma fun��o que receba por par�metro um vetor V contendo N elementos
inteiros, um inteiro N, indicando o total de elementos do vetor, uma matriz A de tamanho N x N 
de elementos inteiros e um valor inteiro I, tal que 0 <= I < N. 
Em seguida, dever� substituir os elementos da I-�sima linha da matriz A pelos elementos do vetor V e 
apresentar a matriz A modificada.*/ 
void substituir_linha_matriz(int V[], int A[][n], int I) 
{
	int j;
	for (j=0;j<n;j++)
	{
		A[I][j] = V[j];
	}
	
}

/*QUEST�O 3 (2.0): Fa�a uma fun��o que receba por par�metro uma matriz A de n�meros inteiros de 
tamanho N x N. Em seguida, a fun��o dever� calcular e apresentar a matriz transposta de A (At). 
A matriz transposta � obtida reposicionando-se as linhas no lugar das colunas e, consequentemente, 
as colunas no lugar das linhas (conforme no exemplo). Para fazer a transposi��o (o reposicionamento)
esta fun��o dever� usar a fun��o substituir_linha_matriz() da QUEST�O 2. 
A = 6 1 8		At = 6 7 2
	7 5 3			 1 5 9
	2 9 4			 8 3 4

 */
 
void calcular_matriz_transposta(int A[][n])
{
	int matriz2[n][n], i, j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			matriz2[i][j] = A[i][j];
		}
	}
	
	int vetorColuna[n];
	for (i=0;i<n;i++)
	{
		vetorColuna[0] = matriz2[0][i];
		vetorColuna[1] = matriz2[1][i];  
		vetorColuna[2] = matriz2[2][i]; 
		substituir_linha_matriz(vetorColuna, A, i);
	}
}

/*QUEST�O 4 (1.5): Implemente a fun��o inserir_passageiro_voo que recebe por par�metro um ponteiro para um vetor
com capacidade para at� 160 registros de passageiros e um ponteiro para a posi��o do vetor na qual o registro 
ser� inserido pela fun��o. A fun��o dever� retornar 1, caso o registro tenha sido inclu�do com sucesso e -1, 
caso contr�rio. A mensagem informando se o registro foi inclu�do com sucesso
ou n�o ser� impressa na fun��o submenu_voo().*/
int inserir_passageiro_voo(Passageiro Vetor[], int *i) 
{   
	int contAntigo = (*i);
	printf("\nInsira o c�digo de passagem: ");
	scanf("%d", &Vetor[(*i)].cod_passagem);
	printf("Insira o n�mero da poltrona: ");
	scanf("%d", &Vetor[(*i)].num_poltrona);
	fflush(stdin);
	printf("Insira o nome do passageiro: ");
	gets(Vetor[(*i)].nome);
	printf("Insira a origem do passageiro: ");
	gets(Vetor[(*i)].origem);
	printf("Insira o destino do passageiro: ");
	gets(Vetor[(*i)].destino);
	(*i)++;
	printf("\nContador de passageiros: %d\n", (*i));
	if ((*i) == contAntigo + 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/*QUEST�O 5 (1.0): Implemente a fun��o buscar_passageiro que receba por par�metro um ponteiro para um vetor
com registros de passageiros, o c�digo da passagem e contador indicando a quantidade de passageiros armazenados
no vetor. A fun��o dever� retornar a posi��o do registro do passageiro no vetor, caso ele exista e
-1, caso contr�rio. A mensagem informando que o c�digo n�o foi encontrado (quando acontecer) deve ser impressa no 
submenu_voo().*/
int buscar_passageiro(Passageiro Voo[], int codigo, int cont)
{	
	printf("\nBuscando um passageiro no voo:\n");
	int i;
	while (Voo[i].cod_passagem != '\0')
	//for (i=0;i<160;i++)
	{
		if (Voo[i].cod_passagem == codigo)
		{
			return i;
		}
		i++;
	}
	return -1;
	
	
}
/*QUEST�O 6 (1.0): Implemente a fun��o imprimir_passageiro() que receba por par�metro um ponteiro para um vetor
com registros de passageiros e o contador de registros cadastrados. A fun��o dever� solicitar o c�digo da passagem 
como entrada e dever� transferir esse c�digo, juntamente com o vetor de passageiros, por par�metros para a fun��o 
buscar_passageiro(), que verificar� se esse c�digo est� cadastrado. Se o retorno da fun��o buscar_passageiro() 
for maior ou igual a zero (ou seja, um �ndice v�lido), a fun��o imprimir_passageiro() dever� imprimir o nome do 
passageiro, o n�mero da poltrona, a origem e o destino. Caso o retorno seja -1, apresente uma mensagem informando que
o c�digo da passagem n�o foi localizado.*/
void imprimir_passageiro(Passageiro Voo[], int cont)
{	
	int codigo, achou;
	printf("Digite o c�digo do passageiro: ");
	scanf("%d", &codigo);
	achou = buscar_passageiro(Voo, codigo, cont);
	if (achou != -1)
	{
		printf("\nNome: %s\n", Voo[achou].nome);
		printf("N�mero da poltrona: %d\n", Voo[achou].num_poltrona);
		printf("Origem: %s\n", Voo[achou].origem);
		printf("Destino: %s\n", Voo[achou].destino);
		printf("C�digo: %d\n\n", Voo[achou].cod_passagem);
	}
	else
	{
		printf("\nO c�digo do passageiro n�o foi encontrado\n");
	}
}	 		

//Fun��o menu(): fun��o que apresenta o menu de op��es para o usu�rio
void menu(){
	printf("**************Menu de Op��es:****************\n\n");
	printf("\t1. Verificar frase pal�ndromo\n ");
	printf("\t2. Substituir linha da matriz\n");
	printf("\t3. Calcular matriz transposta\n");
	printf("\t4. Acessar submenu de voo\n");
	printf("\t5. Sair\n");
	printf("\nEscolha uma op��o entre 1 e 4 ou digite 5 para encerrar o programa\n");
}
//Chamada das fun��es: (0.25)
void submenu_voo(Passageiro Voo[], int *cont){
	int op, flag, funcionou;
	
	do
	{		
		printf("**************Submenu de Voo:****************\n\n");
		printf("\t1. Inserir voo\n ");
		printf("\t2. Imprimir dados de um passageiro\n");
		printf("\t3. Voltar ao menu principal\n");
		printf("\nEscolha uma op��o entre 1 e 2 ou digite 3 para voltar ao menu principal\n");
		scanf("%d",&op);
	
		switch (op){
			case 1: system("cls");
				/*INSIRA AQUI A CHAMADA DA FUN��O inserir_passageiro_voo(), RESPEITANDO OS 
				PAR�METROS CONFORME O PROT�TIPO DA FUN��O*/	
				printf("Inserindo um passageiro no voo...\n");
				funcionou = inserir_passageiro_voo(Voo, &(*cont));
				if (funcionou == 1)
				{
					printf("\nPassageiro inserido com sucesso!!\n\n");
				}
				else
				{
					printf("\nPassageiro n�o foi inserido.\n\n");
				}		
				break;	
			case 2: system("cls");
			/*INSIRA AQUI A CHAMADA DA FUN��O imprimir_passageiro(), RESPEITANDO OS 
			PAR�METROS CONFORME O PROT�TIPO DA FUN��O*/
				printf("Imprimindo um passageiro...\n\n");
				imprimir_passageiro(Voo, (*cont));
				break;	
			case 3: system("cls");
				printf("Voltando para o menu principal\n");
				break;
			default: printf("Op��o incorreta!\n");		
		}	
	} while(op >= 1 && op <3);
}

//Chamada das fun��es: (0.75)
main()
{	int op, cont = 0;
	int matriz[n][n] = {{6,1,8},{7,5,3},{2,9,4}};
	int vetor[n] = {5,5,5}; // valores para teste
	int i = 1;
	Passageiro voo[160];  
	setlocale(LC_ALL, "Portuguese");
		
	do
	{	
		menu();
		scanf("%d",&op);
		fflush(stdin);
		switch (op){
			case 1: system("cls");
			   char str[100];			  
			   printf("Digite uma string:\n");
			   gets(str);
			   printf("Verificando se � uma frase pal�ndromo...\n");
			   	/*INSIRA AQUI A CHAMADA DA FUN��O eh_palindromo(), RESPEITANDO OS 
			   PAR�METROS E TRATANDO CORRETAMENTE O VALOR DE RETORNO, SE HOUVER.*/
			   if (palindromo(str))
			   {
			   		printf("Sua frase � um pal�ndromo!!\n\n");
			   }
			   else
			   {
			   		printf("Sua frase n�o � um pal�ndromo.\n\n");
			   }
			   break;
			case 2: system("cls");
				printf("Substituindo uma linha da matriz por um vetor...\n");			  
			   /*INSIRA AQUI A CHAMADA DA FUN��o substituir_linha_matriz(), RESPEITANDO OS 
			   PAR�METROS E O VALOR DE RETORNO (SE HOUVER), CONFORME O PROT�TIPO DA FUN��O*/
			   printf("Matriz antiga: \n");
			   printMatriz(matriz);
			   printf("\nSubstituindo a linha %d\n", i+1);
			   substituir_linha_matriz(vetor, matriz, i);
			   printMatriz(matriz);
			   break;
			case 3: system("cls");
				printf("Calculando a transposta da matriz...\n");
				printf("Matriz antiga: \n");
				printMatriz(matriz);
				printf("Matriz transposta: \n");
				calcular_matriz_transposta(matriz);
				printMatriz(matriz);
				break;
			case 4: system("cls");
				//CHAMANDO O SUBMENU COM OP��ES PARA GERENCIAR VOOS
				submenu_voo(voo,&cont);			
				break;
			case 5: system("cls");
			   printf("\nEncerrando o programa...\n"); 
			   break;
			default: printf("Op��o incorreta!\n");
		}	
	} while (op >= 1 && op <5);	
}

