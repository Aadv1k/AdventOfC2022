#include "../utils.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_L 100
#define MAX_B 10000

int main(void) {
  FILE *input = fopen("./input.txt", "r");
  char line[MAX_L], prev[MAX_L];
  int sums[MAX_B], sum, line_num;

  while (fgets(line, MAX_L, input)) {
    if (line[0] == '\n') {
      sums[line_num] = sum;
      sum = 0;
      line_num++;
    }
    sum += atoi(line);
  }

  printf("The elf is carrying %d\n calories!", utl_max(sums));
}
