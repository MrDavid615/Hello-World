#include <stdio.h>
#include "contact.h"

int main()
{
	int i;
	struct contact* first = (struct contact*)malloc(36);
	struct contact* pNum = first;
	do{
		printf("------------CONTACT-------------\n");
		printf("-----1.���---------2.��ѯ------\n");
		printf("-----3.ɾ��---------0.�˳�------\n");
		printf("--------------------------------\n");
		printf("����ָ��");
		scanf("%d",&i);
		if(i == 1)
			pNum = contact_add(pNum);
		if(i == 2)
			contact_find(first);
	}while(i);


	return 0;
}