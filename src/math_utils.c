#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "math_utils.h"

float add(int argc, char const *argv[]) {
	if (argc < 4) {
		printHelp();
		exit(-1);
	}
	float result = 0;
	for (int i = 2; i < argc; i++) {
		float num = 0;
		if (!parseToNum(argv[i], &num)) {
			printHelp();
			exit(-1);
		}
		result += num;
	}
	return result;
}

float substract(int argc, char const *argv[]) {
	if (argc < 4) {
		printHelp();
		exit(-1);
	}
	float result;
	if (!parseToNum(argv[2], &result)) {
		printHelp();
		exit(-1);
	}
	for (int i = 3; i < argc; i++) {
		float num;
		if (!parseToNum(argv[i], &num)) {
			printHelp();
			exit(-1);
		}
		result -= num;
	}
	return result;

}

float multiply(int argc, char const *argv[]) {
	float result = 0;
	for (int i = 2; i < argc; i++) {
		float num = 0;
		if (!parseToNum(argv[i], &num)) {
			printHelp();
			exit(-1);
		}
		result *= num;
	}
	return result;
}

// TODO: multi number division?
float divide(int argc, float *a, float *b) {
	if (argc < 4) {
		printHelp();
		exit(-1);
	}
	if (*b == 0) {
		printf("For some reason, you can't divide by zero!\n");
		return 1;
	}
	return *a / *b;
}

void printHelp(void) {
	printf("Usage: calc <operation> <num1> <num2>\n"
			"'calc help' for more information"
		);	
}

bool parseToNum(const char *str, float *result) {
	char *end;
	*result = strtod(str, &end);
	return *end == '\0';
}
