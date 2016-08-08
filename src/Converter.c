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

char * arabicToRoman(int arabic) {
  char *roman = calloc(10, 1);
  int remaining = arabic;

  if (remaining == 9) {
    roman = strcat(roman, "IX");
    remaining -= 9;
  }

  if (remaining >= 5) {
    roman = strcat(roman, "V");
    remaining -= 5;
  }

  if (remaining == 4) {
    roman = strcat(roman, "IV");
    remaining -= 4;
  }

  return strcat(roman, str_repeat("I", remaining));
}
