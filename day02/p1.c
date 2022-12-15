#include "../utils.h"
#include "day02.h"

#include <stdio.h>

#define MAX_E 5000


// Return the score for each of the move
int getMoveScore(char t) {
  enum MoveScore;

  switch (t) {
  case 'X':
    return MoveRock;
  case 'Y':
    return MovePaper;
  case 'Z':
    return MoveScissor;
  }
  return -1;
}

int getGameScore(char t) {
  enum GameScore;
  switch (t) {
  case 'X':
    return GameLoose;
  case 'Y':
    return GameDraw;
  case 'Z':
    return GameWon;
  }
  return -1;
}

int calculateScore(char inp1, char inp2) {
  enum GameScore;

  int score = getMoveScore(inp2);

  switch (inp1) {
  case 'A':
    if (inp2 == 'X')
      score += GameDraw;
    if (inp2 == 'Y')
      score += GameWon;
    if (inp2 == 'Z')
      score += GameLoose;
    break;
  case 'B':
    score += getGameScore(inp2);
    break;
  case 'C':
    if (inp2 == 'X')
      score += GameWon;
    if (inp2 == 'Y')
      score += GameLoose;
    if (inp2 == 'Z')
      score += GameDraw;
    break;
  }

  return score;
}


int main() {
  FILE *input = fopen("./input.txt", "r");
  char games[utl_fileLength("./input.txt")][2];

  for (int i = 0; !feof(input); i++) {
    fscanf(input, "%s %s", games[i], games[i] + 1);
  }

  int part1;

  for (int i = 0; i < sizeof(games) / sizeof(games[0]); i++) {
    part1 += calculateScore(*games[i], games[i][1]);
  }

  printf("Total score according to the guide is %d\n", part1);
}
