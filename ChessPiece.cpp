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

bool ChessPiece::is_valid_move(map <string, ChessPiece*> &chess_board, const string source_square, const string destination_square) {
  return 0;
}

bool is_empty(map <string, ChessPiece*> &position, const string square) {
  if (position[square] != NULL)
    return 0;
  else
    return 1;
}





KingPiece::KingPiece(Colour _c) : ChessPiece(King, colour) {
}

bool KingPiece::is_valid_move(map <string, ChessPiece*> &chess_board, const string source_square, const string destination_square) {
  // The king moves one square in any direction
  if ( (abs(source_square[0] - destination_square[0]) == 1) &&
       (abs(source_square[1] - destination_square[1]) == 1) )
    return 1;
  else
    return 0;
}

QueenPiece::QueenPiece(Colour _c) : ChessPiece(Queen, colour) {
}

bool QueenPiece::is_valid_move(map <string, ChessPiece*> &chess_board, const string source_square, const string destination_square) {
  // The queen can move any number of squares along rank, file, or diagonal, but it may not leap over other pieces.

  // move along the file
  if (source_square[0] == destination_square[0]) {
    char start, finish;
    if (source_square[1] - destination_square[1] > 0) {
      start = destination_square[1];
      finish = source_square[1];
    } else {
      start = source_square[1];
      finish = destination_square[1];
    }
    char square[2];
    square[0] = source_square[0];
    for (char rank = start; rank < finish; rank++) {
      square[1] = rank;
      if (!is_empty(chess_board, square))
	return 0;
    }
    return 1;
  }

  // move along the rank
  if (source_square[1] == destination_square[1]) {
    char start, finish;
    if (source_square[0] - destination_square[0] > 0) {
      start = destination_square[0];
      finish = source_square[0];
    } else {
      start = source_square[0];
      finish = destination_square[0];
    }
    char square[2];
    square[1] = source_square[1];
    for (char file = start; file < finish; file++) {
      square[0] = file;
      if (!is_empty(chess_board, square))
	return 0;
    }
    return 1;
  }

  // diagonal move
  if (abs(source_square[0] - destination_square[0]) == abs(source_square[1] - destination_square[1])) {
    char start_f, start_r, finish_f, finish_r;

    if (source_square[0] - destination_square[0] > 0) {
      start_f = destination_square[0];
      finish_f = source_square[0];
    } else {
      start_f = source_square[0];
      finish_f = destination_square[0];
    }

    if (source_square[1] - destination_square[1] > 0) {
      start_r = destination_square[1];
      finish_r = source_square[1];
    } else {
      start_r = source_square[1];
      finish_r = destination_square[1];
    }

    char square[2];
    for (char file = start_f, rank = start_r; (file < finish_f) && (rank < finish_r); file++, rank++) {
      square[0] = file;
      square[1] = rank;
      if (!is_empty(chess_board, square))
	return 0;
    }
    return 1;
  }

  return 0;
}

BishopPiece::BishopPiece(Colour _c) : ChessPiece(Bishop, colour) {
}

bool BishopPiece::is_valid_move(map <string, ChessPiece*> &chess_board, const string source_square, const string destination_square) {
  // The bishop can move any number of squares diagonally, but may not leap over other pieces.

  if (abs(source_square[0] - destination_square[0]) == abs(source_square[1] - destination_square[1])) {
    char start_f, start_r, finish_f, finish_r;

    if (source_square[0] - destination_square[0] > 0) {
      start_f = destination_square[0];
      finish_f = source_square[0];
    } else {
      start_f = source_square[0];
      finish_f = destination_square[0];
    }

    if (source_square[1] - destination_square[1] > 0) {
      start_r = destination_square[1];
      finish_r = source_square[1];
    } else {
      start_r = source_square[1];
      finish_r = destination_square[1];
    }

    char square[2];
    for (char file = start_f, rank = start_r; (file < finish_f) && (rank < finish_r); file++, rank++) {
      square[0] = file;
      square[1] = rank;
      if (!is_empty(chess_board, square))
	return 0;
    }
    return 1;
  }
  return 0;
}

