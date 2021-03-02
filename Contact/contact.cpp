#include "contact.h"

struct NumofCon* Contact_Init(void)
{
	struct NumofCon* ps = (struct NumofCon*) malloc(4+32*1);
	if(ps == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	ps->Num = 0;
	return ps;
}

struct NumofCon* Contact_read(struct NumofCon* ps)
{
	struct contact file;
	int Num = 1;
	int check = Num-1;
	FILE* pf = fopen("contact.txt", "r");
	if(pf == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	char ch = fgetc(pf);
	if(ch == EOF)
		Num = 0;
	rewind(pf);

	while(Num)
	{
		fscanf(pf, "%d", &Num);
		if(check == Num)
			break;
		check = Num;
		fscanf(pf, "%s", file.name);
		fscanf(pf, "%s", file.sex);
		fscanf(pf, "%d", &(file.age));
		fscanf(pf, "%s", file.ID);
		ps = (struct NumofCon*) realloc(ps,4+32*Num);
		ps->Num = Num;
		strcpy(ps->p[Num-1].name, file.name);
		strcpy(ps->p[Num-1].sex, file.sex);
		ps->p[Num-1].age = file.age;
		strcpy(ps->p[Num-1].ID, file.ID);
	}
	fclose(pf);
	return ps;
}


struct NumofCon* contact_add(struct NumofCon* ps)
{
	ps->Num++;
	struct NumofCon* ps2 = (struct NumofCon*) realloc(ps,4+32*(ps->Num));
	if(ps2 == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	int i = ps2->Num-1;
	printf("����������:");
	scanf("%s",ps2->p[i].name);
	printf("�������ձ�:");
	scanf("%s",ps2->p[i].sex);
	printf("����������:");
	scanf("%d",&(ps2->p[i].age));
	printf("������绰:");
	scanf("%s",ps2->p[i].ID);
	ps = ps2;
	ps2 = NULL;
	return ps;
}

void contact_find(struct NumofCon* ps)
{
	int i=0;
	char name[8];
	printf("������ҪѰ�ҵ���������:");
	scanf("%s",name);
	while(strcmp(name,ps->p[i].name))
	{
		i++;
	}
	printf("����:%s\n",ps->p[i].name);
	printf("�ձ�:%s\n",ps->p[i].sex);
	printf("����:%d\n",ps->p[i].age);
	printf("�绰:%s\n",ps->p[i].ID);
}

void contact_Printall(struct NumofCon* ps)
{
	for(int i = 0;i<ps->Num; i++)
	{
		printf("Num:%d\n",i+1);
		printf("����:%s\n",ps->p[i].name);
		printf("�ձ�:%s\n",ps->p[i].sex);
		printf("����:%d\n",ps->p[i].age);
		printf("�绰:%s\n",ps->p[i].ID);
	}
}

struct NumofCon* contact_delete(struct NumofCon* ps)
{
	int i=0;
	char name[8];
	printf("������Ҫɾ������������:");
	scanf("%s",name);
	while(strcmp(name,ps->p[i].name))
	{
		i++;
		if(i>ps->Num-1)
		{
			printf("û�д�����Ϣ\n");
			return ps;
		}
	}
	for(;i < ps->Num; i++)
	{
		strcpy(ps->p[i].name, ps->p[i+1].name);
		strcpy(ps->p[i].sex, ps->p[i+1].sex);
		ps->p[i].age = ps->p[i+1].age;
		strcpy(ps->p[i].ID, ps->p[i+1].ID);
	}
	ps->Num = ps->Num - 1;
	struct NumofCon* ps2 = (struct NumofCon*) realloc(ps,4+32*(ps->Num));
	if(ps2 == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	ps = ps2;
	ps2 = NULL;
	printf("%s����Ϣ�Ѿ��Ƴ�\n",name);
	return ps;
}

void contact_serve(struct NumofCon* ps)
{
	FILE* pf = fopen( "contact.txt", "w");
	int i = 0;
	if(pf == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	while(i < ps->Num)
	{
		fprintf(pf, "%d ",i+1);
		fprintf(pf, "%s ",ps->p[i].name);
		fprintf(pf, "%s ",ps->p[i].sex);
		fprintf(pf, "%d ",ps->p[i].age);
		fprintf(pf, "%s\n",ps->p[i].ID);
		i++;
	}
	fclose(pf);
}
