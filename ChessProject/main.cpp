#include <iostream>
#include "piece.h"
#include "board.h"
using std::cout;
int main()
{
	King whiteKing("e1", "white");
	King blackKing("e8", "black");
	Pawn whitePawn("a2", "white");
	Pawn blackPawn("d4", "black");
	Bishop whiteBishop("e4", "white");
	Rook blackRook("e5", "black");
	Rook whiteRook("a8", "black");
	Board myBoard[8][8];
	setBoard(myBoard);
	Board(*pointer)[8][8] = &myBoard;
	//yeh ma [0][4] ki [1][4]
	myBoard[1][4].currentPiece = &whiteKing;
	myBoard[1][0].currentPiece = &whitePawn;
	myBoard[3][3].currentPiece = &blackPawn;
	myBoard[3][4].currentPiece = &whiteBishop;
	myBoard[1][3].currentPiece = &whiteRook;
	myBoard[3][2].currentPiece = &blackRook;	
	cout << (*pointer)[1][4].currentPiece->MovesInEmptyBoard("e2", "e4");
	cout << (*pointer)[1][0].currentPiece->MovesInEmptyBoard("a2", "b3");
	//how to access member function in pawn as above-anything->anything
	cout << (*pointer)[3][3].currentPiece->MovesInEmptyBoard("d4", "d3");
	cout << (*pointer)[3][4].currentPiece->MovesInEmptyBoard("e4", "d4");
	cout << (*pointer)[1][3].currentPiece->MovesInEmptyBoard("a8", "d1");
	cout << (*pointer)[3][2].currentPiece->MovesInEmptyBoard("e5", "e1");
	
}
