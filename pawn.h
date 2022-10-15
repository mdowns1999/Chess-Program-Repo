/***********************************************************************
 * Header File:
 *    Pawn : A Chess Board Piece
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    This is the Pawn in chess.
 ************************************************************************/
#pragma once
#include "piece.h"
#include "board.h"
#include <set>
using namespace std;

class Pawn: public Piece
{
private:
   char letter;

public:

   //Pawn();
   //Constructor
   Pawn(int r, int col, bool white);

   //Inherited Functions
   char getLetter();
   virtual void display(ogstream &gout);
   set<int> getMoves(Piece** board);
};

