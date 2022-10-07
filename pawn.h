#pragma once
#include "piece.h"
#include <set>

class Pawn: public Piece
{
public:
   //set<int> pawnMoves;


   //Constructor
   Pawn(int r, int c, bool white) : Piece() {};

   //Inherited Functions
   char getLetter();
   //virtual void display() {};
   //virtual set<int> getMoves() { return pawnMoves;};
};

