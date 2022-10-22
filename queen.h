/***********************************************************************
 * Header File:
 *    Queen : A Chess Board Piece
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    This is the Queen in chess.
 ************************************************************************/
#pragma once
#include "piece.h"
#include "board.h"
#include <set>
using namespace std;

class Queen : public Piece
{
private:
   char letter;

public:

   //Constructor
   Queen(int r, int col, bool white);

   //Inherited Functions
   char getLetter() { return letter; }
   virtual void display(ogstream& gout);
   set<int> getMoves(Piece** board, int lastMove);
};
