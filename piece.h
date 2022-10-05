#pragma once
#include "position.h"


class Piece
{
protected:
   Position position;

   int nMove;
   int lastMove;



public:

   bool fWhite;
   // For the Unit Tests
   friend testPiece;

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


