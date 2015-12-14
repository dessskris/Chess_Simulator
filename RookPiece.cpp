#include "RookPiece.h"
#include "ChessBoard.h"
using namespace std;

RookPiece::RookPiece(Colour _c, ChessBoard *_b) : ChessPiece(Rook, _c, _b) {}
RookPiece::~RookPiece() {}

bool RookPiece::is_valid_move(const string source_square, const string destination_square) {
  // The rook can move any number of squares along any rank or file, but may not leap over other pieces.
  if (source_square[0] == destination_square[0]) { // same file
    char start, finish;
    if (source_square[1] > destination_square[1]) {
      start = destination_square[1] + 1;
      finish = source_square[1] - 1;
    } else {
      start = source_square[1] + 1;
      finish = destination_square[1] - 1;
    }
    char square[3];
    square[2] = '\0';
    square[0] = source_square[0];
    for (char rank = start; rank <= finish; rank++) {
      square[1] = rank;
      if (!is_empty(square))
	return 0;
    }
    if (check_capture(destination_square)) {
      if (board->get_piece_colour(destination_square) == colour) {
	board->capture();
	return 0;
      }
    }
    return 1;
  }

  if (source_square[1] == destination_square[1]) { // same rank
    char start, finish;
    if (source_square[0] > destination_square[0]) {
      start = destination_square[0] + 1;
      finish = source_square[0] - 1;
    } else {
      start = source_square[0] + 1;
      finish = destination_square[0] - 1;
    }
    char square[3];
    square[2] = '\0';
    square[1] = source_square[1];
    for (char file = start; file <= finish; file++) {
      square[0] = file;
      if (!is_empty(square))
	return 0;
    }
    if (check_capture(destination_square)) {
      if (board->get_piece_colour(destination_square) == colour) {
	board->capture();
	return 0;
      }
    }
    return 1;
  }

  return 0;
}
