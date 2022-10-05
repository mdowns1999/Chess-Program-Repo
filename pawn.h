#pragma once
#include "piece.h"
#include <set>

class Pawn : public Piece
{
public:

   //Constructor
   Pawn(int r, int c, bool white);

   //Inherited Functions
   virtual char getLetter() {};
   virtual void display() {};
   virtual set<int> getMoves() {};
};

