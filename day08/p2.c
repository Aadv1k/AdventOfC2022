
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../utils.h"

#define MAX_L 1000
#define MAX_W 1000

int YLineOfSight_score(char lines[MAX_L][MAX_W], int length, int atY, int atX) {
  int up = 1, down = 1;
  int target = lines[atY][atX] - '0';

  for (int i = 0; i != atY; i++) {
    int cur = lines[i][atX] - '0';
    if (cur < target) {
      up++;
      continue;
    }
    break;
  }

  for (int i = atY; i < length; i++) {
    int cur = lines[i][atX] - '0';
    if (cur < target) {
      down++;
      continue;
    }
    break;
  }

  return up * down;
}

int XLineOfSight_score(char lines[MAX_L][MAX_W], int length, int atY, int atX) {
  int right = 1, left = 1;
  int target = lines[atY][atX] - '0';

  for (int i = 0; i < atX; i++) {
    int cur = lines[atY][i] - '0';
    if (cur < target) {
      left++;
      continue;
    }
    break;
  }

  for (int i = atX+1; lines[atY][i] != '\0'; i++) {
    int cur = lines[atY][i] - '0';
    if (cur < target) {
      right++;
      continue;
    }
    break;
  }

  return right * left;
}

int main(void) {
  FILE *input = fopen("sample.txt", "r");
  char lines[MAX_L][MAX_W];

  int lineNum = 0;
  while (!feof(input)) {
    fgets(lines[lineNum], MAX_W, input);
    lines[lineNum][strlen(lines[lineNum]) - 1] = '\0';
    lineNum++;
  }

  int scores[lineNum];

  for (int i = 1; i < lineNum-1; i++) { 
    for (int j = 1; lines[i][j+1] != '\0'; j++) {
      int score = XLineOfSight_score(lines, lineNum, i, j) * YLineOfSight_score(lines, lineNum, i, j);
      scores[i] = score;
    }
  }

  printf("Part2: %d\n", utl_max(scores, lineNum));

  return 0;
}
