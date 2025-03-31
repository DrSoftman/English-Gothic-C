#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void load_dict(const char* filename) {

  FILE* file = fopen(filename, "r")

  if (!file) {
    perror("Error opening file: Does it exist? %s", filename);
    return;
  }

  char buffer[256];
  

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    char *token = strtok(buffer, ":")
  }

  fclose(file);

  
}



