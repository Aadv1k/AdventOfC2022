#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
int utl_max(int nums[]) {
  int result = 0;
  for (int i = 0; nums[i] != 0; i++) {
    if (nums[i] > result && nums[i] != -1) {
      result = nums[i];
    };
  }
  return result;
}

int utl_findElemInArr(int elem, int arr[]) {
  for (int i = 0; arr[i] != 0; i++) {
    if (arr[i] == elem) {
      return i;
    }
  }

  return -1;
}

long utl_fileLength(char *filename) {
  FILE *infile = fopen(filename, "r");

  long file_len = 0;

  for (char c = getc(infile); c != EOF; c = getc(infile)) {
    if (c == '\n')
      file_len++;
  }

  return file_len;
}

#endif
