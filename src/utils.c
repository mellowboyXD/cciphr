#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cipher.h"
#include "utils.h"
#include "constants.h"

void usageDisplay() {
    printf("Usage: cciphr [OPTION] ... TEXT [STRINGS]...\n");
    printf("Try: 'cciphr -h' for more information\n");
}

void prettyPrint(int start, int len, char **argv, int key) {
    printf("Out: ");
    for (int i = start; i < len; i++) {
        cipher(argv[i], key);
    }
    printf("\n");
}

int changeKey(char *value) {
    int len = strlen(value);
    char outstr[MAX_KEY] = "";

    for (int i = 0; i < len; i++) {
        char chr = value[i];
        if (chr >= '0' && chr <= '9') {
            char str[2] = {chr, '\0'};
            strcat(outstr, str);
        } else {
            printf("cciphr: invalid number after '-k'\n");
            usageDisplay();
            return -1;
        }
    }
    int key = atoi(outstr);
    
    if (key > 25 || key < 0) {
        printf("cciphr: invalid key '%i'. key must be < 25 or > 0\n", key);
        return -1;
    }

    return key;
}
