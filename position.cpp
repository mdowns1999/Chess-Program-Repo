#include "position.h"

Position::Position(Position position, int move)
{
   this->location = position.location + move;
}





/*****************************************************************
 * GET LOCATION
 * Returns the Location
 ****************************************************************/
int Position::getLocation()
{
   return 0;
};

/*****************************************************************
 * GET ROW
 * Return row
 ****************************************************************/
int Position::getRow()
{
   return location / 8 + 1;
};

/*****************************************************************
 * GET COLUMN
 * Returns Column
 ****************************************************************/
int Position::getColumn()
{
   return location % 8;
};

/*****************************************************************
 * GET X
 * Return X
 ****************************************************************/
int Position::getX()
{
   return 2;
};

/*****************************************************************
 * GET Y
 * Return Y
 ****************************************************************/
int Position::getY()
{
   return 2;
};

/*****************************************************************
 * IS VALID
 * Checks position is valid.
 ****************************************************************/
bool Position::isValid()
{
   return true;
};

/*****************************************************************
 * SET ROW
 * Sets row
 ****************************************************************/
void Position::setRow(int r)
{  
   int c = location % 8;
   location = ((r - 1) * 8) + c;
};

/*****************************************************************
 * SET COL
 * Set Column
 ****************************************************************/
void Position::setCol(int c)
{
   int r = location / 8;
   location = (r * 8) + c;

};

/*****************************************************************
 * SET
 * Set Position
 ****************************************************************/
void Position::set(int r, int c)
{

};

/*****************************************************************
 * ADJUST ROW
 * Adjusts Row
 ****************************************************************/
void Position::adjustRow(int dRow)
{

};

/*****************************************************************
 * ADJUST COL
 * Adjusts Column
 ****************************************************************/
void Position::adjustCol(int dCol)
{

};