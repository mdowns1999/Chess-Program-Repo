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

   //Pawn();
   //Constructor
   Knight(int r, int col, bool white);

   //Inherited Functions

   char getLetter();
   virtual void display(ogstream& gout);
   set<int> getMoves(Board& board);
};
