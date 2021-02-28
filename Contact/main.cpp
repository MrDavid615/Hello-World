#include <stdio.h>
#include "contact.h"

int main()
{
	int i;
	struct contact* first = (struct contact*)malloc(36);
	struct contact* pNum = first;
	do{
		printf("------------CONTACT-------------\n");
		printf("-----1.添加---------2.查询------\n");
		printf("-----3.删除---------0.退出------\n");
		printf("--------------------------------\n");
		printf("输入指令");
		scanf("%d",&i);
		if(i == 1)
			pNum = contact_add(pNum);
		if(i == 2)
			contact_find(first);
	}while(i);


	return 0;
}