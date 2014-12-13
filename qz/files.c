#include <stdio.h>
#include "data.h"
#define QUIZ_FILE "quiz.dat"

/* returns number of entries that was read from the file */
int readQuizFile(quiz *quizvar)
{
	FILE * infile;
	int count = 0;
    infile = fopen(QUIZ_FILE, "rb");
    if(infile != NULL) {
		count = fread(quizvar, sizeof(quiz), QUIZSIZE, infile);
        fclose(infile);
    }
	quizvar[count].question[0] = '\0'; /* ensure that there is terminator at the end */

	return count;
}

/* returns zero if entries were written to file and non-zero if an error occurred */
int writeQuizFile(quiz *quizvar)
{
	FILE * outfile;
	int count = 0;
	int wcount = 0;
	int numOfExistingQuestions;
    outfile = fopen(QUIZ_FILE, "wb");
    numOfExistingQuestions=questionCounter(quizvar);
    printf("\ncount--%d--", numOfExistingQuestions);
    if(outfile != NULL) {
		wcount = fwrite(quizvar, sizeof(quiz), numOfExistingQuestions, outfile);
        fclose(outfile);
    }

	if(numOfExistingQuestions != wcount) return -1;

	return 0;
}
