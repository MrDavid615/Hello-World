#include "word_basement.h"


void Word_test(void)
{
	int i,how_much = HOW_MUCH;
	short fault[HOW_MUCH] = {0};
	char s[20];
	for(i = 0;i<HOW_MUCH;i++)
	{
		printf("%s\n",Base[i].mean);
		scanf("%s",s);
		if(!strcmp(s,"what"))
		{
			printf("This word is : %s\n",Base[i].word);
		}
		else if(strcmp(s,Base[i].word))
		{
			printf("Fault!\n");
			fault[i--] = 1;
		}
	}
	printf("OK\n");

	system("pause");
	system("cls");
	
	printf("----------- fault words -----------\n\n");
	while(how_much--)
	{
		if(fault[how_much] != 0)
			printf(" %s , %s\n",Base[how_much].word,Base[how_much].mean);
	}
}