#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include "Torre.h"
#include "Disco.h"

/*
		TORRE DE HANÓI
*/

int main() {
    setlocale(LC_ALL, "");

	int n = 0;

    Pilha * torre1 = criar();
    Pilha * torre2 = criar();
    Pilha * torre3 = criar();


    titulo();
    menu(torre1, torre2, torre3,n);
	//jogar(torre1, torre2, torre3, n);
	
	destruir(torre1);
	destruir(torre2);
	destruir(torre3);
	
    system("pause");
}

/* */

void jogar(Pilha * torre1, Pilha * torre2, Pilha * torre3, int n) {


		if (n >= 3 && n <= 20) {
			inicializar_torres(torre1, n);
			do
			{
				mostrar_torres(torre1, torre2, torre3);
				movimentos_validos(torre1, torre2, torre3);
				mover_discos(torre1, torre2, torre3);
				//desistir();
				limpar_tela();
			} while (checar_jogo(torre1, torre2, torre3, n) != 1);

			venceu(torre1,torre2, torre3);
			limpar_torre(torre3, n);
			limpar_tela();
			return menu(torre1, torre2, torre3, n);
		}
		else {
			printf("\n\n\t\tNúmero de Discos Inválidos. \n\t Aperte qualquer tecla e tente novamente!!");
			_getch();
			limpar_tela();
			return menu(torre1, torre2, torre3, n);
		}
		
	
}

/*
	Função básica que irá mostrar um menu com 5 opções para o usuário

*/

void menu(Pilha * torre1, Pilha * torre2, Pilha * torre3, int n) {

    int escolha;

    printf("\n\n\t\tMenu de Opções");
    printf("\n\n\t\t01. Jogar");
    printf("\n\n\t\t02. História da Torre de Hanói");
    printf("\n\n\t\t03. Regras do Jogo");
    printf("\n\n\t\t04. Créditos");
	printf("\n\n\t\t05. Sair");
    printf("\n\n\t\tEscolha a opção(Apenas Números): ");
    scanf_s("%d", &escolha);
    switch (escolha)
    {
    case 1:

        limpar_tela();
		printf("\n\n\nEscolha a quantidade de discos que queira jogar(Mínimo: 3, Máximo: 20): ");
		scanf_s("%d", &n);
		jogar(torre1, torre2, torre3, n);
		_getch();
		limpar_tela();
		//return menu(torre1, torre2, torre3, n);
        break;

    case 2:

        limpar_tela();
        historia();
        limpar_tela();
        return menu(torre1, torre2, torre3, n);
        break;

    case 3:

        limpar_tela();
        ajuda();
        limpar_tela();
        return menu(torre1, torre2, torre3, n);
        break;

    case 4:

		limpar_tela();
		printf("\n\n\n\n\tTorre de Hanói desenvolvido em C.\n\tPor Thyago Oliveira e Artur Lima");
		printf("\n\n-------------------------------------------------------------------------------\t");
		printf("\n\tAperte qualquer tecla para voltar ao menu Principal!!");
		_getch();
		limpar_tela();
		return menu(torre1, torre2, torre3, n);
        break;

	case 5:

		exit(0);
		break;

    default:

        printf("\n\n\t\tTecla Incorreta, Pressione Enter para continuar.");
        _getch();
        //sleep(5000);
        //delay();
        limpar_tela();
        return menu(torre1, torre2, torre3, n);
        break;
    }
}

/*
	Essa função vai ser usada para limpar a tela.
*/

void limpar_tela() {
    system("cls");
}

/*
	Função que limpa a a TERCEIRA TORRE após o término do jogo,
	para iniciar uma nova partida. Chamando a função desempilhar
	para que a Torre fica vazia, para ser inicializada novamente.
*/
void limpar_torre(Pilha * torre3, int n) {
	int i;

	for (i = 0; i < n; i++) {
		desempilhar(torre3);

	}
}

/*
	Função para mostrar a história da Torre de Hanói.
*/

