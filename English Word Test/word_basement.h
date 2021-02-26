#ifndef __WORD_BASEMENT_H
#define __WORD_BASEMENT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	mean_size	35

typedef struct
{
	int Num;
	char* word;
	char* mean;
}Word_Basement;

#define	Basement1 1
#if	Basement1

#define HOW_MUCH     22
extern Word_Basement Base[HOW_MUCH];

#endif

void Word_test(void);

#endif //word_basement.h