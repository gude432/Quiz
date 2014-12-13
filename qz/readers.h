#ifndef READERS_H_INCLUDED
#define READERS_H_INCLUDED

#include "data.h"

int readString(char *str, int maxsize);
int readInt(int *value);
int readQuestion(quiz *quizptr);

#endif
