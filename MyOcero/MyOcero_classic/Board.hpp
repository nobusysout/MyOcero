#pragma once
#include "pch.hpp"
#include "Square.hpp"

class Board
{
public:
	std::vector<std::vector<Square>> *squares;
	Board();
	~Board();
	void Show();
};