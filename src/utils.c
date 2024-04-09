#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cipher.h"
#include "utils.h"
#include "constants.h"

/*
 * function: print_usage_info
 * prints info on how to use the tool to the console
*/
void print_usage_info() {
    printf("Usage: cciphr [OPTION] ... TEXT...\n");
    printf("Try: 'cciphr -h' for more information\n");
}

/*
 * function: print_to_console
 * prints the output after encryption to the console 
 *
 * param: start(int) the start index, 
 *        len(int) the max length of the string to encrypt, 
 *        argv(str) the string, key(int) the key
 * return: void
*/
void print_to_console(int start, int len, char **argv, int key) {
    printf("Out: ");
    for (int i = start; i < len; i++) {
        cipher(argv[i], key);
    }
    printf("\n");
}

/*
 * function: print_help_menu
 * prints the help menu to the console 
*/
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
            "For more information on Ceasar's Cipher, visit <https://en.wikipedia.org/wiki/Caesar_cipher>\n"
            "Note: This is a toy project by @mellowboyXD\n"
    );
}

/* function: change_key
 *
 * converts the string input into a valid encryption key
 *
 * param: value(str)  - The string to be encrypted
 * return: -1(int) if key is not an integer or key is not in range
 * return: key(int) the value converted to integer
*/
int convert_key_to_int(char *value) {
    int len = strlen(value);
    char outstr[MAX_KEY] = "";

    if (len < 1) return -1;

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
