#include <stdio.h>

int main(void) {
  FILE *input = fopen("./input.txt", "r");
  int overlap = 0, overlap_2 = 0;


  while (!feof(input)) {
    int x1, x2, y1, y2;
    fscanf(input, "%d-%d,%d-%d", &x1, &x2, &y1, &y2);

    if (
        (x1 <= y1 && x2 >= y2) ||
        (y1 <= x1 && y2 >= x2) 
      ) overlap++;

    if (!(x2 < y1 || y2 < x1)) {
      overlap_2++;
    }
  }

  printf("The overlap is %d %d\n", overlap, overlap_2);
}
