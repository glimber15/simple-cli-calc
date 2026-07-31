#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

float add(int argv, long *a, long *b) {
	if (argv < 4) {
		printHelp();
		exit(-1);
	}
	return *a + *b;
}

float substract(int argv, long *a, long *b) {
	if (argv < 4) {
		printHelp();
		exit(-1);
	}
	return *a - *b;
}

float multiply(int argv, long *a, long *b) {
	if (argv < 4) {
		printHelp();
		exit(-1);
	}
	return *a * *b;
}

float division(int argv, long *a, long *b) {
	if (argv < 4) {
		printHelp();
		exit(-1);
	}
	if (*b == 0) {
		printf("For some reason, you can't divide by zero!\n");
		return 1;
	}
	return (float)*a / *b;
}

void printHelp() {
	printf("Usage: calc <operation> <num1> <num2>\n"
			"'calc help' for more information"
		);	
}

bool parseToNum(const char *str, long *result) {
	char *end;
	*result = strtol(str, &end, 10);
	return *end == '\0';
}