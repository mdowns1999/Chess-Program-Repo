/***********************************************************************
 * Source File:
 *    Piece
 * Author:
 *    Mike, Ben, and Star
 * Summary:
 * This is code will be the parent class for all the pieces for the chess
 * game.
 ************************************************************************/

#include "piece.h"

/*****************************************************************
 * PIECE CONSTRUCTOR
 * Set all the default variables
 ****************************************************************/
Piece::Piece()
{
   fWhite = false;
   nMove = 0;
   lastMove = 0;
   letter = 'u';
}

/*****************************************************************
* PIECE NON DEFAULT CONSTRUCTOR
* Set all the variables
****************************************************************/
Piece::Piece(int r, int c, bool white) 
{
   this->fWhite = white;
   this->nMove = 0;
   this->lastMove = 0;
   this->position.setRow(r);
   this->position.setCol(c);
   letter = 'u';  
};

/*****************************************************************
* ASSIGN
* Assign Piece a Position
******************************************************************/
void Piece::assign(Position position)
{
   //Set Position
   this->position = position;

   //Increase the times the Piece Moved
   nMove++;
};

/*****************************************************************
* ASSIGN
* Assign the Piece
*****************************************************************/
void Piece::assign(Piece piece)
{
   this->position = piece.position;
   this->fWhite = piece.fWhite;
};


/*****************************************************************
* JUST MOVED
* Tells if Piece has just moved
*****************************************************************/
bool Piece::justMoved()
{
   return false;
};


