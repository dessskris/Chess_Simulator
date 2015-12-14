#ifndef PAWNPIECE_H
#define PAWNPIECE_H

#include <cmath>
#include <string>
#include "helper.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

using namespace std;

class PawnPiece : public ChessPiece {
 public:
  PawnPiece(Colour _c, ChessBoard *_b);
  virtual ~PawnPiece();

  /* The pawn may move forward to the unoccupied square immediately in front
     of it on the same file;
     or on its first move it may advance two squares along the same file
     provided both squares are unoccupied;
     or it may move to a square occupied by an opponent's piece which is
     diagonally in front of it on an adjacent file, capturing that piece.*/
  virtual bool is_valid_move(const string source_square, const string destination_square);
};

#endif
