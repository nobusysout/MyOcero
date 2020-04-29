#pragma once
#include "pch.hpp"
#include "Board.hpp"


enum class PlayerColor {
	BLACK, WHITE,
};

class Player
{
public:
	PlayerColor color;
	Board *board;
	bool chooseLoopFlag = true;
	std::pair<int,int> cursor;
	Player();
	Player(PlayerColor,Board*);
	~Player();
	void ChooseAction();
	void CursorFlashingThread(int,int);
};