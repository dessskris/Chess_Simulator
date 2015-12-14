#include "helper.h"
using namespace std;

bool valid_square(const string square) {
  if (square.length() != 2) {
    return 0;
  }
  if (square[0] < 'A' || square[0] > 'H') {
    return 0;
  }
  if (square[1] < '1' || square[1] > '8') {
    return 0;
  }
  return 1;
}

