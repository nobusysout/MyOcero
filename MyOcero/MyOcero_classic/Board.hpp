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
	void JudgeWinner();
	void ShowPoints();
	void ShowPoints(int,int);
private:
	int CountPoint(PlayerColor);
	bool canPut(PlayerColor);
};