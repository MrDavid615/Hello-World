#ifndef __CONTACT_H
#define __CONTACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct contact
{
	char name[8];
	char sex[8];
	int age;
	char ID[12];
};

struct NumofCon
{
	int Num;
	struct contact p[];
};

struct NumofCon* Contact_Init(void);
struct NumofCon* contact_add(struct NumofCon* ps);
void contact_find(struct NumofCon* addr);
void contact_Printall(struct NumofCon* ps);
struct NumofCon* contact_delete(struct NumofCon* ps);
void contact_serve(struct NumofCon* ps);
struct NumofCon* Contact_read(struct NumofCon* ps);

#endif

