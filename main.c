#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  
  
int main(int argc, char *argv[]) {  
    char *param = NULL, *filename = NULL;  
    FILE *file = NULL;  
    int ch, word_count = 0, char_count = 0;  
    int in_word = 0;   
  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    param = argv[1];  
    filename = argv[2];  
  
    if (strcmp(param, "-c") != 0 && strcmp(param, "-w") != 0) {  
        fprintf(stderr, "Invalid parameter: %s\n", param);  
        return 1;  
    }  
  
    file = fopen(filename, "r");  
    if (file == NULL) {  
        perror(filename);  
        return 1;  
    }  
  
    while ((ch = fgetc(file)) != EOF) {  
        char_count++;  
  
        if (isspace(ch) || ch == ',') {  
            in_word = 0;  
        } else if (!in_word) {  
            word_count++;  
            in_word = 1;  
        }  
    }  
  
    if (param[0] == '-' && param[1] == 'c') {  
        printf("Character count:%d\n", char_count);  
    } else if (param[0] == '-' && param[1] == 'w') {  
        printf("Word count:%d\n", word_count);  
    }  
  
    fclose(file);  
    return 0;  
}
