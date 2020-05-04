#include "pch.hpp"
#include "Board.hpp"
#include "Player.hpp"
void PlayClassicOcero();

int main()
{
	PlayClassicOcero();

	std::cout << "もう一回? y/n" << std::endl;
	
	while (1) {
		char c;
		std::cin >> c;
		if (c == 'y') {
			main();
			break;
		}
		else if (c == 'n') break;
	}
}

void PlayClassicOcero() {
	//初期化
	Board *board = new Board();
	Player *player1 = new Player(PlayerColor::BLACK, board);
	Player *player2 = new Player(PlayerColor::WHITE, board);
	//ゲーム
	Player *turnPlayer = player1;
	while (!board->isFinish()) {
		if (!board->isPass(turnPlayer->color)) {
			turnPlayer->ChooseAction();
			board->wasPassed = false;
		}
		else {
			board->wasPassed = true;
		}
		if (turnPlayer == player1) {
			turnPlayer = player2;
		}
		else {
			turnPlayer = player1;
		}
	}
	//勝敗判定
	board->UpdateGameScreen(0, 0, false, turnPlayer->color);
	board->JudgeWinner();
	delete board;
	delete player1;
	delete player2;
}