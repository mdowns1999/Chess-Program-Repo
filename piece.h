#pragma once
#include "position.h"
#include "board.h"


class Piece
{
   // For the Unit Tests
   friend class testPiece;

protected:
   Position position;
   bool fWhite;
   int nMove;
   int lastMove;
   //Board board;



public:
   Piece();

   // Constructor
   Piece(int r, int c, bool white);

   void assign(Position position);
   void assign(Piece piece);
   bool isWhite();
   bool isMove();
   int getNMoves();
   Position getPosition();
   bool justMoved();

   //Virtual Functions for Inheritance
   virtual char getLetter() {}
   virtual void display() {}
   //virtual void getMoves(Board board) {};
};