void historia() {

    printf("\n\n\t\t\tHistória da Torre de Hanói.");
    printf("\n\n\n\tA Torre de Hanói é um quebra-cabeça que  foi inventado pelo matemático\nfrancês Édouard Lucas.");
    printf(" Ele teve inspiração de uma lenda para construir o jogo \ndas Torres de Hanói em 1883.");
    printf(" Já seu nome foi inspirado na torre símbolo da \ncidade de Hanói, no Vietnã.");
    printf(" Existem várias lendas a respeito da origem do jogo, a mais conhecida diz respeito a um templo Hindu, situado no centro do universo.");
    printf(" Diz-se que Brama supostamente havia criado uma torre com 64 discos de ouro \ne mais duas estacas equilibradas sobre uma plataforma. ");
    printf(" Brama ordenara-lhes que movessem todos os discos de uma estaca para outra segundo as suas instruções.");
    printf(" \nSegundo a lenda, quando todos os discos fossem transferidos de uma estaca para aoutra, o templo iria desmoronar e o mundo desapareceria.");
    printf(" Existem muitas \nvariações sobre esta lenda.");
    printf(" Por exemplo, em algumas narrativas, o templo é um \nmosteiro e os sacerdotes são monges. ");
    printf(" O templo ou mosteiro pode estar em \ndiferentes partes do mundo - incluindo Hanói, Vietnã, e pode ser associado a \nqualquer religião. ");
    printf(" Em algumas versões, são introduzidos outros elementos, tais como o facto de a torre foi criado no início do mundo,");
    printf(" ou que os padres ou \nmonges podem fazer apenas uma mudança por dia.");

    printf("\n\n-------------------------------------------------------------------------------\t");
    printf("\n\n\t Aperte qualquer tecla para voltar ao menu Principal!!");

    _getch();
}

/*
	Função que mostra as regras do jogo da Torre de Hanói ao usuário.
*/

void ajuda() {

    printf("\n\n\n\t\t\tRegras da Torre de Hanói");
    printf("\n\n\n\n\tTorre de Hanói é um quebra-cabeça que consiste em uma base contendo trêspinos,");
    printf("em um dos quais são dispostos alguns discos uns sobre os outros,");
    printf("em ordem  crescente de diâmetro, de cima para baixo.");
    printf("O problema consiste em passar todos osdiscos de um pino para outro qualquer,");
    printf("usando um dos pinos como auxiliar, ");
    printf("de \nmaneira que um disco maior nunca fique em cima de outro menor em nenhuma \nsituação.");
    printf(" E apenas um disco pode ser movido por vez.");
    printf("O número de discos pode \nvariar sendo que o mais simples contém apenas três.");
    printf("\n\n\n\t\t\t\t Boa Sorte !!");
    printf("\n\n\n-------------------------------------------------------------------------------\t");
    printf("\n\n\n Aperter qualquer tecla para voltar ao menu Principal!!");

    _getch();

}

/*
	Essa função sera chamada quando o jogador conseguir 
	passar todos os discos de forma correta para a TERCEIRA
	TORRE, será mostrado na tela uma Mensagem que o usuário
	conseguiu concluir o desafio.
*/

void venceu(Pilha * torre1, Pilha * torre2, Pilha * torre3) {
	limpar_tela();
	mostrar_torres(torre1, torre2, torre3);
	printf("\n\n\tParabéns, você venceu");
	printf("\n\n\tAperte qualquer tecla para voltar ao menu principal.");
	_getch();
}

/*
	Função para iniciar a PRIMEIRA TORRE, onde será passado a quantidade
	de DISCO que o usuário escolheu que está na VARIÁVEL n, será feito um
	teste pra saber se o número de discos atende ao requisito mínimo e 
	depois chamando a função empilhar, vai ser preenchido a TORRE. 
*/

void inicializar_torres(Pilha * torre1, int n) {
	limpar_tela();
    int i;

    if (n >= 3) {

        for (i = n; i > 0; i--) {
			limpar_tela();
            empilhar(torre1, i);
        }
    }
}

/*
	Função que vai imprimir na tela as 3 TORRES para se dar
	início ao Jogo.
*/

void mostrar_torres(Pilha * torre1, Pilha * torre2, Pilha * torre3) {

	printf("\n\n\tTorre 1: ");
	imprimir(torre1);
	printf("\tTorre 2: ");
	imprimir(torre2);
	printf("\tTorre 3: ");
	imprimir(torre3);
}

/*
	Nessa função será realizado os movimentos dos DISCOS entre
	as TORRES, onde sera feito testes baseado na TORRE de ORIGEM
	e TORRE de DESTINO que vão ser escolhidas pelo jogador, se 
	o movimento atender as regras do jogo o DISCO vai passar de 
	uma torre a outra, se não dara uma mensagem de Movimento 
	INVÁLIDO.
*/

