#include "contact.h"

struct contact* contact_add(struct contact* addr)
{
	addr->p = (struct contact*)malloc(36);
	printf("请输入姓名:");
	scanf("%s",addr->name);
	printf("请输入姓别:");
	scanf("%s",addr->sex);
	printf("请输入年龄:");
	scanf("%d",&(addr->age));
	printf("请输入电话:");
	scanf("%s",addr->ID);
	strcpy(addr->p->name, "People");
	return addr->p;
}

void contact_find(struct contact* addr)
{
	char name[8];
	printf("输入查询者的姓名:");
	scanf("%s",name);
	char* p;
	do{
		p = addr->name;
		if(strcmp(p,"People") == 0)
			break;
	}while(strcmp(name,p)&&(addr = addr->p));
	printf("姓名:%s\n",addr->name);
	printf("姓别:%s\n",addr->sex);
	printf("年龄:%d\n",addr->age);
	printf("电话:%s\n",addr->ID);
}

void contact_Delete(struct contact* addr)
{
	char name[8];
	printf("输入删除者的姓名:");
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
