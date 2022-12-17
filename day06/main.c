#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_L 5000

typedef struct Sequence {
  char seqStr[MAX_L];
  int seqIdx;
  int seqLength;
} Sequence;

bool has_duplicates(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    for (int j = i + 1; str[j] != '\0'; j++) {
      if (str[i] == str[j]) {
        return true;
      }
    }
  }
  return false;
}

void solve(FILE *input, Sequence *seq) {
  rewind(input);
  char line[MAX_L] = "", stack[MAX_L] = "";
  fgets(line, MAX_L, input);

  for (int i = 0; line[i] != '\0'; i++) {
    stack[0] = '\0';
    for (int j = 0; j < seq->seqLength; j++) {
      strncat(stack, &line[i + j], 1);
    }

    if (!has_duplicates(stack)) {
      strcpy(seq->seqStr, stack);
      seq->seqIdx = i + seq->seqLength;
      break;
    }
  }
}

int main(void) {
  FILE *input = fopen("input.txt", "r");

  Sequence seq = {};

  seq.seqLength = 4;
  solve(input, &seq);
  printf("Part1: %s %d\n", seq.seqStr, seq.seqIdx);

  seq.seqLength = 14;
  solve(input, &seq);
  printf("Part2: %s %d\n", seq.seqStr, seq.seqIdx);

  fclose(input);
  return 0;
}