KnightPiece::KnightPiece(Colour _c) : ChessPiece(Knight, colour) {
}

bool KnightPiece::is_valid_move(map <string, ChessPiece*> &chess_board, const string source_square, const string destination_square) {
  // The knight moves to any of the closest squares that are not on the same rank, file, or diagonal,
  // thus the move forms an "L"-shape: two squares vertically and one square horizontally, or
  // two squares horizontally and one square vertically.
  // The knight is the only piece that can leap over other pieces.

  // two squares vertically and one square horizontally
  if ((abs(source_square[1] - destination_square[1]) == 2) &&
      (abs(source_square[0] - destination_square[0]) == 1))
    return 1;

  // two squares horizontally and one square vertically
  if ((abs(source_square[0] - destination_square[0]) == 2) &&
      (abs(source_square[1] - destination_square[1]) == 1))
    return 1;

  return 0;
}

RookPiece::RookPiece(Colour _c) : ChessPiece(Rook, colour) {
}

bool RookPiece::is_valid_move(map <string, ChessPiece*> &chess_board, const string source_square, const string destination_square) {
  // The rook can move any number of squares along any rank or file, but may not leap over other pieces.
  if (source_square[0] == destination_square[0]) { // same file
    char start, finish;
    if (source_square[1] - destination_square[1] > 0) {
      start = destination_square[1];
      finish = source_square[1];
    } else {
      start = source_square[1];
      finish = destination_square[1];
    }
    char square[2];
    square[0] = source_square[0];
    for (char rank = start; rank < finish; rank++) {
      square[1] = rank;
      if (!is_empty(chess_board, square))
	return 0;
    }
    return 1;
  }

  if (source_square[1] == destination_square[1]) { // same rank
    char start, finish;
    if (source_square[0] - destination_square[0] > 0) {
      start = destination_square[0];
      finish = source_square[0];
    } else {
      start = source_square[0];
      finish = destination_square[0];
    }
    char square[2];
    square[1] = source_square[1];
    for (char file = start; file < finish; file++) {
      square[0] = file;
      if (!is_empty(chess_board, square))
	return 0;
    }
    return 1;
  }

  return 0;
}

PawnPiece::PawnPiece(Colour _c) : ChessPiece(Pawn, colour) {
  has_moved = 0;
}

bool PawnPiece::is_valid_move(map <string, ChessPiece*> &chess_board, const string source_square, const string destination_square) {
  // The pawn may move forward to the unoccupied square immediately in front of it on the same file;
  // or on its first move it may advance two squares along the same file provided both squares are
  // unoccupied; or it may move to a square occupied by an opponent's piece which is diagonally
  // in front of it on an adjacent file, capturing that piece.

  //moving backwards
  if (colour == Black) {
    if (source_square[1] < destination_square[1])
      return 0;
  }
  if (colour == White) {
    if (source_square[1] > destination_square[1])
      return 0;
  }

  // first move, advance two squares along the same file provided both squares are unoccupied
  if (!has_moved) {
    if ((source_square[0] == destination_square[0]) &&
	(abs(source_square[1] - destination_square[1]) == 2)) {
      char square_in_between[2];
      square_in_between[0] = source_square[0];
      if (colour == Black)
	square_in_between[1] = source_square[1] - 1;
      if (colour == White)
	square_in_between[1] = source_square[1] + 1;

      if (is_empty(chess_board, square_in_between) && is_empty(chess_board, destination_square))
	return 1;
      return 0;
    }
  }

  // move forward to the unoccupied square immediately in front of it on the same file
  if ((source_square[0] == destination_square[0]) &&
      (abs(source_square[1] - destination_square[1]) == 1)) {
    if (is_empty(chess_board, destination_square))
      return 1;
    return 0;
  }

  // move to a square occupied by an opponent's piece which is diagonally in front of it on an adjacent file, capturing that piece
  if ((abs(source_square[0] - destination_square[0]) == 1) &&
      (abs(source_square[1] - destination_square[1]) == 1)) {
    if (!is_empty(chess_board, destination_square)) {
      //capture
      return 1;
    }
  }

  return 0;
}
