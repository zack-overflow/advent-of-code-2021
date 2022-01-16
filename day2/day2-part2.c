#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE* fp = fopen("day2-input", "r");
    
    if (fp == NULL) {
        perror("Error opening file");
        return(-1);
    }

    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    char direction[8];
    int delta = 0;
    
    while(fscanf(fp, "%s %d\n", direction, &delta) != EOF) {
        if (!(strcmp("forward", direction))) {
            horizontal += delta;
            depth += aim * delta;
        } else if (!(strcmp("down", direction))) {
            aim += delta;
        } else {
            aim -= delta;
        }
    }

    printf("%d\n", depth);
    printf("%d\n", horizontal);
    printf("%d\n", depth * horizontal);

    fclose(fp);
    return 0;
}
