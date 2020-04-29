#include "pch.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <Windows.h>

Player::Player()
{
	color = PlayerColor::BLACK;
}

Player::Player(PlayerColor color,Board *board) {
	this->color = color;
	this->board = board;
}

Player::~Player()
{
}

void Player::ChooseAction() {
	int i = 1, j = 1;
	bool firstFlag = true;
	BYTE CurrentInputKeyInfo[256];
	BYTE PreviousInputKeyInfo[256];
	GetKeyboardState(PreviousInputKeyInfo);
	while (chooseLoopFlag) {
		GetKeyboardState(CurrentInputKeyInfo);
		if (CurrentInputKeyInfo[VK_LEFT] & 0x80 && !(PreviousInputKeyInfo[VK_LEFT] & 0x80)) {

		}
		else if(CurrentInputKeyInfo[VK_UP] & 0x80 && !(PreviousInputKeyInfo[VK_UP] & 0x80)){

		}
		else if (CurrentInputKeyInfo[VK_RIGHT] & 0x80 && !(PreviousInputKeyInfo[VK_RIGHT] & 0x80)) {

		}
		else if (CurrentInputKeyInfo[VK_DOWN] & 0x80 && !(PreviousInputKeyInfo[VK_DOWN] & 0x80)) {

		}
		else if (CurrentInputKeyInfo[VK_RETURN] & 0x80 && !(PreviousInputKeyInfo[VK_RETURN] & 0x80)) {

		}
		memcpy(PreviousInputKeyInfo,CurrentInputKeyInfo,sizeof(CurrentInputKeyInfo));
	}
}
 
void Player::CursorFlashingThread(int x,int y) {
	while (chooseLoopFlag) {
		board->ShowBoard(x, y, true);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		board->ShowBoard(x, y, false);
	}
}