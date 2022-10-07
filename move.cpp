#include "move.h"

string Move::getText()
{
   return "A5B6";
};

Position Move::getSrc()
{
   return source;
};

Position Move::getDes()
{
   return dest;
};


void Move::setEnpassant()
{

};

bool Move::setCastleK()
{
   return false;
};

bool Move::setCastleQ()
{
   return false;
};

bool Move::setWhiteMove()
{
   return false;
};
