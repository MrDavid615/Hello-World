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
		printf("-----1.���---------2.��ѯ------\n");
		printf("-----3.��ʾ---------4.ɾ��------\n");
		printf("------------0.�˳�--------------\n");
		printf("--------------------------------\n");
		printf("����ָ��");
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