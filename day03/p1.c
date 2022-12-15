#include "../utils.h"

#include <stdio.h>
#include <string.h>

#define MAX_L 100
#define ASCII_LOWER_BEGIN 91

char findCommoninDoublets(char *str1, char *str2) {
  for (int i = 0; i < strlen(str1); i++) {
    char *match = strchr(str2, str1[i]);
    if (match) {
      return *match;
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

  int part1 = 0;

  for (int i = 0; fgets(lines[i], MAX_L, input); i++) {
    char right[MAX_L], left[MAX_L];
    strcpy(right, lines[i] + strlen(lines[i]) / 2);
    strcpy(left, lines[i]);
    *(left + strlen(lines[i]) / 2) = '\0';
    part1 += deriveScoreFromChar(findCommoninDoublets(lines[i], right));
  }

  printf("The sum of the priorities is %d\n", part1);
  fclose(input);
}
