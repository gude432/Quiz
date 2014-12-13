#include <stdio.h>
#include <string.h>
#include "data.h"

/* returns zero on success */
int readString(char *str, int maxsize)
{
	int len = 0;
	if(fgets(str, maxsize, stdin) == NULL) {
		return -1;
	}
	len = strlen(str);
	if(str[len - 1] == '\n') str[len - 1] = '\0';

	return 0;
}

/* returns zero on success */
int readInt(int *value)
{
	char tmp[40];

	if(fgets(tmp, 40, stdin) == NULL) {
		return -1;
	}

	if(sscanf(tmp, "%d", value) != 1) {
		return -2;
	}

	return 0;
}

int readQuestion(quiz *questionvar)
{
	int error = 0;
	printf("Enter question: ");
	if(readString(questionvar->question, LINESIZE)) error++;

	printf("Enter first alternative: ");
	if(readString(questionvar->alt1, LINESIZE)) error++;

	printf("Enter second alternative: ");
	if(readString(questionvar->alt2, LINESIZE)) error++;

	printf("Enter third alternative: ");
	if(readString(questionvar->alt3, LINESIZE)) error++;

	printf("Enter correct answer: ");
	if(readInt(&questionvar->correctAnswer)) error++;

	return error;
}
