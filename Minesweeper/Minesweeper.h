#ifndef		__Minesweeper_h
#define		__Minesweeper_h

#include <stdio.h>
#include <stdlib.h>

void lay_mine(char (*a)[99], int h, int l, int Mine);
void sweep(char (*a)[99], int h, int l);

#endif
