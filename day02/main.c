#include "../utils.h"

#include <stdio.h>

#define MAX_E 5000

enum MoveScore {
  MoveRock = 1,
  MovePaper,
  MoveScissor,
};

enum GameScore {
  GameDraw = 3,
  GameWon = 6,
  GameLoose = 0,
};

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

int calculateScoreP1(char inp1, char inp2) {
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

int calculateScoreP2(char inp1, char inp2) {
  int score = getGameScore(inp2);

  switch (inp1) {
  case 'A':
    if (inp2 == 'X')
      score += getMoveScore('Z');
    if (inp2 == 'Y')
      score += getMoveScore('X');
    if (inp2 == 'Z')
      score += getMoveScore('Y');
    break;
  case 'B':
    score += getMoveScore(inp2);
    break;
  case 'C':
    if (inp2 == 'X')
      score += getMoveScore('Y');
    if (inp2 == 'Y')
      score += getMoveScore('Z');
    if (inp2 == 'Z')
      score += getMoveScore('X');
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

  int part1, part2;

  for (int i = 0; i < sizeof(games) / sizeof(games[0]); i++) {
    part1 += calculateScoreP1(*games[i], games[i][1]);
    part2 += calculateScoreP2(*games[i], games[i][1]);
  }

  printf("Part 1: %d\nPart 2: %d\n", part1, part2);
}
