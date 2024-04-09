#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cipher.h"
#include "utils.h"
#include "constants.h"

void print_usage_info() {
    printf("Usage: cciphr [OPTION] ... TEXT...\n");
    printf("Try: 'cciphr -h' for more information\n");
}

void print_to_console(int start, int len, char **argv, int key) {
    printf("Out: ");
    for (int i = start; i < len; i++) {
        cipher(argv[i], key);
    }
    printf("\n");
}

void print_help_menu() {
    printf( "Usage: cciphr [OPTION] ... TEXT...\n"
            "Encrypts or decrypts a piece of text using Julius Ceasar's popular cipher algorithm\n"
            "Example: cciphr -k 5 attackatonce\n"
            "\n"
            "Command-line Options:\n"
            "  -h\tDisplays this menu\n"
            "  -a\tDisplays the encryption key(integer)\n"
            "  -k\tChange the key(default=3)\n"
            "  -d\tDecrypt the text\n"
            "\n"
            "Note: This is a toy project by @mellowboyXD\n"
    );
}

int change_key(char *value) {
    int len = strlen(value);
    char outstr[MAX_KEY] = "";

    for (int i = 0; i < len; i++) {
        char chr = value[i];
        if (chr >= '0' && chr <= '9') {
            char str[2] = {chr, '\0'};
            strcat(outstr, str);
        } else {
            printf("cciphr: invalid number after '-k'\n");
            print_usage_info();
            return -1;
        }
    }
    int key = atoi(outstr);
    
    if (key > MAX_KEY - 1 || key < 0) {
        printf("cciphr: invalid key '%i'. key must be < 25 or > 0\n", key);
        return -1;
    }

    return key;
}
