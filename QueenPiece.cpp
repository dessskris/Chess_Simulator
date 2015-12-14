#include "QueenPiece.h"
#include "ChessBoard.h"
using namespace std;

QueenPiece::QueenPiece(Colour _c, ChessBoard *_b) : ChessPiece(Queen, _c, _b) {}
QueenPiece::~QueenPiece() {}

bool QueenPiece::is_valid_move(const string source_square, const string destination_square) {
  // The queen can move any number of squares along rank, file, or diagonal, but it may not leap over other pieces.

  // move along the file
  if (source_square[0] == destination_square[0]) {
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

  // move along the rank
  if (source_square[1] == destination_square[1]) {
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

  // diagonal move
  if (abs(source_square[0] - destination_square[0]) ==
      abs(source_square[1] - destination_square[1])) {
    char start_f, start_r, finish_f, finish_r;

    // Move to the right and up, or to the left and down
    if ((source_square[0] - destination_square[0]) ==
	(source_square[1] - destination_square[1])) {
      if (source_square[0] > destination_square[0]) {
	start_f = destination_square[0] + 1;
	finish_f = source_square[0] - 1;
	start_r = destination_square[1] + 1;
	finish_r = source_square[1] - 1;
      } else {
	start_f = source_square[0] + 1;
	finish_f = destination_square[0] - 1;
	start_r = source_square[1] + 1;
	finish_r = destination_square[1] - 1;
      }
      char square[3];
      square[2] = '\0';
      for (char file = start_f, rank = start_r;
	   (file <= finish_f) && (rank <= finish_r);
	   file++, rank++) {
	square[0] = file;
	square[1] = rank;
	if (!is_empty(square)) {
	  return 0;
	}
      }
    }
    // Move to the right and down, or to the left and up
    else {
      if (source_square[0] > destination_square[0]) {
	start_f = source_square[0] + 1;
	finish_f = destination_square[0] - 1;
	start_r = destination_square[1] - 1;
	finish_r = source_square[1] + 1;
      } else {
	start_f = source_square[0] + 1;
	finish_f = destination_square[0] - 1;
	start_r = source_square[1] - 1;
	finish_r = destination_square[1] + 1;
      }
      char square[3];
      square[2] = '\0';
      for (char file = start_f, rank = start_r;
	   (file <= finish_f) && (rank >= finish_r);
	   file++, rank--) {
	square[0] = file;
	square[1] = rank;
	if (!is_empty(square)) {
	  return 0;
	}
      }
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
