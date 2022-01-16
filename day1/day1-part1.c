#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define RSIZ 2000

int main(int argc, char *argv[]) {
    FILE* fp = fopen("day1-input", "r");
    
    if (fp == NULL) {
        perror("Error opening file");
        return(-1);
    }

    int nums[RSIZ];
    nums[0] = 0;
    int n;
    int window1;
    int window2;
    int num_increases = 0;

    int i = 0;
    while(fscanf(fp, "%x\n", &n) != EOF) {
        nums[i] = n;

        // init window2 before reading fourth item
        if (i == 3) {
            window2 = window1;
        }

        window1 = window1 + n;

        if (i >= 3) {
            window1 = window1 - nums[i-3];
        }
        if (i >=4) {
            window2 = window2 + nums[i-1];
            window2 = window2 - nums[i-4];
        }

        if (i >= 3) {
            if (window1 > window2) {
                num_increases = num_increases + 1;
            }
        }

        i++;
    }

    printf("%d", num_increases);

    fclose(fp);
    return 0;
}
