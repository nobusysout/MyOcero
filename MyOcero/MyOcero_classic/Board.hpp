#pragma once
#include "pch.hpp"
#include "Square.hpp"
#include "Player.hpp"

class Board
{
public:
	std::vector<std::vector<Square>> *squares;
	Board();
	~Board();
	void ShowBoard();
	bool isFinish();
	bool isPass(PlayerColor);
	bool canPut(PlayerColor, int, int);
	void JudgeWinner();
	void ShowPoints();
	void ShowPoints(int,int);
private:
	int CountPoint(PlayerColor);
	bool canPutSub(PlayerColor,int,int,int,int,int);
	int xdir[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int ydir[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
};