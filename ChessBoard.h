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
  string black_king_pos;
  string white_king_pos;
  ChessPiece *captured_piece;
  void initialise_board();
  void initialise_position();
  void switch_turn();
  void move(const string source_square, const string destination_square);
  void move_capture(const string source_square, const string destination_square);
  void undo_capture(const string old_source_square, const string old_destination_square);
  bool find_king(Colour colour);
  bool king_in_check(Colour colour);

  
 public:
  ChessBoard();
  ~ChessBoard();
  ChessPiece* operator [](string pos);
  void capture(); // used in ChessPiece class
  Type get_piece_type(string pos); // used in ChessPiece class
  Colour get_piece_colour(string pos); // used in ChessPiece class
  void printBoard();
  void submitMove(const string source_square, const string destination_square);
  void resetBoard();
};

#endif
