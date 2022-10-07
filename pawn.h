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
   set<int> pawnMoves;


   Pawn();
   //Constructor
   Pawn(int r, int c, bool white);

   //Inherited Functions
   char getLetter();
   //virtual void display() {};
   set<int> getMoves(Board &board);
};

