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

	while (!(*board).isFinish()) {

	}

	//勝敗判定


}