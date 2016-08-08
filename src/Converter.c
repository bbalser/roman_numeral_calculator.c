#include <stdlib.h>
#include <string.h>

char * str_repeat(char *s1, int n) {
  size_t slen = strlen(s1);
  char *dest = malloc(n*slen+1);

  for (int i = 0; i < n; i++) {
    dest = strcat(dest, s1);
  }

  return dest;
}

char * arabicToRoman(int arabic) {
  if (arabic == 5) {
    return "V";
  }
  if (arabic == 4) {
    return "IV";
  }
  return str_repeat("I", arabic);
}
