#include "pch.hpp"
#include "Player.hpp"
#include "Board.hpp"

Player::Player(PlayerColor color,Board *board) {
	this->color = color;
	this->board = board;
	cursor.first = 1;
	cursor.second = 1;
}

Player::~Player()
{
}

void Player::ChooseAction() {
	int x = 1, y = 1;
	chooseLoopFlag = true;
	int s;
	//std::thread FlashingThread(&Player::CursorFlashingThread,this);
	while (chooseLoopFlag) {
		s = _getch();
		if (s == 13) { //Enter

		}
		else if (s == 224) {
			switch (s) {
			case 72: //ª
				break;
			case 80: //«
				break;
			case 75: //©
				break;
			case 77: //¨
				break;
			}
		}
	}
}

void Player::CursorFlashingThread() {
	while (chooseLoopFlag) {
		std::system("cls");
		board->ShowBoard(cursor.first, cursor.second, true);
		board->ShowPoints();
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		
		std::system("cls");
		board->ShowBoard(cursor.first, cursor.second, false);
		board->ShowPoints();
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
	}
}