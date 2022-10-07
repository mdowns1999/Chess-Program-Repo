#include "pawn.h"



//Inherited Functions
char Pawn::getLetter()
{ 
   if (fWhite)
      return 'P';
   else
      return 'p';
}
//virtual void display() {};
//virtual set<int> getMoves() { return pawnMoves;};