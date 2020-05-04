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
	int s,ps=0;
	std::thread FlashingThread(&Player::CursorFlashingThread,this);
	while (chooseLoopFlag) {
		s = _getch();
		if (s == 13 && ps!=13) { //Enter
			if (board->canPut(color,*x,*y)) {
				board->PutStone(color,*x,*y);
				chooseLoopFlag = false;
			}
		}
		else if (s == 224 && ps!=224) {
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
		ps = s;
	}
	FlashingThread.detach();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Player::CursorFlashingThread() {
	while (chooseLoopFlag) {
		board->UpdateGameScreen(cursor.first, cursor.second, true, color);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		
		board->UpdateGameScreen(cursor.first, cursor.second, false, color);
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}