#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printHelp();
bool parseToNum(const char *str, long *result);

int main(int argc, char const *argv[])
{
	long a, b;
	if (!parseToNum(argv[2], &a) || !parseToNum(argv[3], &b)) {
		printHelp();
		return 1;
	}

	if (argc < 2) {
		printHelp();
		return 1;
	}

	if (strcmp(argv[1], "add") == 0) {
		if (argc < 4) {
			printHelp();
			return 1;
		}
		int result = a + b;
		printf("[ %d ]\n", result);
	}
	else if (strcmp(argv[1], "sub") == 0) {
		if (argc < 4) {
			printHelp();
			return 1;
		}
		int result = a - b;
		printf("[ %d ]\n", result);
	}
	else if (strcmp(argv[1], "mul") == 0) {
		if (argc < 4) {
			printHelp();
			return 1;
		}
		int result = a * b;
		printf("[ %d ]\n", result);
	}
	else if (strcmp(argv[1], "div") == 0) {
		if (argc < 4) {
			printHelp();
			return 1;
		}
		if (b == 0) {
			printf("For some reason, you can't divide by zero!\n");
			return 1;
		}
		int result = a / b;
		printf("[ %d ]\n", result);
	}
	else if (strcmp(argv[1], "help") == 0) {
		printf(
				"* Help *\n"
				"calc <operation> <num1> <num2>\n"
				"calc add <num1> <num2> : Addition\n"
				"calc sub <num1> <num2> : Substraction\n"
				"calc mul <num1> <num2> : Multiplication\n"
				"calc div <num1> <num2> : Division\n"
			);
	}
	else {
		printf("unknown command: %s", argv[1]);
	}

	return 0;
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