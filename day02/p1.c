#include "../utils.h"

#include <stdio.h>

enum Scores {
  ScoreRock = 1,
  ScorePaper,
  ScoreScissor,
  ScoreDraw = 3,
  ScoreWon = 6,
  ScoreLoose = 0,
};

int getMoveScore(char t) {
  enum Scores;
  switch (t) {
  case 'X':
    return ScoreRock;
  case 'Y':
    return ScorePaper;
  case 'Z':
    return ScoreScissor;
  }
  return -1;
}

int getGameScore(char t) {
  enum Scores;
  switch (t) {
  case 'X':
    return ScoreLoose;
  case 'Y':
    return ScoreDraw;
  case 'Z':
    return ScoreWon;
  }
  return -1;
}

// Gets the score -> moveScore + won/loose/draw score
int calculateScore(char inp1, char inp2) {
  enum Scores;
  int score = getMoveScore(inp2);
  switch (inp1) {
  case 'A': // Rock
    if (inp2 == 'X')
      score += ScoreDraw;
    if (inp2 == 'Y')
      score += ScoreWon;
    if (inp2 == 'Z')
      score += ScoreLoose;
    break;
  case 'B': // Paper
    score += getGameScore(inp2);
    break;
  case 'C': // Scissor
    if (inp2 == 'X')
      score += ScoreWon;
    if (inp2 == 'Y')
      score += ScoreLoose;
    if (inp2 == 'Z')
      score += ScoreDraw;
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

  printf("Part1: %d\n", part1);
}
