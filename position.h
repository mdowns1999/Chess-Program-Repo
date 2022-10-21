#pragma once
#include <iostream>
using namespace std;

class Position
{
private:
   int location;

public:
   Position() { location = 0;}
   Position(Position position, int move);
   int getLocation() { return location; }
   int getRow() { return location / 8 + 1; }
   int getColumn() { return location % 8 + 1; }
   bool isValid() { return (location >= 0 && location <= 63); }
   void addLocation(int delta) { location = location + delta; }
   void setRow(int r);
   void setCol(int c);
   void setLocation(int l) { location = l; }
   bool hasWrapped(int deltaRow, int deltaCol, Position newPosition);

};
