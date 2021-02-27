#include <stdio.h>
#include "Minesweeper.h"

int main()
{
	char a[99][99] = {0};
	lay_mine(a, 10, 10, 20);
	sweep(a,10,10);

	return 0;
}
