#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_dicdata(char* filename, char eng[][256], char jpn[][256]) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) return -1;

    int count = 0;
    char s[256];

    while (fscanf(file, " %s", s) != EOF) {
        strcpy(eng[count], s);
        fscanf(file, " %s", s);
        strcpy(jpn[count], s);
        count++;
    }

    fclose(file);
    
    return count;
}

void print_array(char array[][256], int count) {
    int i;
    puts("------------------------------");
    for (i = 0; i < count; ++i) {
        printf("[%d] = %s\n", i, array[i]);
    }
}

