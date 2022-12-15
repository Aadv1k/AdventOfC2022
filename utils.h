#ifndef UTILS_H
#define UTILS_H

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

#endif
