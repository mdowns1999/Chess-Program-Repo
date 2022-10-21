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

   //Set up a structure so we can put in the moves
   struct move
   {
      int col;
      int row;
   };

   //Assign the Piece a position or a Piece
   void assign(Position position);
   void assign(Piece piece);

   bool isWhite() { return fWhite; }
   bool isMove() { return (nMove != 0); }

   Position getPosition() { return position; }

   //methods related to Move
   int getNMoves() { return nMove; }
   bool justMoved();
   void setNMove(int moves) { nMove = moves; }

   //Virtual Functions for Inheritance
   virtual char getLetter() { return letter; }
   virtual void display(ogstream &gout) {}
   virtual set<int> getMoves(Piece** board) { return set<int>(); }
   virtual bool getEmpassant() {return false;}
};


