#pragma once

class Position
{
private:
   double squareWidth;
   double squareHeight;



public:
   int location;

   Position() { location = 0;};
   Position(Position position, int move);
   int getLocation();
   int getRow();
   int getColumn();
   int getX();
   int getY();
   bool isValid();
   void setRow(int r);
   void setCol(int c);
   void set(int r, int c);
   void adjustRow(int dRow);
   void adjustCol(int dCol);

   //Operators down below

};
