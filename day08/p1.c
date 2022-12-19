#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../utils.h"

#define MAX_L 1000
#define MAX_W 1000

bool YLineOfSight_clear(char lines[MAX_L][MAX_W], int length, int atY, int atX) {
  bool up = true, down = true;
  int target = lines[atY][atX] - '0';

  for (int i = 0; i != atY; i++) {
    int cur = lines[i][atX] - '0';
    if (cur < target) continue;
    up = false;
    break;
  }

  for (int i = atY; i < length; i++) {
    int cur = lines[i][atX] - '0';
    if (cur < target) continue;
    down = false;
    break;
  }

  return (up || down);
}

bool XLineOfSight_clear(char lines[MAX_L][MAX_W], int length, int atY, int atX) {
  bool right = true, left = true;
  int target = lines[atY][atX] - '0';

  for (int i = 0; i < atX; i++) {
    int cur = lines[atY][i] - '0';
    if (cur < target) continue;
    left = false;
    break;
  }

  for (int i = atX+1; lines[atY][i] != '\0'; i++) {
    int cur = lines[atY][i] - '0';
    if (cur < target) continue;
    right = false;
    break;
  }

  return (right || left);
}

int main(void) {
  FILE *input = fopen("input.txt", "r");
  char lines[MAX_L][MAX_W];

  int lineNum = 0;
  while (!feof(input)) {
    fgets(lines[lineNum], MAX_W, input);
    lines[lineNum][strlen(lines[lineNum]) - 1] = '\0';
    lineNum++;
  }

  int visibleTrees = (lineNum-1)*2 + strlen(lines[0])*2;

  for (int i = 1; i < lineNum-1; i++) { 
    for (int j = 1; lines[i][j+1] != '\0'; j++) {
      int cur = lines[i][j] - '0';

      if (
      XLineOfSight_clear(lines, lineNum, i, j) ||
      YLineOfSight_clear(lines, lineNum, i, j)) visibleTrees++;
    }
  }

  printf("Part1: %d\n", visibleTrees);

  return 0;
}
