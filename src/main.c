#include <stdio.h>

#include "utils.h"

typedef enum { false, true }bool;

int main(int argc, char **argv) {
    if (argc < 2) {
        usageDisplay();
    } else {
        int key = 3;
        int start = 1;
        bool showKey = false;
        bool decrypt = false;

        for (int i = 1; i < argc; i++) {
            char *arg = argv[i];
            if (arg[0] == '-') {
                // printf("flag\n");
                int flag = arg[1];
                switch (flag) {
                    case 'h':
                        // TODO: HELP MENU
                        usageDisplay();
                        return SUCCESS;
                        break;

                    case 'd':
                        decrypt = true;
                        start++;
                        break;

                    case 'a':
                        showKey = true;
                        start++;
                        break;

                    case 'k':
                        key = changeKey(argv[i + 1]);
                        if (key == -1) return INVALID_NUM;
                        start += 2;
                        break;

                    default:
                        printf("cciphr: invalid option '-%c'\n", flag);
                        usageDisplay();
                        return INVALID_OPT;
                }
            } else {
                break;
            }        
        }
        if (decrypt == true) key *= -1;
        if (showKey == true) printf("key: %i [left shift]\n", key);
        if (start >= argc) {
            printf("Error! Expected arguments\n");
            return INVALID_OPT;
        }
        prettyPrint(start, argc, argv, key);
    }

    return SUCCESS;
}
