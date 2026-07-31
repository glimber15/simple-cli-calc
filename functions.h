#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void printHelp();
bool parseToNum(const char *str, long *result);
float add(int argv, long *a, long *b);
float substract(int argv, long *a, long *b);
float multiply(int argv, long *a, long *b);
float divide(int argv, long *a, long *b);

#endif