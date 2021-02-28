#ifndef __CONTACT_H
#define __CONTACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{
	char name[8];
	char sex[8];
	int age;
	char ID[12];
	struct contact* p;
};


struct contact* contact_add(struct contact* addr);
void contact_find(struct contact* addr);
void contact_Delete(struct contact* addr);

#endif

