#include "pch.hpp"
#include "Board.hpp"

bool operator ==(SquareState ss, PlayerColor pc) {
	if (((ss == SquareState::BLACK) && (pc == PlayerColor::BLACK)) ||
		((ss == SquareState::WHITE) && (pc == PlayerColor::WHITE)))
	{
		return true;
	}
	return false;
}

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

void Board::ShowBoard() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << (int)(*squares)[i][j].state;
		}
		std::cout << std::endl;
	}
}


bool Board::isFinish() {
	if (isPass(PlayerColor::BLACK) && isPass(PlayerColor::WHITE)) return true;
	return false;
}

bool Board::isPass(PlayerColor currentPlayer) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Square square = (*squares)[i][j];
			if (square.state == SquareState::NONE) {
				if (canPut(currentPlayer)) {
					return true;
				}
			}
		}
	}
	return false;
}

int Board::CountPoint(PlayerColor color) {
	int counter = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((*squares)[i][j].state == color) {
				counter++;
			}
		}
	}
	return counter;
}

void Board::JudgeWinner() {
	int bp = CountPoint(PlayerColor::BLACK);
	int wp = CountPoint(PlayerColor::WHITE);
	if (bp > wp) {
		std::cout << "BLACK WIN!!" << std::endl;
		ShowPoints(bp,wp);
	}
	else if (bp == wp) {
		std::cout << "DRAW!!" << std::endl;
	}
	else {
		std::cout << "WHITE WIN!!" << std::endl;
		ShowPoints(bp,wp);
	}
}

void Board::ShowPoints() {
	int bp = CountPoint(PlayerColor::BLACK);
	int wp = CountPoint(PlayerColor::WHITE);
	std::cout << "BLACK: " << bp << "  WHITE: " << wp << std::endl;
}
void Board::ShowPoints(int bp, int wp) {
	std::cout << "BLACK: " << bp << "  WHITE: " << wp << std::endl;
}

bool Board::canPut(PlayerColor pc) {
	for (int i = 0; i < 3;i++) {
		for (int j = 0; j < 3; j++) {

		}
	}
	return false;
}