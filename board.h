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
#include "move.h"
#include "uiDraw.h"

class Board
{
private:
   Piece board[64];
   int currentMove;
   Position pt;
   ogstream gout;


public:
   //Reset as a datatype?
   Board(ogstream& gout, void reset()) { };
   Board(Position pt) { this->pt = pt; };
   int getCurrentMove();
   bool whiteTurn();
   void display(Position posHover, Position posSel);
   Piece get(Position position);
   void free();
   void reset();
   void move(Move move);
   void assign(Piece piece);

private:
   void swap(Position position1, Position position2);
   void assertBoard();
};