void mover_discos(Pilha * torre1, Pilha * torre2, Pilha * torre3) {

	int origem = 0;
	int destino = 0;

	
	printf("\n\n\tEscolha a torre de origem: ");
	scanf_s("%d", &origem);
	printf("\n\tEscolha a torre de destino: ");
	scanf_s("%d", &destino);
	
	if (origem > 3 || origem < 1 || destino > 3 || destino < 1) {
		printf("\n\n\tPosições inválidas. Aperte qualquer tecla e tente novamente.");
		_getch();
	}

	if (origem == 1 && destino == 2 && tamanho(torre1) != 0) {
			if (topo(torre1) < topo(torre2) || tamanho(torre2) == 0 ) {
				empilhar(torre2, desempilhar(torre1));
			}
			else {
				printf("\n\n\tJogada Inválida");
				_getch();
			}
	}
	if (origem == 1 && destino == 3 && tamanho(torre1) != 0) {
		if (topo(torre1) < topo(torre3) || tamanho(torre3) == 0) {
			empilhar(torre3, desempilhar(torre1));
		}
		else {
			printf("\n\n\tJogada Inválida");
			_getch();
		}
	}
	if (origem == 2 && destino == 1 && tamanho(torre2) != 0) {
		if (topo(torre2) < topo(torre1) || tamanho(torre1) == 0) {
			empilhar(torre1, desempilhar(torre2));
		}
		else {
			printf("\n\n\tJogada Inválida");
			_getch();
		}
	}
	if (origem == 2 && destino == 3 && tamanho(torre2) != 0) {
		if (topo(torre2) < topo(torre3) || tamanho(torre3) == 0) {
			empilhar(torre3, desempilhar(torre2));
		}
		else {
			printf("\n\n\tJogada Inválida");
			_getch();
		}
	}
	if (origem == 3 && destino == 2 && tamanho(torre3) != 0) {
		if (topo(torre3) < topo(torre2) || tamanho(torre2) == 0) {
			empilhar(torre2, desempilhar(torre3));
		}
		else {
			printf("\n\n\tJogada Inválida");
			_getch();
		}
	}
	if (origem == 3 && destino == 1 && tamanho(torre3) != 0) {
		if (topo(torre3) < topo(torre1)  || tamanho(torre1) == 0) {
			empilhar(torre1, desempilhar(torre3));
		}
		else {
			printf("\n\n\tJogada Inválida");
			_getch();
		}
	}
	
}

/*
	Função que é usada para saber se o jogo acabou,
	que é feito um teste, no caso se as TORRES 1 e 2
	estiverem vazias e a TORRE 3 estiver empilhada 
	com o número de DISCOS que esta na váriavel n
	o jogo termina, se não a função retorna 0 e 
	o continua a partida.
*/

int checar_jogo(Pilha * torre1, Pilha * torre2, Pilha * torre3, int n) {
	
	if (tamanho(torre1) == 0 && tamanho(torre2) == 0 && tamanho(torre3) == n) {
		return 1;
	} else {

		return 0;
	}
}


/*
void delay() {
	int i;
	for (i = 10; i >= 0; i--)
	{
		printf("%i\n", i); // Escreve na tela o número atual da 'contagem'
		sleep(1000); // Espera 1 segundo
	}
}
*/

/*
int desistir(){

	int desistencia;

	printf("01.Desistir.");
	printf("02. Continuar.");
	scanf_s("%d", &desistencia);

	switch (desistencia){

	case 1:
		return 1;
		break;

	case 2:
		return 0;
		break;
	default:
		break;
	}
}

*/

/*
	Função que vai mostrar na tela uma DICA de Movimento para o usuário.
	Vai ser mostrado todos os POSSÍVEIS movimentos que o jogador poderá
	realizar, fazendo um teste para comparar o valor do topo de cada TORRE.
*/

void movimentos_validos(Pilha * torre1, Pilha * torre2, Pilha * torre3) {


	if (topo(torre1) < topo(torre2) || tamanho(torre2) == 0 ) {
		if (tamanho(torre1) != 0) {
			printf("\n\n\tTorre 1 -> Torre 2");
		}
	}

	if (topo(torre1) < topo(torre3) || tamanho(torre3) == 0) {
		if (tamanho(torre1) != 0) {
			printf("\n\n\tTorre 1 -> Torre 3");
		}
	}

	if (topo(torre2) < topo(torre1) || tamanho(torre1) == 0) {
		if (tamanho(torre2) != 0) {
			printf("\n\n\tTorre 2 -> Torre 1");
		}
	}

	if (topo(torre2) < topo(torre3) || tamanho(torre3) == 0) {
		if (tamanho(torre2) != 0) {
			printf("\n\n\tTorre 2 -> Torre 3");
		}
	}

	if (topo(torre3) < topo(torre1) || tamanho(torre1) == 0) {
		if (tamanho(torre3) != 0) {
			printf("\n\n\tTorre 3 -> Torre 1");
		}
	}

	if (topo(torre3) < topo(torre2) || tamanho(torre2) == 0) {
		if (tamanho(torre3) != 0) {
			printf("\n\n\tTorre 3 -> Torre 2");
		}
	}
}
