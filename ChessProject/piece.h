#pragma once
#include <vector>
#include <string>
#include <fstream>
using std::string;
using std::vector;

vector<int> getPositionInVector(string position);
int getPositionInInteger(string position);
class Piece
{
protected:
	string name;
	bool isWhite;
	bool alive;
	//string currentPosition;
public:
	//void setCurrentPosition(string position);
	string myName();
	virtual int movesInEmptyBoard(string initialPosition, string finalPosition) = 0;
	bool isAlive() { return alive; }
	bool kill();
	bool getColor() { return isWhite; }
};

class King:public Piece
{
public:
	King(string currentPosition, string color);
	int MovesInEmptyBoard(string initialPosition, string finalPosition);
};

class Pawn :public Piece
{
	std::ifstream moveRefFile;
	std::ifstream eatRefFile;
public:
	Pawn(string currentPosition, string color);
	//Does eat and move validation
	int MovesInEmptyBoard(string initialPosition, string finalPosition);
	//0 = Move not Valid, 1 = Move Valid, 2 = Move Possible if it has opposite piece
	void anything();
};

class Bishop :public Piece
{
public:
	Bishop(string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);
};

class Rook :public Piece
{
public:
	Rook(string currentPosition, string color);
	int MovesInEmptyBoard(string initialPosition, string finalPosition);
};

class Queen :public Piece
{
public:
	Queen(string color);
	int movesInEmptyBoard(string initialPosition, string finalPosition);
};
