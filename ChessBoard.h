#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <map>
#include <string>
#include "helper.h"
#include "ChessPiece.h"

using namespace std;

class ChessPiece;

class ChessBoard {
 private:
  map <string, ChessPiece*> position;
  Colour turn;
  bool capture_sign;
  
 public:
  ChessBoard();
  ~ChessBoard();
  ChessPiece* operator [](string pos);
  void initialisePosition();
  void printBoard();
  void move(const string source_square, const string destination_square);
  void capture();
  void switch_turn();
  void submitMove(const string source_square, const string destination_square);
  void resetBoard();
};

#endif
