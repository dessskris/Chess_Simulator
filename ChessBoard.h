#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <map>
#include <string>
#include "helper.h"

using namespace std;

class ChessPiece;

class ChessBoard {
 private:
  // Map to store a chess piece in a position
  map <string, ChessPiece*> position;

  Colour turn;
  bool capture_sign;
  ChessPiece *captured_piece;

  string black_king_pos;
  string white_king_pos;

  void initialise_board();
  void initialise_position();
  void switch_turn();

  // Move the piece in SOURCE_SQUARE to DESTINATION_SQUARE,
  // assuming DESTINATION_SQUARE is empty
  void move(const string source_square, const string destination_square);

  // Move the piece in SOURCE_SQUARE to DESTINATION_SQUARE,
  // and capturing the piece in DESTINATION_SQUARE
  void move_capture(const string source_square, const string destination_square);

  // Undo the move and return the captured piece back to OLD_DESTINATION_SQUARE
  void undo_capture(const string old_source_square, const string old_destination_square);

  // Move the piece in SOURCE_SQUARE to DESTINATION_SQUARE,
  // and confirm that its own King is not in check.
  // In any case the move will be undone, hence the word 'pretend'.
  bool pretend_move_king_ok(string source_square, string destination_square, Colour colour);

  // Update black_king_pos or white_king_pos
  bool find_king(Colour colour);

  // Confirm whether King of this COLOUR is in check
  bool king_in_check(Colour colour);

  // Find out if there is any valid move that COLOUR can make
  bool any_valid_move(Colour colour);
  
 public:
  ChessBoard();
  ~ChessBoard();
  ChessPiece* operator [](string pos);
  void capture(); // used in ChessPiece class
  Type get_piece_type(string pos); // used in ChessPiece class
  Colour get_piece_colour(string pos); // used in ChessPiece class
  void print_board(); // for checking
  void submitMove(const string source_square, const string destination_square);
  void resetBoard();
};

#endif
