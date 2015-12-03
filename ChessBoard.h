#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <map>
#include <string>
#include "ChessPiece.h"

using namespace std;


class ChessBoard {
 private:
  map <string, ChessPiece*> position;
  Colour turn;

  
 public:
  ChessBoard();
  ~ChessBoard();
  void InitialisePieces();
  void InitialisePosition();
  void submitMove(const string source_square, const string destination_square);
  void resetBoard();
};

#endif
