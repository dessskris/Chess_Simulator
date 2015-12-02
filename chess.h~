#include <map>

using namespace std;

enum Colour {Black, White};
enum Type (King, Queen, Bishop, Knight, Rook, Pawn};

class ChessBoard {
 private:
  map <char, ChessPiece> position;
  Colour turn;
  ChessPiece *black_piece[16];
  ChessPiece *white_piece[16];
  
 public:
  ChessBoard();
  submitMove(char source_square[3], char destination_square[3]);
  resetBoard();
};

ChessBoard::ChessBoard() {
  


  position.insert (pair<char, ChessPiece> ('A8', black_piece[0]));
  position.insert (pair<char, ChessPiece> ('B8', black_piece[1]));
}


void ChessBoard::InitialisePieces() {
  black_piece[0] = new Rook(Black);
  black_piece[1] = new Knight(Black);
}


class ChessPiece {
 private:
  Colour colour;
  Type type;
 public:
  ChessPiece();
  ChessPiece(Type _t, Colour _c);
  string get_colour();
  string get_type();
  bool is_valid_move(char source_square[3], char destination_square[3]);
};

class King : public ChessPiece {
  
 public:
 King(Colour colour) : ChessPiece(0, colour);
};
