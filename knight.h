/***********************************************************************
 * Header File:
 *    Knight : A Chess Board Piece
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    This is the Knight in chess.
 ************************************************************************/
#pragma once
#include "piece.h"
#include "board.h"
#include <set>
using namespace std;

class Knight : public Piece
{
private:
   char letter;

public:

   //Constructor
   Knight(int r, int col, bool white);

   //Inherited Functions
   char getLetter() { return letter; }
   virtual void display(ogstream& gout);
   set<int> getMoves(Piece** board);
};
