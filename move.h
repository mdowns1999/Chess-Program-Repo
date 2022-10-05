#pragma once
#include "position.h"
#include "piece.h"
#include <string>
#include <iostream>
using namespace std;

class Move
{
private:
   Position source;
   Position dest;
   char piece;
   bool enpassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   string error;

public:
   Move(); //Constructor
   string getText();
   Position getSrc();
   Position getDes();

   //Getters
   const char getPromotion() { return piece = 'P'; };
   const bool getEnpassant() { return enpassant = false; };
   const bool getCastleK() { return castleK = false; };
   const bool getCastleQ() { return castleQ = false; };
   const bool getWhiteMove() { return isWhite = true; };

   //Setters
   void setEnpassant();
   bool setCastleK();
   bool setCastleQ();
   bool setWhiteMove();

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

