#pragma once
#include "position.h"
#include "board.h"
#include "move.h"
#include<set>
using namespace std;

class Board;

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
   char letter = 'u';
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
   void setNMove(int moves) { nMove = moves; }

   //Virtual Functions for Inheritance
   virtual char getLetter() { return letter; }
   //virtual void display() {}
   virtual set<int> getMoves(Board& board) { return set<int>(); }
};


