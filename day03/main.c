#include "../utils.h"

#include <stdio.h>
#include <string.h>

#define MAX_L 100
#define ASCII_LOWER_BEGIN 91

char findCommonCharInTriplets(char *str1, char *str2, char *str3) {
  for (int i = 0; i < strlen(str1); i++) {
    char *match1 = strchr(str2, str1[i]);
    char *match2 = strchr(str3, str1[i]);

    if (match1 && match2) {
      return *match1;
    };
  }
  return 0;
}

int deriveScoreFromChar(char t) {
  if (t < ASCII_LOWER_BEGIN) {
    return t - 38;
  }

  return t - 96;
}

int main(void) {
  FILE *input = fopen("./input.txt", "r");

  size_t flength = utl_fileLength("./input.txt");

  char lines[flength][MAX_L];

  int i = 0;
  while (!feof(input)) {
    fgets(lines[i], MAX_L, input);
    i++;
  }

  int part2 = 0;

  for (int i = 0; i < flength; i += 3) {
    part2 += deriveScoreFromChar(
        findCommonCharInTriplets(lines[i], lines[i + 1], lines[i + 2]));
  }

  printf("Elf group item priorities %d\n", part2);
  fclose(input);
}
