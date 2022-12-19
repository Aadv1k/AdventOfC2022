#include "../utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_L 500

void get_contents_by_dir(int fileLen, char lines[fileLen][MAX_L],
                         const char *dirname) {
  char command[MAX_L] = "$ cd ";
  strcat(command, dirname);
  for (int i = 0; i < fileLen; i++) {
    if (strcmp(lines[i], command) != 0) {
      continue;
    }

    for (int j = 2; lines[i + j][0] != '$' && i + j != fileLen; i++) {
      puts(lines[i + j]);
    }
  }
}

typedef struct DirItem {
  char itemName[MAX_L];
  int itemDepth;
} DirItem;


int find_dir_idx(int fileLen, char lines[fileLen][MAX_L], char * dirname) {
  char command[MAX_L] = "$ cd ";
  strcat(command, dirname);

  for (int i = 0; i < fileLen; i++) {
    if (strcmp(command, lines[i]) == 0) {
      return i;
    }
  }
  return -1;
}

int get_size_by_dir(int fileLen, char lines[fileLen][MAX_L], DirItem *Dir) {
  int sizeKb = 0, depth = 0;
  DirItem Subdir;

  char command[MAX_L] = "$ cd ";
  strcat(command, Dir->itemName);

  for (int i = 0; i < fileLen; i++) {

    if (strcmp(lines[i], command) != 0) continue;

    for (int j = 2; lines[i + j][0] != '$' && i + j != fileLen; j++) {
        char * contentType = strdup(lines[i + j]);
        *(strchr(contentType, ' ')) = '\0';

        Subdir.itemDepth = find_dir_idx(fileLen-(i+j), &lines[i+j], strchr(lines[i+j], ' ')+1);
        strcpy(Subdir.itemName, strchr(lines[i+j], ' ')+1);

        printf("%d -> %s\n", Subdir.itemDepth, Subdir.itemName);
        sizeKb += !strcmp(contentType, "dir") ? get_size_by_dir(fileLen, lines, &Subdir) : atoi(contentType);
        free(contentType);
    } 

  }

  return sizeKb;
};

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

  DirItem Dir = {"e", 12};
  printf("%d\n", get_size_by_dir(fileLen, lines, &Dir));

  return 0;
}
