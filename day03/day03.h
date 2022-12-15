#ifndef DAY3_H
#define DAY3_H

#include <string.h>
#define MAX_L 100
#define ASCII_LOWER_BEGIN 91

char findCommoninDoublets(char *str1, char *str2) {
  for (int i = 0; i < strlen(str1); i++) {
    char *match = strchr(str2, str1[i]);
    if (match) {
      return *match;
    };
  }
  return 0;
}

char findCommonCharInTriplets(char *str1, char *str2, char *str3) {
  for (int i = 0; i < strlen(str1); i++) {
    char *match1 = strchr(str2, str1[i]);
    char *match2 = strchr(str3, str1[i]);

    if (match1 && match2) {
      return *match1;
    };
  }
  return 0;
}

int deriveScoreFromChar(char t) {
  if (t < ASCII_LOWER_BEGIN) {
    return t - 38;
  }

  return t - 96;
}


#endif
