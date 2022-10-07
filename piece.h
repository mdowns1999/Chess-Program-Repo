#pragma once
#include "position.h"
#include "board.h"
#include<set>


class Piece
{
   // For the Unit Tests
   friend class testPiece;

protected:
   Position position;
   bool fWhite;
   int nMove;
   int lastMove;
   int r;
   int c;

   //Board board;



public:

   // Constructor
   Piece();
   Piece(int r, int c, bool white);

   void assign(Position position);
   void assign(Piece piece);
   bool isWhite();
   bool isMove();
   int getNMoves();
   Position getPosition();
   bool justMoved();

   //Virtual Functions for Inheritance
   //virtual char getLetter() { return 'P'; };
   virtual void display() {}
   //virtual void getMoves() {};
};


