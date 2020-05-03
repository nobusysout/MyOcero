#include "pch.hpp"
#include "Board.hpp"

inline bool operator ==(SquareState ss, PlayerColor pc) {
	if (((ss == SquareState::BLACK) && (pc == PlayerColor::BLACK)) ||
		((ss == SquareState::WHITE) && (pc == PlayerColor::WHITE)))
	{
		return true;
	}
	return false;
}
inline bool operator !=(SquareState ss, PlayerColor pc) {
	return !(ss == pc);
}
inline SquareState operator !(SquareState ss) {
	if (ss == SquareState::BLACK) return SquareState::WHITE;
	if (ss == SquareState::WHITE) return SquareState::BLACK;
	return ss;
}
inline PlayerColor operator !(PlayerColor pc) {
	if (pc == PlayerColor::BLACK) return PlayerColor::WHITE;
	if (pc == PlayerColor::WHITE) return PlayerColor::BLACK;
	return pc;
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

void Board::ShowBoard(int x, int y, bool isMaskOn) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (isMaskOn && j == x && i == y) {
				std::cout << " ";
			}
			else {
				std::cout << (int)(*squares)[i][j].state;
			}
		}
		std::cout << std::endl;
	}
}

void Board::ShowBoard() {
	ShowBoard(0,0,false);
}
bool Board::isFinish() {
	if (isPass(PlayerColor::BLACK) && isPass(PlayerColor::WHITE)){
		std::cout << "Finish!" << std::endl;
		return true;
	}
	return false;
}

bool Board::isPass(PlayerColor currentPlayer) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Square square = (*squares)[i][j];
			if (square.state == SquareState::NONE) {
				if (canPut(currentPlayer,j,i)) {
					return false;
				}
			}
		}
	}
	return true;
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
	ShowPoints(bp,wp);
}
inline void Board::ShowPoints(int bp, int wp) {
	std::cout << "BLACK: " << bp << "  WHITE: " << wp << std::endl;
}

bool Board::canPut(PlayerColor pc,int x,int y) {
	if ((*squares)[y][x].state != SquareState::NONE) return false;
	for (int i = 0; i < 8;i++) {
		int dx = xdir[i];
		int dy = ydir[i];
		if (canPutSub(pc,dx,dy,x+dx,y+dy,0)) return true;
	}
	return false;
}

bool Board::isMovable(int x, int y) {
	return !((*squares)[y][x].state == SquareState::BANNED);
}

void Board::PutStone(PlayerColor color,int x,int y) {
	int fx = x, fy = y;
	for (int i = 0 ; i < 8; i++) {
		int dx = xdir[i];
		int dy = ydir[i];
		if (canPutSub(color, dx, dy, x + dx, y + dy, 0)) {
			while ((*squares)[y + dy][x + dx].state == !color) {
				(*squares)[y + dy][x + dx].state = (color == PlayerColor::BLACK) ? SquareState::BLACK : SquareState::WHITE;
				x += dx;
				y += dy;
			}
		}
		x = fx;
		y = fy;
	}
	(*squares)[y][x].state = (color == PlayerColor::BLACK) ? SquareState::BLACK : SquareState::WHITE;
}

bool Board::canPutSub(PlayerColor pc,int dx,int dy,int x,int y,int counter) {
	SquareState point = (*squares)[y][x].state;
	if (point == !pc) {
		counter++;
		return canPutSub(pc,dx,dy,x+dx,y+dy,counter);
	}
	else if (point == pc) {
		return counter == 0 ? false : true;
	}
	else {
		return false;
	}
}