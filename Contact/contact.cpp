#include "contact.h"

struct contact* contact_add(struct contact* addr)
{
	addr->p = (struct contact*)malloc(36);
	printf("����������:");
	scanf("%s",addr->name);
	printf("�������ձ�:");
	scanf("%s",addr->sex);
	printf("����������:");
	scanf("%d",&(addr->age));
	printf("������绰:");
	scanf("%s",addr->ID);
	strcpy(addr->p->name, "People");
	return addr->p;
}

void contact_find(struct contact* addr)
{
	char name[8];
	printf("�����ѯ�ߵ�����:");
	scanf("%s",name);
	char* p;
	do{
		p = addr->name;
		if(strcmp(p,"People") == 0)
			break;
	}while(strcmp(name,p)&&(addr = addr->p));
	printf("����:%s\n",addr->name);
	printf("�ձ�:%s\n",addr->sex);
	printf("����:%d\n",addr->age);
	printf("�绰:%s\n",addr->ID);
}

void contact_Delete(struct contact* addr)
{
	char name[8];
	printf("����ɾ���ߵ�����:");
	scanf("%s",name);
	char* p;
	do{
		p = addr->name;
		if(strcmp(p,"People") == 0)
			break;
	}while(strcmp(name,p)&&(addr = addr->p));
	free(addr);
	addr = NULL;
}
