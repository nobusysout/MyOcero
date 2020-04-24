#pragma once
#include "pch.hpp"


enum class PlayerColor {
	BLACK, WHITE,
};

class Player
{
public:
	PlayerColor color;
	bool chooseLoopFlag = true;
	std::pair<int,int> cursor;
	Player();
	Player(PlayerColor color);
	~Player();
	void ChooseAction();
	void CursorFlashingThread();
};