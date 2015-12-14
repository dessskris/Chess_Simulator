#ifndef ROOKPIECE_H
#define ROOKPIECE_H

#include <cmath>
#include <string>
#include "helper.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

using namespace std;

class RookPiece : public ChessPiece {
 public:
  RookPiece(Colour _c, ChessBoard *_b);
  virtual ~RookPiece();

  // The rook can move any number of squares along any rank or file, but may not leap over other pieces.
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

#endif
