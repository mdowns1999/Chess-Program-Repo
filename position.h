/***********************************************************************
 * Header File:
 *    Position : A Position on the board
 * Author:
 *   Ben, Star, and Mike
 * Summary:
 *    This keeps track of the position for the game.
 ************************************************************************/

#pragma once
#include <iostream>
using namespace std;

class Position
{
private:
   int location;

public:
   //Constructors
   Position() { location = 0;}
   Position(Position position, int move);

   //Getters
   int getLocation() { return location; }
   int getRow() { return location / 8 + 1; }
   int getColumn() { return location % 8 + 1; }

   //Setters

   void setRow(int r);
   void setCol(int c);
   void setLocation(int l) { location = l; }


   bool isValid() { return (location >= 0 && location <= 63); }
   void addLocation(int delta) { location = location + delta; }
   bool hasWrapped(int deltaRow, int deltaCol, Position newPosition);

};
