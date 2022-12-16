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

// Socre = wone/loose/draw score + move score
int calculateScore(char inp1, char inp2) {
  int score = getGameScore(inp2);

  switch (inp1) {
  case 'A': // Rock
    if (inp2 == 'X')
      score += getMoveScore('Z');
    if (inp2 == 'Y')
      score += getMoveScore('X');
    if (inp2 == 'Z')
      score += getMoveScore('Y');
    break;
  case 'B': // Paper
    score += getMoveScore(inp2);
    break;
  case 'C': // Scissors
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

  int part2;

  for (int i = 0; i < sizeof(games) / sizeof(games[0]); i++) {
    part2 += calculateScore(*games[i], games[i][1]);
  }

  printf("Part2: %d\n", part2);
}
