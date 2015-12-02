#include <string>

using namespace std;

class ChessPiece {
 private:
  Colour colour;
  Type type;
 public:
  ChessPiece();
  ChessPiece(Type _t, Colour _c);
  string get_colour();
  string get_type();
  virtual bool is_valid_move(const string source_square[3], const string destination_square[3]);
};


class King : public ChessPiece {

 public:
 King(Colour colour) : ChessPiece(0, colour);
};

