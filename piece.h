#pragma once
#include "position.h"
#include "board.h"


class Piece
{
public:
   // For the Unit Tests
   friend testPiece;

protected:
   Position position;

   int nMove;
   int lastMove;



public:

   bool fWhite;
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
   virtual void getMoves(Board board) {};
};


