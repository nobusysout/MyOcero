#include "pch.hpp"
#include "Board.hpp"
#include "Player.hpp"

int main()
{
	//初期化
	Board *board = new Board();
	Player *player1 = new Player(PlayerColor::BLACK,board);
	Player *player2 = new Player(PlayerColor::WHITE,board);
	//ゲーム
	Player *turnPlayer = player1;
	while (!board->isFinish()) {
		if (!board->isPass(turnPlayer->color)) {
			turnPlayer->ChooseAction();
		}
		else {
			std::cout << "Pass!" << std::endl; //WasPassed変数を作り、描画ルーチン側に任せる Passじゃないときにfalseに戻すことを忘れないこと
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