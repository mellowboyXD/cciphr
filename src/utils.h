#ifndef UTILS_H_
#define UTILS_H_

enum Errors {
    SUCCESS,
    INVALID_OPT,
    INVALID_NUM
};

void usageDisplay();

void prettyPrint(int start, int len, char **argv, int key);

int changeKey(char *value);

#endif
