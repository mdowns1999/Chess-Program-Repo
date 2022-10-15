/***********************************************************************
 * Header File:
 *    Piece : A default Chess Board Piece
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    This is the Piece in chess.
 ************************************************************************/
#pragma once
#include "position.h"
#include "board.h"
#include "move.h"
#include "uiDraw.h"
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
   //int r;
   //int c;
   char letter = 'u';
   //Board board;



public:

   // Constructor
   Piece();
   Piece(int r, int c, bool white);

   struct M
   {
      int move;

   };

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
   virtual void display(ogstream &gout) {}
   virtual set<int> getMoves(Piece** board) { return set<int>(); }
};


