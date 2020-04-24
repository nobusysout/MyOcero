#include "pch.hpp"
#include "Player.hpp"

Player::Player()
{
	color = PlayerColor::BLACK;
}

Player::Player(PlayerColor color) {
	this->color = color;
}

Player::~Player()
{
}