#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void load_dict(const char *filename, char *swedish_dict[], char *gothic_dict[], size_t dict_size) {
    FILE *file = fopen(filename, "r"); 

    if (!file) {
        perror("Error opening file");
        return;
    }

    char buffer[256];
    size_t gothic_index = 0, swedish_index = 0; 

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        char *token = strtok(buffer, ":");
        int token_num = 0; 

        while (token != NULL) {
            token_num++;
            if (token_num == 1 && gothic_index < dict_size) {
                gothic_dict[gothic_index++] = strdup(token); 
            } else if (token_num == 2 && swedish_index < dict_size) {
                swedish_dict[swedish_index++] = strdup(token); 
            token = strtok(NULL, ":"); 
        }
    }

    fclose(file);
}


