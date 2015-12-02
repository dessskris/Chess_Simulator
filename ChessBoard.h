#include <map>
#include <string>

using namespace std;

enum Colour {Black, White};
enum Type {King, Queen, Bishop, Knight, Rook, Pawn};

class ChessBoard {
 private:
  map <char, ChessPiece> position;
  Colour turn;
  ChessPiece *black_piece[16];
  ChessPiece *white_piece[16];
  
 public:
  ChessBoard();
  void submitMove(const string *source_square, const string *destination_square);
  void resetBoard();
};
