/***********************************************************************
 * Header File:
 *    Rook : A Chess Board Piece
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    This is the Rook in chess.
 ************************************************************************/
#pragma once
#include "piece.h"
#include "board.h"
#include <set>
using namespace std;

class Rook: public Piece
{
private:
   char letter;

public:

   //Constructor
   Rook(int r, int col, bool white);

   //Inherited Functions
   char getLetter() { return letter; }
   virtual void display(ogstream& gout);
   set<int> getMoves(Piece** board, int lastMove);
};
