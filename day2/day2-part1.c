#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RSIZ 1000

int main(int argc, char *argv[]) {
    FILE* fp = fopen("day2-input", "r");
    
    if (fp == NULL) {
        perror("Error opening file");
        return(-1);
    }

    int horizontal = 0;
    int depth = 0;

    char direction[8];
    int displacement = 0;
    
    while(fscanf(fp, "%s %d\n", direction, &displacement) != EOF) {
        if (!(strcmp("forward", direction))) {
            horizontal += displacement;
        } else if (!(strcmp("down", direction))) {
            depth += displacement;
        } else {
            depth -= displacement;
        }
    }

    printf("%d\n", depth);
    printf("%d\n", horizontal);
    printf("%d\n", depth * horizontal);

    fclose(fp);
    return 0;
}
