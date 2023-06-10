#include <iostream>

int main() 
{
	//variaveis de posição da matriz usada durante jogo  
	int linha{};
	std::cout << "Insira linha: ";
	std::cin  >> linha;

	int coluna{};
	std::cout << "insira coluna: ";
	std::cin  >> coluna;
	
	std::cout << linha << "  " << coluna << std::endl;

	/*matrizJogo é a matriz que o jogader vê durante a partida e atualiza
	de acordo com as tentativas do jogador*/
	char matrizJogo[10][10], matrizResposta[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrizResposta[i][j] = 126;

			matrizJogo[i][j] = 126;
			std::cout << matrizJogo[i][j] << " ";
		}
		
		std::cout << std::endl;
	}

	
	return 0;
}


/*		Requisitos funcionais
* 
*	[x] Matris 10x10 para campo de jogo
*	[x] Matris 10x10 para respostas 
*	[ ] Geração dos alvos no campo para serem encontrados
*	[ ] Aleatorizar a posição dos alvos no campo de forma ordenada
*	[ ] Recebeer 2 valores do jogador para indicar qual posição do campo atacar
*	[ ] Traduzir os dois valores para pontos no campo de jogo e campo de resposta
*	[ ] Comparar posições de no campo principal e de resposta para confirmar 
		um acerto ou erro
*	[ ] Contagem de acertos e erros de jogador
*	{ } Interface de menu principal
*	{ } Salvamento de pontuação
*	{ } Tabela das 10 pontuações mais altas
*	{ } Salvar iniciais do jogador para fácil distinção na tabela de pontuação
*	{ }	
* 
*	[ ] = requisito ainda a ser cumprido
*	[x] = requisito cumprido
*	{ } = requisito opcional ainda a ser alcançado
*	{x} = requisito opcional cumprido
*/

