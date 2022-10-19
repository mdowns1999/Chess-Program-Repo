#pragma once
#include "board.h"
#include <string>
#include <iostream>
using namespace std;

class Move
{
private:
   Position source;
   Position dest;
   char piece;
   bool promotion;
   bool enpassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   string error;

public:
   Move(); //Constructor
   string getText();
   Position getSrc() { return source; };
   Position getDes() { return dest; };
   void setSrc(Position srcPosition);
   void setDes();

   //Getters
   const bool getPromotion() { return promotion;       };
   const bool getEnpassant() { return enpassant = false; };
   const bool getCastleK()   { return castleK = false;   };
   const bool getCastleQ()   { return castleQ = false;   };
   const bool getWhiteMove() { return isWhite = true;    };

   //Setters
   void setEnpassant();
   bool setCastleK();
   bool setCastleQ();
   bool setWhiteMove();
   bool setPromotion() { promotion = true; return promotion; };

    //Operators Here
   //bool operator == (Move& move)
   //{
   //   return piece.getLetter() == move;
   //};
   //
   //bool operator == (const& piece, Piece pt)
   //{
   //   return piece.getLetter() == pt;
   //};


 


};

