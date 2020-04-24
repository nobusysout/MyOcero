#pragma once
#include "pch.hpp"


enum class PlayerColor {
	BLACK, WHITE,
};

class Player
{
public:
	PlayerColor color;
	Player();
	Player(PlayerColor color);
	~Player();
};