#include <iostream>
#include <Windows.h>


int main() 
{
	/*	
	matrizJogo é a matriz que o jogader vê durante a partida e atualiza
	de acordo com as tentativas do jogador
	*/
	const int maxLinha{ 10 }, maxColuna{ 10 };
	char matrizJogo[maxLinha][maxColuna]{}, matrizResposta[maxLinha][maxColuna]{};

	for (int i{ 0 }; i < maxLinha; i++)
	{
		for (int j{ 0 }; j < maxColuna; j++)
		{
			matrizJogo[i][j] = '~';

			/*
			if (i == 2 && j == 0)//posição arbitraria de resposta para teste
			{
				matrizResposta[i][j] = '*';
			}
			*/
		}
	}

	//tentativas é usado ao fim do loop de jogo principal
	int tentativas{10};
	int linha{};
	int coluna{};

	//loop de game principal
	do 
	{
		for (int i = 0; i < maxLinha; i++)
		{
			std::cout << "\t\t\t\t\t\t";
			for (int j = 0; j < maxColuna; j++)
			{
				std::cout << matrizJogo[i][j] << " ";
			}
			std::cout << '\n';
		}

		//variaveis de posição da matriz usada durante jogo  
		std::cout << "Insira linha: ";
		std::cin >> linha;

		std::cout << "insira coluna: ";
		std::cin >> coluna;

		matrizJogo[linha - 1][coluna - 1] = '*';

		//Verificação de acerto ou erro de tiro
		if (matrizJogo[linha - 1][coluna - 1] == matrizResposta[linha - 1][coluna - 1])
		{
			//Acerto
			matrizJogo[linha - 1][coluna - 1] = 'v';

			tentativas += 2;
			std::cout << "Tentativas: " << tentativas << '\n';
		}
		else
		{
			//Erro
			matrizJogo[linha - 1][coluna - 1] = 'x';

			tentativas--;
			std::cout << "Tentativas: " << tentativas << '\n';
		}

		system("pause");
		system("cls");

	} while (tentativas > 0);

	if (tentativas == 0)
	{
		std::cout << "zero tentativas" << std::endl;
	}

	return 0;
}


/*		Requisitos funcionais
* 
*	[x] Matris 10x10 para campo de jogo
*	[x] Matris 10x10 para respostas 
*	[ ] Geração dos alvos no campo para serem encontrados
*	[ ] Aleatorizar a posição dos alvos no campo de forma ordenada
*	[x] Recebeer 2 valores do jogador para indicar qual posição do campo atacar
*	[x] Traduzir os dois valores para pontos no campo de jogo e campo de resposta
*	[x] Comparar posições no campo principal e de resposta para confirmar 
*		um acerto ou erro
*	[x] Contagem de acertos e erros de jogador
*	[ ] Checar se jogador não colocou posição inválida na entrada de valores
*	[ ] Verificar se jogador repetiu valores na entrada de valores
*	{ } Interface de menu principal
*	{ } Salvamento de pontuação
*	{ } Tabela das 10 pontuações mais altas
*	{ } Salvar iniciais do jogador para fácil distinção na tabela de pontuação
*	{ }	Implementar seleção de dificuldade
*	{ } Dificuldade personalizada
* 
*	[ ] = requisito ainda a ser cumprido
*	[x] = requisito cumprido
*	{ } = requisito opcional ainda a ser alcançado
*	{x} = requisito opcional cumprido
*/