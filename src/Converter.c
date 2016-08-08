#include <stdlib.h>
#include <string.h>

char * str_repeat(char *s1, int n) {
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
  {"X", 10},
  {"IX", 9},
  {"V", 5},
  {"IV", 4},
  {"", 0}
};


char * arabicToRoman(int arabic) {
  char *roman = calloc(10, 1);
  int remaining = arabic;

  for (int i = 0; i < 4; i++) {
    if (remaining >= roman_values[i].arabic) {
      roman = strcat(roman, roman_values[i].roman);
      remaining -= roman_values[i].arabic;
    }
  }

  return strcat(roman, str_repeat("I", remaining));
}
