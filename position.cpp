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
   cout << "Location" << location << endl;
   //cout << "location % 8: " << (location % 8) << endl;
   //cout << "location + delta )% 8 != 7: " << ((location + delta) % 8 != 7) << endl;
   if(location % 8 == 7 && ((location + delta) % 8 == 0 && (location + delta) / 8 != location / 8))
      return false;

   if(location % 8 == 0 && ((location + delta )% 8 == 7 && (location + delta) / 8 != location / 8))
      return false;
   

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

};