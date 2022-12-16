#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 100
#define MAX_W 50

void print_crates(char crates[][MAX_L], int crateWidth) {
  puts("====================");
  for (int i = 0; i < crateWidth; i++) {
    printf("%d: ", i+1);
    if (crates[i][0] == 0) {
      printf("[.]\n");
      continue;
    }
    for (int j = 0; crates[i][j] != 0; j++) {
      printf("[%c]", crates[i][j]);
    }
   puts("");
  }
  puts("====================");
}

int main(void) {
  FILE *input = fopen("./input.txt", "r");
  char lines[MAX_L][MAX_L];

  int crateWidth, lineNum;

  while (!feof(input)) {
    fgets(lines[lineNum], MAX_L, input);
    if (lines[lineNum][0] == '\n') {
      crateWidth = atoi(strchr(lines[lineNum - 1], '\n') - 2);
      break;
    }
    lineNum++;
  }

  char crates[MAX_W][MAX_L];
  crates[0][0] = '\0';

  for (int i = 0; i < crateWidth; i++) {
    for (int j = 0; j < lineNum - 1; j++) {
      char curLine[MAX_L];
      strcpy(curLine, lines[j] + (4 * i));
      curLine[2] = '\0';
      if (curLine[0] != ' ') {
        strcat(crates[i], curLine + 1);
      }
    }
  }

  int fromAddr, toAddr, amount;
  char instructionLine[MAX_L];

  while (fgets(instructionLine, MAX_L, input)) {

    sscanf(instructionLine, "move %d from %d to %d\n", &amount, &fromAddr,
           &toAddr);

    // Normalizing
    toAddr--;
    fromAddr--;

    for (int i = 0; i < amount; i++) {
      char temp[MAX_L] = "";
      // prepend the character from the fromAddr to the toAddr
      strcpy(temp, crates[toAddr]);
      strncpy(crates[toAddr], &crates[fromAddr][i], 1);
      if (strlen(crates[toAddr]) > 1) {
        crates[toAddr][1] = '\0';
      }
      strcat(crates[toAddr], temp);

      // Instead of removing the element, we will instead replace it; this is
      // done to preserve the index of the crates[fromAddr]
      crates[fromAddr][i] = '.';
    }

    // Here we need to filter out the '.' other wise they will mess with further results
    for (int i = 0; i < crateWidth; i++) {
      char temp[MAX_L] = "";
      for (int j = 0; j < strlen(crates[i]); j++) {
        if (crates[i][j] != '.')
          strncat(temp, &crates[i][j], 1);
      }
      strcpy(crates[i], temp);
    }
  }
  print_crates(crates, crateWidth);

  char result[MAX_L] = "";
  for (int i = 0; i < crateWidth; i++) {
    strncat(result, &crates[i][0], 1);
  }

  printf("Part1: %s\n", result);
  return 0;
}
