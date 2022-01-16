#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_LINES 1000
#define LINE_LENGTH 13
#define SHOULD_PRINT 0

/* Solution Concept:
    -- Put each binary string in an array indexed according to line #
    -- Init 1000-item array with 0 for it's still alive and 1 for it's out

    while counter is >1:
        -- Go through first digit and establish majority element among the valid elements (make sure to handle for equal #)
        -- Go through the lines again; for each one, if it's valid then make it invalid and decrement counter if appropriate
*/

char* findRating(char num_strs[NUM_LINES][LINE_LENGTH], char mode) {
     /********************************
     * find o2 gen rating
     ********************************/

    int validity[NUM_LINES] = {0};

    int counter = NUM_LINES;
    int digit = 0;

    while (counter > 1) {
        // find majority element
        int zeros = 0;
        int ones = 0;
        int i = 0;

        while (i < NUM_LINES) {
            if (validity[i] == 0) {
                if (num_strs[i][digit] == '1') {
                    ones++;
                } else {
                    zeros++;
                }
            }
            i++;
        }

        int majority_element = zeros > ones ? '0' : '1';
        int minority_element = zeros > ones ? '1' : '0';
        int key_element = (mode == 'o') ? majority_element : minority_element;

        // update validity
        i = 0;
        while (i < NUM_LINES) {
            if (validity[i] == 0 && (num_strs[i][digit] != key_element)) {
                validity[i] = 1;
                counter--;
            }
            i++;
        }

        if (SHOULD_PRINT) {
            printf("\nCounter: %d\n\n", counter);
            int j = 0;
            while (j < NUM_LINES) {
                printf("Line %d (%s): %d\n", j+1, num_strs[j], validity[j]);
                j++;
            }
        }

        digit++;
    }

    // recover answer
    int i = 0;
    while (validity[i] != 0) {
        i++;
    }
    
    return num_strs[i];
}

int main(int argc, char *argv[]) {
    FILE* fp = fopen("day3-input", "r");
    
    if (fp == NULL) {
        perror("Error opening file");
        return(-1);
    }

    /********************************
     * read in input
     ********************************/
    char num_strs[NUM_LINES][LINE_LENGTH];
    
    int i = 0;
    while(fscanf(fp, "%s", num_strs[i]) != EOF) {
        i++;
    }

    char* o2_gen_binary = findRating(num_strs, 'o');
    char* co2_scrub_binary= findRating(num_strs, 'c');

    printf("o2: %s\nco2: %s\n", o2_gen_binary, co2_scrub_binary);

    /********************************
     * combine for final answer
     ********************************/

    int o2_gen_rating = 0;
    int co2_scrub_rating = 0;

    int binary_digit_mult = 1;
    int j = LINE_LENGTH - 2;
    while (j >= 0) {
        int o2_gen_digit = o2_gen_binary[j] - '0';
        int co2_scrub_digit = co2_scrub_binary[j] - '0';
        printf("%d %d\n\n", o2_gen_digit, co2_scrub_digit);

        o2_gen_rating += o2_gen_digit * binary_digit_mult;
        co2_scrub_rating += co2_scrub_digit * binary_digit_mult;

        binary_digit_mult *= 2;
        j--;
    }

    printf("%d %d %d\n", o2_gen_rating, co2_scrub_rating, o2_gen_rating * co2_scrub_rating);

    fclose(fp);
    return 0;
}
