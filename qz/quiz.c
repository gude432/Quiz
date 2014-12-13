#include <stdio.h>
#include <conio.h>

#include "data.h"
#include "files.h"
#include "readers.h"

void printMenu(void);
int initialize(quiz *quizvar);
int addQuestion(quiz *quizvar);
int takeQuiz(quiz *quizvar, int *percentile);
void error(int *err);
int questionCounter(quiz *quizvar);
int printReport(quiz *quizvar, int *percentile);

int main(int argc, char *argv[]){
    quiz qset[QUIZSIZE + 1] = { NULL };
    int selection = -1;
	int numOfExistingQuestions = questionCounter(qset);
	int percentile =0;
	do {

		printMenu();
		/* loop until user enters a number */
		while(readInt(&selection)) {
			printf("Invalid selection\n");
			printMenu();
		}
		/* check which option was selected */
		switch (selection)
		{
		case 1:
			initialize(qset);
			break;
		case 2:
			printf("%d\n", writeQuizFile(qset));
			break;
		case 3:
			readQuizFile(qset);
			break;
		case 4:
			addQuestion(qset); //passing array name is same as passing address of the first element in the arrary=pointer
			break;
		case 5:
			takeQuiz(qset, &percentile);
			break;
		case 6:
			printf("Not implemented yet\n");
			break;
		case 7:
			printf("Goodbye\n");
			exit(0);
			break;
		case 8:
			printf("\n NUM OF QUESTIONS %d\n",questionCounter(qset));
			break;
		default:
			printf("Invalid selection\n");
			break;
		}

	} while(selection);

	return 0;
}


void printMenu(void)
{
	printf("Select action (0-7)\n");
	printf("1 - Initialize\n");
	printf("2 - Save questions to disk\n");
	printf("3 - Read questions from disk\n");
	printf("4 - Add new question\n");
	printf("5 - Take quiz\n");
	printf("6 - Print report\n");
	printf("7 - Exit\n");
}

int initialize(quiz * quizptr){
	quizptr->question[0] = 0;
	printf("Successfully initialized \n");
	return 0;
}

int questionCounter(quiz *quizptr){
    int count =0;
    for(count = 0; count<QUIZSIZE &&  strlen(quizptr[count].question) != 0 ; count++);
    return count;
}


int addQuestion(quiz * ptr){
    int x=questionCounter(ptr);
    int errcode = readQuestion(&ptr[x]);
    if(errcode==0)
        printf("\nSuccessfuly added.\n");
    else
        error(errcode);
    return 0;
}

int takeQuiz(quiz * quizptr, int *percentile){
    float x =0;
    int i, ans, percent, score, random,num = 0;
    num = questionCounter(quizptr);
    printf("%d",num);
    if (num<NUMOFQUIZSESSION){
        printf("Atleast %d questions are required", NUMOFQUIZSESSION );
    }

    else{
        int asked[QUIZSIZE] = {0};
        for (i=0; i<NUMOFQUIZSESSION ; ){

            x = rand()/32768.0 ;
            random = (int)(num*x);

                if (asked[random] == 0){ //unasked
                    while (1){
                    printf("%s\n1) %s\n2) %s\n3) %s\nEnter answer: ", quizptr[random].question,quizptr[random].alt1,quizptr[random].alt2,quizptr[random].alt3);
                    readInt(&ans);

                    if(ans == quizptr[random].correctAnswer){
                        score++;
                        printf("\nCorrect\n");
                        i++;
                        asked[random]=1; //mark as asked question
                        break;
                    }
                    else if((ans == 1 || ans == 2 || ans == 3) && ans != quizptr[random].correctAnswer){
                      printf("\nWrong\n");
                      i++;
                      asked[random]=1;
                      break;
                    }
                    else
                        printf("Please answer either 1, 2, or 3\n");
                        // increment only if question was asked
                    }
                }


        }
        *percentile = score*100/NUMOFQUIZSESSION;

     }
    return 0;
}

int printReport(quiz *quizvar, int *percentile){
    if(*percentile > 75){

    }
    return 0;
}


void error(int *err){
if(err == -1) printf("\nPlease enter a value\n");
if(err == -2) printf("\nPlease enter a valid value\n");
}



