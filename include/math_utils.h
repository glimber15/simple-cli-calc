#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <stdbool.h>

void printHelp(void);
bool parseToNum(const char  *str, float *result);
float add(int argc, char const *argv[]);
float substract(int argc, char const *argv[]);
float multiply(int argc, char const *argv[]);
float divide(int argc, float *a, float *b);

#endif