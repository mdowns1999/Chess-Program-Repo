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
 * GET LOCATION
 * Returns the Location
 ****************************************************************/
int Position::getLocation()
{
   return location;
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
   return location % 8 + 1;
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
   return (location >= 0 && location <= 63);
};

/*****************************************************************
 * IS VALID
 * Checks position is valid.
 ****************************************************************/
bool Position::isValid(int delta)
{
   //assert(delta == 1 || delta == 8 || )
   
   int dCol = (delta + location) % 8;
   int dRow = (delta + location) / 8;

   int c = location % 8;
   int r = location / 8;
   cout << "*****************************" << endl;

   cout << "Location: " << location << endl;
   cout << "Delta: " << delta << endl;
   cout << "dCOL " << dCol << endl;
   cout << "dRow " << dRow << endl;
   cout << "c " << c << endl;
   cout << "r " << r << endl;
   cout << "Delta + Location: " << location + delta << endl;
   cout << "************************************"<< endl;
   // if (c + dCol > 8 || c + dCol < 0)
   //    return false;
   
   if (c == 7 && dCol == 0 && dRow != r)
      return false;
   if (c == 0 && dCol == 7 && dRow != r)
      return false;
   
   //cout << "location % 8: " << (location % 8) << endl;
   //cout << "location + delta )% 8 != 7: " << ((location + delta) % 8 != 7) << endl; && (location + delta) / 8 != location / 8)
   //if(location % 8 == 7 && ((location + delta) % 8 == 0 ))
   //   return false;

   //if(location % 8 == 0 && ((location + delta )% 8 == 7 ))
   //   return false;
   //if (location / 8 == 7 && ((location + delta) / 8 == 0))
   //   return false;

   //if (location / 8 == 0 && ((location + delta) / 8 == 7))
   //   return false;

   //Check that we do not go off the board to the left
   //if (location % 8 == 0)
    //  return false;

   //return (location + delta >= 0 && location + delta <= 63);


   return (location + delta >= 0 && location + delta <= 63);
};

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

}
bool Position::hasWrapped(int rowDelta, int colDelta, Position newPosition)
{
   int currentRow = getRow();
   int newRow = newPosition.getRow();
   int newCol = newPosition.getColumn();
   cout << "********************************" << endl;
  /* cout << "delta: " << delta << endl;
   cout << "current row: " << currentRow << endl;
   cout << "new row: " << newRow << endl;*/
   //if(delta >= 7) 
   //{
   //   rowDelta = 1;
   //   
   //}
   //else if (delta <= -7)
   //{
   //   rowDelta = -1;
   //}

   cout << "location + rowDelta" << location + rowDelta << endl;


   return (getRow() + rowDelta == newRow) && getColumn() + colDelta == newCol;
}

;