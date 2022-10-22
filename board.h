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
#include "uiDraw.h"
#include <iostream>
#include "uiInteract.h"
#include <set>
using namespace std;

class Piece;


class Board
{
private:
   Piece *board[64];
   int currentMove;
   Position pt;
   ogstream gout;
   Position source;
   Position dest;
   int lastMove;



public:
   //Constructors
   Board();
   Board(ogstream& gout, void reset()) { }
   Board(Position pt)   { this->pt = pt; }

   //Return the Board
   Piece** getBoard()   { return board;}

   //Get the Current Move
   int getCurrentMove() { return currentMove; }

   //Is it Whites turn or not?
   bool whiteTurn() { return(currentMove % 2 == 0);}

   //Get last move
   int getLastMove() { return lastMove; }

   void display( Interface& ui, set <int> possible);
   bool move(int positionFrom, int positionTo);

   //Free the Spot in Memory
   void free(int position, Piece* pPiece);

private:
   //These Methods are your normal moves that are used frequently
   void swap(int positionFrom, int positionTo);
   void capture(int positionFrom);

   //These Methods Update the Board for these Special Moves
   void addPromotion(int positionTo);
   void addEnpassant(int positionTo);
   void addCastle(int positionTo);
};
