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

  int maxThreeSum = 0;

  for (int i = 0; i < 3; i++) {
    maxThreeSum += utl_max(sums);
    sums[utl_findElemInArr(utl_max(sums), sums)] = -1;
  }

  printf("The (three max) elves are carrying %d\n calories!", maxThreeSum);
}
