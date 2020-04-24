#include "pch.hpp"
#include "Board.hpp"
#include "Player.hpp"

int main()
{
	//初期化
	Board *board = new Board();
	board->ShowBoard();
	board->ShowPoints();
	Player *player1 = new Player(PlayerColor::BLACK);
	Player *player2 = new Player(PlayerColor::WHITE);
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