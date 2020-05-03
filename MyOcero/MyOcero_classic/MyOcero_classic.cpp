#include "pch.hpp"
#include "Board.hpp"
#include "Player.hpp"

int main()
{
	//初期化
	Board *board = new Board();
	Player *player1 = new Player(PlayerColor::BLACK,board);
	Player *player2 = new Player(PlayerColor::WHITE,board);
	//調査
	/*int i = 0;
	while (1) {
		i = _getch();
		std::cout << i << std::endl;
	}*/
	//ゲーム
	Player *turnPlayer = player1;
	while (!board->isFinish()) {
		if (!board->isPass(turnPlayer->color)) {
			turnPlayer->ChooseAction();
		}
		else {
			std::cout << "Pass!" << std::endl;
		}
		if (turnPlayer == player1) {
			turnPlayer = player2;
		}
		else {
			turnPlayer = player1;
		}
	}

	//勝敗判定
	board->JudgeWinner();
}