#ifndef UTILS_H_
#define UTILS_H_

enum errors {
    SUCCESS,
    INVALID_OPT,
    INVALID_NUM
};

void print_usage_info();

void print_to_console(int start, int len, char **argv, int key);

int change_key(char *value);

void print_help_menu();

#endif
