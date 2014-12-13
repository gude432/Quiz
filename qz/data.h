#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#define LINESIZE 256  /* maximum length of a question or alternatives */

#define QUIZSIZE 16 /* maximum number of questions in the quiz */
#define NUMOFQUIZSESSION 5 /* number of questions in a take quiz session */

typedef struct quiz_
{
	char question[LINESIZE];
	char alt1[LINESIZE];
	char alt2[LINESIZE];
	char alt3[LINESIZE];
	int correctAnswer;
} quiz;


#endif
