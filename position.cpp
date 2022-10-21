/***********************************************************************
 * Source File:
 *    Position
 * Author:
 *    Ben, Star, Mike
 * Summary:
 *    This code handles Position.  
 ************************************************************************/
 #include "position.h"

Position::Position(Position position, int move)
{
   int x = position.location;

   this->location = position.location + move;
}


/*****************************************************************
 * SET ROW
 * Sets row
 ****************************************************************/
void Position::setRow(int r)
{  
   int c = location % 8;
   this->location = ((r - 1) * 8) + c;
};

/*****************************************************************
 * SET COL
 * Set Column
 ****************************************************************/
void Position::setCol(int c)
{
   int r = location / 8;
   this->location = (r * 8) + c;

};


bool Position::hasWrapped(int rowDelta, int colDelta, Position newPosition)
{
   int currentRow = getRow();
   int newRow = newPosition.getRow();
   int newCol = newPosition.getColumn();

   return (getRow() + rowDelta == newRow) && getColumn() + colDelta == newCol;
}

;