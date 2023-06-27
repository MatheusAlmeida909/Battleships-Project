#include <iostream>
#include <Windows.h>

int main() 
{
	/*	
	matrizJogo é a matriz que o jogader vê durante a partida e atualiza
	de acordo com as tentativas do jogador
	*/
	const int maxLinha{ 10 }, maxColuna{ 10 };
	char matrizJogo[maxLinha][maxColuna]{};
	char matrizResposta[maxLinha][maxColuna]{};

	for (int i{ 0 }; i < maxLinha; i++)
	{
		for (int j{ 0 }; j < maxColuna; j++)
		{
			matrizJogo[i][j] = '~';
		}
	}

	int qntdNavios{ 7 };

	//Gerador de respostas
	for (int i{ 0 }; i < qntdNavios; i++)
	{
		matrizResposta[/*randomizador*/][/*randomizador*/] = '*';
	}

	for (int i{ 0 }; i < maxLinha; i++)
	{
		for (int j{ 0 }; j < maxColuna; j++)
		{
			if (matrizResposta[i][j] == '*')
			{
				if (i >= 9)
				{
					for (j; j < /*valor aleatório de 2 a 5*/; j--)
					{
						matrizResposta[i][j] == '*';
					}
				}
				else
				{
					for (j; j < /*valor aleatório de 2 a 5*/; j++)
					{

					}
				}
			}
		}
	}
	  
	//tentativas é usado ao fim do loop de jogo principal
	int tentativas{10};

	int acertos{};
	int erros{};

	int linha{};
	int coluna{};

	//loop de game principal
	do 
	{
		for (int i{ 0 }; i < maxLinha; i++)
		{
			std::cout << "\t\t\t\t\t\t";
			for (int j{ 0 }; j < maxColuna; j++)
			{
				std::cout << matrizJogo[i][j] << " ";
			}
			std::cout << '\n';
		}

		/* exibição de resposta para teste
		* 
		* for (int i = 0; i < maxLinha; i++)
		{
			std::cout << "\t\t\t\t\t\t";
			for (int j = 0; j < maxColuna; j++)
			{
				std::cout << matrizResposta[i][j] << " ";
			}
			std::cout << '\n';
		}
		* 
		*/

		do
		{
			std::cout << "Insira linha: " << std::endl;
			std::cin >> linha;

			std::cout << "insira coluna: " << std::endl;
			std::cin >> coluna;
			
			if (matrizJogo[linha - 1][coluna - 1] == 'x' || matrizJogo[linha - 1][coluna - 1] == 'v')
			{
				std::cout << "Você já atirou nessa posição";

				tentativas++;
				
				continue;
			}
			
		} while (linha > maxLinha || linha < 1 || coluna > maxColuna || coluna < 1);
		//limitar entrada so usuário para apenas o numero de linhas e colunas do jogo

		//Marcação para comparar com matrizResposta e decidir acerto ou erro
		matrizJogo[linha - 1][coluna - 1] = '*';

		//Verificação de acerto ou erro de tiro
		if (matrizJogo[linha - 1][coluna - 1] == matrizResposta[linha - 1][coluna - 1])
		{
			//Acerto
			matrizJogo[linha - 1][coluna - 1] = 'v';

			++acertos;

			tentativas += 2;
			std::cout << "Tentativas: " << tentativas << '\n';
		}
		else
		{
			//Erro
			matrizJogo[linha - 1][coluna - 1] = 'x';

			++erros;

			tentativas--;
			std::cout << "Tentativas: " << tentativas << '\n';
		}

		system("pause");
		system("cls");

	} while (tentativas > 0);

	int pontuação{ acertos * 100 + tentativas * 25 - erros * 15 };

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
*	[x] Checar se jogador não colocou posição inválida na entrada de valores
*	[x] Verificar se jogador repetiu tentativas na entrada de valores
*	[x] Sistema de pontuação
*	[ ] Salvamento de pontuação
*	[ ] Entrada do nome/sigla do jogador para a tabela de pontuação
*	[ ] Limpar e otimizar código
*	{ } Interface de menu principal
*	{ } Tabela das 10 pontuações mais altas
*	{ } Salvar iniciais do jogador para fácil distinção na tabela de pontuação
*	{ }	Implementar seleção de dificuldade
*	{ } Dificuldade personalizada
*	
*	-----------------------------------------------------------------------------
*	
*	[ ] = requisito ainda a ser cumprido
*	[x] = requisito cumprido
*	{ } = requisito opcional ainda a ser alcançado
*	{x} = requisito opcional cumprido
*/