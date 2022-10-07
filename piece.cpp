#include "piece.h"


Piece::Piece()
{
   r = 1;
   c = 0;
   fWhite = true;
   nMove = 0;
   lastMove = 0;
   position.setRow(r);
   position.setCol(c);
   letter = 'u';
}

Piece::Piece(int r, int c, bool white) 
{
   this->r = r;
   this->c = c;
   this->fWhite = white;
   this->nMove = 0;
   this->lastMove = 0;
   this->position.setRow(r);
   this->position.setCol(c);
   letter = 'u';

   cout << "Before Letter: " << letter << endl;    

};

/*****************************************************************
 * ASSIGN
 * Assign Piece a Position
 ****************************************************************/
void Piece::assign(Position position)
{

   this->position.setRow(position.getRow());
   this->position.setCol(position.getColumn());

   this->r = position.getRow();
   this->c = position.getColumn();

   nMove++;
};

/*****************************************************************
 * ASSIGN
 * Assign the Piece
 ****************************************************************/
void Piece::assign(Piece piece)
{
   this->r = piece.r;
   this->c = piece.c;

   this->position.setRow(piece.r);
   this->position.setCol(piece.c);
   this->fWhite = piece.fWhite;

};

/*****************************************************************
 * IS WHITE
 * Return if Piece is white or not
 ****************************************************************/
bool Piece::isWhite()
{
   return fWhite;
};

/*****************************************************************
 * IS MOVE
 * See if Piece can move
 ****************************************************************/
bool Piece::isMove()
{
   return (nMove != 0);
};

/*****************************************************************
 * GET NUMBER OF MOVES
 * Returns the number of moves
 ****************************************************************/
int Piece::getNMoves()
{
   return nMove;
};

/*****************************************************************
 * GET POSITION
 * Returns Position
 ****************************************************************/
Position Piece::getPosition()
{
   return position;
};

/*****************************************************************
 * JUST MOVED
 * Tells if Piece has just moved
 ****************************************************************/
bool Piece::justMoved()
{
   return false;
};

