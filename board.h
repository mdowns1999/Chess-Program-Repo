/***********************************************************************
 * Header File:
 *    Board : The Board of Chess
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    This keeps track of the chess board.
 ************************************************************************/


#pragma once
#include "position.h"
#include "piece.h"

//#include "space.h"
//#include "move.h"
#include "uiDraw.h"
#include <iostream>
using namespace std;

class Piece;

class Board
{
private:
   Piece *board[64];
   //Piece board[64];
   int currentMove;
   Position pt;
   ogstream gout;


public:
   Board();
   //Reset as a datatype?
   Board(ogstream& gout, void reset()) { };
   Board(Position pt) { this->pt = pt; };
   Piece* getBoard() { return *board;};
   int getCurrentMove();
   bool whiteTurn();
   void display(Position posHover, Position posSel);
   //Piece get(Position pt);
   void free();
   void reset();
   //void move(Move move);
   //void assign(Piece piece);

private:
   void swap(Position position1, Position position2);
   void assertBoard();
};
