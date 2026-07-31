#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <stdbool.h>

void printHelp(void);
bool parseToNum(const char *str, long *result);
float add(int argv, long *a, long *b);
float substract(int argv, long *a, long *b);
float multiply(int argv, long *a, long *b);
float divide(int argv, long *a, long *b);

#endif