#pragma once
#include "pch.hpp"

enum class SquareState {
	NONE, BLACK, WHITE, BANNED,
};

class Square
{
public:
	SquareState state;
	Square();
	~Square();
};

