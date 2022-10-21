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
   bool moved;
   int nMove;
   int lastMove;
   char letter = 'u';



public:

   // Constructor
   Piece();
   Piece(int r, int c, bool white);

   struct M
   {
      int move;

   };

   struct M2
   {
      int col;
      int row;
   };

   void assign(Position position);
   void assign(Piece piece);
   bool isWhite();
   bool isMove();
   int getNMoves();

   //int getLastMove() { return lastMove; }
   //void setlastMove();

   Position getPosition();
   bool justMoved();
   void setNMove(int moves) { nMove = moves; }

   //Virtual Functions for Inheritance
   virtual char getLetter() { return letter; }
   virtual void display(ogstream &gout) {}
   virtual set<int> getMoves(Piece** board) { return set<int>(); }
   virtual bool getEmpassant() {return false;}
};


