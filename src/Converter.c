#include <stdlib.h>
#include <string.h>

char * strrepeat(char *s1, int n) {
  size_t slen = strlen(s1);
  char *dest = calloc(n*slen+1, 1);

  for (int i = 0; i < n; i++) {
    dest = strcat(dest, s1);
  }

  return dest;
}

typedef struct {
  char * roman;
  int arabic;
} RomanValue;

static RomanValue roman_values[] = {
  {"M", 1000},
  {"CM", 900},
  {"D", 500},
  {"CD", 400},
  {"C", 100},
  {"XC", 90},
  {"L", 50},
  {"XL", 40},
  {"X", 10},
  {"IX", 9},
  {"V", 5},
  {"IV", 4},
  {"I", 1},
  {"", 0}
};

char * arabicToRoman(int arabic) {
  char *roman = calloc(15, 1);
  int remaining = arabic;

  for (int i = 0; 0 != roman_values[i].arabic; i++) {
    int times = remaining / roman_values[i].arabic;
    remaining = remaining % roman_values[i].arabic;

    roman = strcat(roman, strrepeat(roman_values[i].roman, times));
  }

  return roman;
}
