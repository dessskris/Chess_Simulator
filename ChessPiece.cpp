#include "ChessPiece.h"
using namespace std;

ChessPiece::ChessPiece() {
}

ChessPiece::ChessPiece(Type _t, Colour _c) : type(_t), colour(_c) {
}

ChessPiece::~ChessPiece() {
}

string ChessPiece::get_colour() {
  switch (colour) {
  case Black:
    return "Black";
  case White:
    return "White";
  default:
    return "Null";
  }
}

string ChessPiece::get_type() {
  switch (type) {
  case King:
    return "King";
  case Queen:
    return "Queen";
  case Bishop:
    return "Bishop";
  case Knight:
    return "Knight";
  case Rook:
    return "Rook";
  case Pawn:
    return "Pawn";
  default:
    return "Null";
  }
}

bool ChessPiece::is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square) {
  return 0;
}





KingPiece::KingPiece(Colour _c) : ChessPiece(King, colour) {
}

bool KingPiece::is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square) {
  // The king moves one square in any direction
  if ( (abs(source_square[0] - destination_square[0]) == 1) &&
       (abs(source_square[1] - destination_square[1]) == 1) )
    return 1;
  else
    return 0;
}

QueenPiece::QueenPiece(Colour _c) : ChessPiece(Queen, colour) {
}

bool QueenPiece::is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square) {
  cout << "hi";
  return 0;
}

BishopPiece::BishopPiece(Colour _c) : ChessPiece(Bishop, colour) {
}

bool BishopPiece::is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square) {
  cout << "hi";
  return 0;
}

KnightPiece::KnightPiece(Colour _c) : ChessPiece(Knight, colour) {
}

bool KnightPiece::is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square) {
  cout << "hi";
  return 0;
}

RookPiece::RookPiece(Colour _c) : ChessPiece(Rook, colour) {
}

bool RookPiece::is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square) {
  // The rook can move any number of squares along any rank or file, but may not leap over other pieces.
  if (source_square[0] == destination_square[0]) { // same file



  }

  return 0;
}

PawnPiece::PawnPiece(Colour _c) : ChessPiece(Pawn, colour) {
}

bool PawnPiece::is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square) {
  cout << "hi";
  return 0;
}
