#include "pch.hpp"
#include "Board.hpp"

Board::Board()
{
	squares = new std::vector<std::vector<Square>>(10,std::vector<Square>(10));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			SquareState target = SquareState::NONE;
			if (i == 0 || i == 9 || j == 0 || j == 9) {
				target = SquareState::BANNED;
			}
			else if ((i == 4 && j == 4) || (i == 5 && j == 5)) {
				target = SquareState::WHITE;
			}
			else if ((i == 4 && j == 5) || (i == 5 && j == 4)) {
				target = SquareState::BLACK;
			}
			(*squares)[i][j].state = target;
		}
	}
}


Board::~Board()
{
}

void Board::Show() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << (int)(*squares)[i][j].state;
		}
		std::cout << std::endl;
	}
}