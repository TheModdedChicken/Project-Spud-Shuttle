#include <cstring>

char * combineChar (char * out, const char * in[]) {
  for (int i = 0; i < (int)sizeof(in) - 1; i++) {
    out = strcat(out, in[i]);
  }

  return out;
};

char * intToChar (int theInt) {
  char integer_string[32];

  sprintf(integer_string, "%d", theInt);

  return integer_string;
}