#include "../utils.h"
#include <stdio.h>

#define _OPEN_SYS_ITOA_EXT
#include <stdlib.h>
#include <string.h>

#define MAX_L 500

typedef struct Directory {
  char dirName[MAX_L];
  int dirSize;
} Directory;


int get_dir_size(int fileLen, char lines[fileLen][MAX_L], const char *dirname) {
  char command[MAX_L] = "$ cd ";
  size_t sizeKbs = 0;
  strcat(command, dirname);

  for (int i = 0; i < fileLen; i++) {
    if (strcmp(lines[i], command) == 0) {
      for (int j = 2; lines[i + j][0] != '$' && j+i != fileLen; j++) {

        char curCommand[MAX_L];
        strcpy(curCommand, lines[i + j]);
        *(strchr(curCommand, ' ')) = '\0';
        if (strcmp(curCommand, "dir") == 0) {
          sizeKbs += get_dir_size(fileLen, lines, strchr(lines[i + j], ' ') + 1);
        } else {
          sizeKbs += atoi(curCommand);
        }
      }
    }
  }
  return sizeKbs;
}

int count_all_dirs(int fileLen, char lines[fileLen][MAX_L]) {
  int dirCount = 0;
  for (int i = 0; i < fileLen; i++) {
    if (strstr(lines[i], "dir") != NULL) {
      dirCount ++;
    }
  }
  return dirCount;
}

void get_all_dir_sizes(int fileLen, char lines[fileLen][MAX_L]) {
  int dirSizes[count_all_dirs(fileLen, lines)];

  int count = 0;
  for (int i = 0; i < fileLen; i++) {
    if (strstr(lines[i], "dir") != NULL) {
      dirSizes[count] = get_dir_size(fileLen, lines, strchr(lines[i], ' ')+1);
      count++;
    }
  }
}


int main(void) {
  FILE *input = fopen("./sample.txt", "r");
  const int fileLen = utl_fileLength("./sample.txt");
  char lines[fileLen][MAX_L];

  int lineNum = 0;
  while (!feof(input)) {
    fgets(lines[lineNum], MAX_L, input);
    lines[lineNum][strlen(lines[lineNum]) - 1] = '\0';
    lineNum++;
  }

  // get_dir_items(fileLen, lines, "/");

  get_all_dir_sizes(fileLen, lines);

  return 0;
}
