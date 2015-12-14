#ifndef HELPER_H
#define HELPER_H

#include <map>
#include <string>
#include <iostream>

using namespace std;

enum Colour {Black, White};
enum Type {King, Queen, Bishop, Knight, Rook, Pawn};

/* Check if SQUARE is a valid square in the format of two characters:
   A letter between A and H (inclusive), and
   A number between 1 and 8 (inclusive) */
bool valid_square(const string square);

#endif
