#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <cmath>
#include <map>
#include <string>

using namespace std;

enum Colour {Black, White};
enum Type {King, Queen, Bishop, Knight, Rook, Pawn};

class ChessPiece {
protected:
Type type;
Colour colour;
public:
ChessPiece();
ChessPiece(Type _t, Colour _c);
~ChessPiece();
string get_colour();
string get_type();
 virtual bool is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square);
};


class KingPiece : public ChessPiece {
public:
KingPiece(Colour _c);
bool is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square);
};

class QueenPiece : public ChessPiece {
public:
QueenPiece(Colour _c);
bool is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square);
};

class BishopPiece : public ChessPiece {
public:
BishopPiece(Colour _c);
bool is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square);
};

class KnightPiece : public ChessPiece {
public:
KnightPiece(Colour _c);
bool is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square);
};

class RookPiece : public ChessPiece {
public:
RookPiece(Colour _c);
bool is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square);
};

class PawnPiece : public ChessPiece {
public:
PawnPiece(Colour _c);
bool is_valid_move(map <string, ChessPiece> &chess_board, const string source_square, const string destination_square);
};



#endif