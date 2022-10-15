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
//#include "pawn.h"
//#include "piece.h"
#include "uiInteract.h"
using namespace std;

class Piece;
class Move;

class Board
{
private:
   Piece *board[64];
   int currentMove;
   Position pt;
   ogstream gout;


public:
   Board();

   //Reset as a datatype?
   Board(ogstream& gout, void reset()) { }
   Board(Position pt)   { this->pt = pt; }
   Piece** getBoard()   { return board;}
   int getCurrentMove() { return currentMove; }
   bool whiteTurn();
   //void display(const Interface& ui, const set <int>& possible);
   //Piece get(Position pt);
   void free();
   void reset();
   bool move(int positionFrom, int positionTo);
   //void assign(Piece piece);

private:
   void swap(Position position1, Position position2);
   void assertBoard();
};
