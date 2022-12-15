#include "../utils.h"

#include <stdio.h>

#define MAX_E 5000

int getXScore(char t) {
  switch (t) {
    case 'X':
      return 1;
    case 'Y':
      return 2;
    case 'Z':
      return 3;
  }
  return -1;
}

int calculateScoreP1(char inp1, char inp2) {
  int score;
  score = getXScore(inp2);

  switch (inp1) {
    case 'A':
      if (inp2 == 'X') score += 3;
      if (inp2 == 'Y') score += 6;
      if (inp2 == 'Z') score += 0;
      break;
    case 'B':
      if (inp2 == 'X') score += 0;
      if (inp2 == 'Y') score += 3;
      if (inp2 == 'Z') score += 6;
      break;
    case 'C':
      if (inp2 == 'X') score += 6;
      if (inp2 == 'Y') score += 0;
      if (inp2 == 'Z') score += 3;
      break;
  } 

  return score;
}


int calculateScoreP2(char inp1, char inp2) {
  int score = 0;

  switch (inp1) {
    case 'A':
      if (inp2 == 'X') score += getXScore('Z') + 0;
      if (inp2 == 'Y') score += getXScore('X') + 3;
      if (inp2 == 'Z') score += getXScore('Y') + 6;
      break;
    case 'B':
      if (inp2 == 'X') score += getXScore('X') + 0;
      if (inp2 == 'Y') score += getXScore('Y') + 3;
      if (inp2 == 'Z') score += getXScore('Z') + 6;
      break;
    case 'C':
      if (inp2 == 'X') score += getXScore('Y') + 0;
      if (inp2 == 'Y') score += getXScore('Z') + 3;
      if (inp2 == 'Z') score += getXScore('X') + 6;
      break;
  } 

  return score;
}

int main() {
  FILE * input = fopen("./input.txt", "r");
  char games[utl_fileLength("./input.txt")][2];

  for (int i = 0; !feof(input); i++) {
    fscanf(input, "%s %s", games[i], games[i]+1);
  }

  int part1, part2; 

  for (int i = 0; i < sizeof(games)/sizeof(games[0]); i++) {
    part1 += calculateScoreP1(*games[i], games[i][1]);
    part2 += calculateScoreP2(*games[i], games[i][1]);
  }

  printf("Part 1: %d\nPart 2: %d\n", part1, part2);

}
