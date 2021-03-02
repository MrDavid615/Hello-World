#include <stdio.h>
#include "contact.h"

int main()
{
	int i;
	struct NumofCon* Con = Contact_Init();
	Con = Contact_read(Con);

	do{
		system("pause");
		system("cls");
		printf("------------CONTACT-------------\n");
		printf("-----1.添加---------2.查询------\n");
		printf("-----3.显示---------4.删除------\n");
		printf("------------0.退出--------------\n");
		printf("--------------------------------\n");
		printf("输入指令");
		scanf("%d",&i);
		if(i == 1)
			Con = contact_add(Con);
		if(i == 2)
			contact_find(Con);
		if(i == 3)
			contact_Printall(Con);
		if(i == 4)
			Con = contact_delete(Con);
	}while(i);

	contact_serve(Con);

	return 0;
}