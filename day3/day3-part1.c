#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    FILE* fp = fopen("day3-input", "r");
    
    if (fp == NULL) {
        perror("Error opening file");
        return(-1);
    }

    char num_str[13];
    int tracker[12] = {0};
    
    while(fscanf(fp, "%s", num_str) != EOF) {
        int i = 0;
        while (i < 12) {
            char c = num_str[i];
            int num = c - '0';
            if (num > 0) {
                tracker[i] += 1;
            } else {
                tracker[i] -= 1;
            }
            i++;
        }
    }

    int gamma_rate = 0;
    int epsilon_rate = 0;
    int gamma_val;
    int epsilon_val;

    int binary_digit_mult = 1;
    int j = 11;
    while (j >= 0) {
        if (tracker[j] > 0) {
            gamma_val = 1;
            epsilon_val = 0;
        } else {
            gamma_val = 0;
            epsilon_val = 1;
        }
        
        gamma_rate += gamma_val * binary_digit_mult;
        epsilon_rate += epsilon_val * binary_digit_mult;

        printf("%d\n", tracker[j]);

        binary_digit_mult *= 2;
        j--;
    }

    printf("%d %d\n", gamma_rate, epsilon_rate);
    printf("%d\n", epsilon_rate * gamma_rate);

    fclose(fp);
    return 0;
}
