#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "cipher.h"
#include "constants.h"

void cipher(char *instring, int key) {
    int len = strlen(instring);
    char outstring[MAX_STR] = "";

    for (int i = 0; i < len; i++) {
        char chr = instring[i];

        if ((toupper(chr) >= 'A') && (toupper(chr) <= 'Z')) {
            char mod;
            if (islower(chr)) {
                int x = (chr - A_LOWER) - key;
                if (x < 0) {
                    x += MAX_KEY;
                } else if (x > MAX_KEY - 1) {
                    x -= MAX_KEY;
                }
                mod = (x % MAX_KEY) + A_LOWER;
            } else {
                int x = (chr - A_UPPER) - key;
                if (x < 0) {
                    x += MAX_KEY;
                } else if (x > MAX_KEY - 1) {
                    x -= MAX_KEY;
                }
                mod = (x % MAX_KEY) + A_UPPER;
            }
            char str[2] = {mod, '\0'};
            strcat(outstring, str);

        } else {
            char str[2] = {chr, '\0'};
            strcat(outstring, str);
        }
    }

    printf("%s ", outstring);
}
