#pragma once
#include "position.h"
#include "piece.h"
#include "move.h"

class Board
{
private:
   //array board[];
   int currentMove;

public:
   Board() { reset(); };
   //Board(Position pt) { this->pt = pt; };
   int getCurrentMove();
   bool whiteTurn();
   void display(Position posHover, Position posSel);
   Piece get(Position position);
   void free();
   void reset();
   void move(Move move);
   void assign(Piece piece);
   void swap(Position position1, Position position2);
   void assertBoard();
};
