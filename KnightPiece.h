#ifndef KNIGHTPIECE_H
#define KNIGHTPIECE_H

#include <cmath>
#include <string>
#include "helper.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

using namespace std;

class KnightPiece : public ChessPiece {
 public:
  KnightPiece(Colour _c, ChessBoard *_b);
  virtual ~KnightPiece();

  /* The knight moves to any of the closest squares that are not on the same
     rank, file, or diagonal, thus the move forms an "L"-shape:
     two squares vertically and one square horizontally, or
     two squares horizontally and one square vertically.
     The knight is the only piece that can leap over other pieces.*/
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

#endif
