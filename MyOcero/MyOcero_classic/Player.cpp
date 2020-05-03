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
	int *x = &cursor.first;
	int *y = &cursor.second;
	chooseLoopFlag = true;
	int s;
	std::thread FlashingThread(&Player::CursorFlashingThread,this);
	while (chooseLoopFlag) {
		s = _getch();
		if (s == 13) { //Enter
			std::cout << "Enter" << std::endl;
		}
		else if (s == 224) {
			s = _getch();
			switch (s) {
			case 72: //ª
				if (!board->isMovable(*x, *y - 1)) break;
				(*y)--;
				break;
			case 80: //«
				if (!board->isMovable(*x, *y + 1)) break;
				(*y)++;
				break;
			case 75: //©
				if (!board->isMovable(*x - 1, *y)) break;
				(*x)--;
				break;
			case 77: //¨
				if (!board->isMovable(*x + 1, *y)) break;
				(*x)++;
				break;
			}
		}
	}
	FlashingThread.detach();
}

void Player::CursorFlashingThread() {
	while (chooseLoopFlag) {
		std::system("cls");
		board->ShowBoard(cursor.first, cursor.second, true);
		board->ShowPoints();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		
		std::system("cls");
		board->ShowBoard(cursor.first, cursor.second, false);
		board->ShowPoints();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}