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



public:
   Board();

   //Reset as a datatype?
   Board(ogstream& gout, void reset()) { }
   Board(Position pt)   { this->pt = pt; }
   Piece** getBoard()   { return board;}
   int getCurrentMove() { return currentMove; }
   bool whiteTurn() { return(currentMove % 2 == 0);}
   void display( Interface& ui, set <int> possible);
   bool move(int positionFrom, int positionTo);


private:
   void swap(int positionFrom, int positionTo);
   void capture(int positionFrom);
   void addPromotion(int positionTo);
};
