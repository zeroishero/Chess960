
#include "chess.h"
#include <iostream>
Chess::Chess(string name1, string name2, Board (*currentBoard)[8][8],OnePiece *ptr)
{
	whiteToPlay = true;
	isOver = false;
	whitePlayerName = name1;
	blackPlayerName = name2;
	this->currentBoard = currentBoard;
	this->ptrToNoPiece = ptr;
	
}
bool Chess::getCurrentPlayer() { return whiteToPlay; }
bool Chess::isChessOver()
{
	return isOver;
}
void Chess::changeTurn()
{
	whiteToPlay = !whiteToPlay;
}
int Chess::moveToEmptySquare(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow= source[1] - '1' + 1;
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	Piece *sourcePiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
	bool canMove = sourcePiece->movesInEmptyBoard(source, destination);
	if (!canMove)
	{
		
		std::cout << "I cant move " << sourcePiece->myName() << "in here" << "from " << source << "to " << destination << "\n";
	}
	bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
	string sourcePieceName = sourcePiece->myName();
	//std::cout << canMove;
	
	if (canMove && playerMatchesPiece)
	{
		(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece = (*currentBoard)[sourceRow-1][sourceFile-1].currentPiece;
		(*currentBoard)[sourceRow-1][sourceFile-1].currentPiece = ptrToNoPiece;
		//string destinationPosition = (*currentBoard)[destinationRow-1][destinationFile-1].getMyLocation();
		//(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece->setCurrentPosition(destinationPosition);
		std::cout << "Move done Successfully\n";
		std::cout << sourcePieceName << " moved from " << source << " to " << destination << "\n";
		return 1;
	}	
	else
	{
		if (playerMatchesPiece == 0)
		{
			std::cout << "You cant move piece of opponent. \n";
		}
		else if (canMove == 0)
		{
			std::cout << "Not a Valid Move\n";
		}
		return 0;
	}
}
int Chess::capture(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow = source[1] - '1' + 1;
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	Piece *sourcePiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece;
	bool canMove = sourcePiece->movesInEmptyBoard(source, destination);
	bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
	bool isOpponentPiece = (getCurrentPlayer() != destinationPiece->getColor());
	//std::cout << canMove;

	if (canMove && playerMatchesPiece && isOpponentPiece)
	{

		sourcePiece->kill();
		//(*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece = ptrToNoPiece;
		(*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
		(*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece = ptrToNoPiece;
		//string destinationPosition = (*currentBoard)[destinationRow-1][destinationFile-1].getMyLocation();
		//(*currentBoard)[destinationRow-1][destinationFile-1].currentPiece->setCurrentPosition(destinationPosition);
		std::cout << "Move done Successfully\n";
		return 1;
	}
	else
	{
		if (playerMatchesPiece == 0)
		{
			std::cout << "You cant move piece of opponent. \n";
		}
		else if (canMove == 0)
		{
			std::cout << "Not a Valid Move\n";
		}
		return 0;
	}
}
int Chess::execute(string choosenMove)
{
	string source = choosenMove.substr(0, 2);
	string destination = choosenMove.substr(2, 2);
	int sourceFile = source[0] - 'a' + 1;
	int sourceRow = source[1] - '1' + 1;
	int destinationFile = destination[0] - 'a' + 1;
	int destinationRow = destination[1] - '1' + 1;
	Piece *sourcePiece = (*currentBoard)[sourceRow - 1][sourceFile - 1].currentPiece;
	Piece *destinationPiece = (*currentBoard)[destinationRow - 1][destinationFile - 1].currentPiece;
	if (destinationPiece->myName() == "OnePiece")
	{
		std::cout << "Sending move to empty square\n";
		if (moveToEmptySquare(choosenMove))
			return 1;
		else
			return 0;
	}
	else if (destinationPiece->myName()!="OnePiece")
	{
		std::cout << "Sending mvoe to capture\n";
		if (capture(choosenMove))
			return 1;
		else
			return 0;
	}
	bool canMove = sourcePiece->movesInEmptyBoard(source, destination);
	bool playerMatchesPiece = (getCurrentPlayer() == sourcePiece->getColor());
	bool isOpponentPiece = (getCurrentPlayer() != destinationPiece->getColor());


}
void Chess::checkState()
{
	//if (*currentBoard)[0][5].currentPiece != noPiece;
}
void Chess::endChess()
{
	isOver = true;
}