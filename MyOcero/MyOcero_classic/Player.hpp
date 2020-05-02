#pragma once
#include "pch.hpp"
#include "PlayerColor.hpp"

class Board;

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
	void CursorFlashingThread();
};