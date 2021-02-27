#include "minesweeper.h"


void lay_mine(char (*a)[99], int h, int l, int Mine)
{
	int x = h,y = l;
	for(int i = 0; i<Mine; i++)
	{
		for(x = rand(); x>h; x = rand());
		for(y = rand(); y>l; y = rand());
		a[x][y] = 1;
	}
}

void sweep(char (*a)[99], int h, int l)
{
	char b[99][99];
	for(int i=0; i<99; i++)
	{
		for(int j=0; j<99; j++)
		{
			b[i][j] = '?';
		}
	}
	int x = 99-1,y = 99-1,Num;
	do
	{

		for(i = x-1; i<=x+1; i++)
		{
			for(int j=y-1; j<=y+1; j++)
			{
				for(int sh=i-1; sh<=i+1; sh++)
				{
					for( int sl=j-1; sl<=j+1; sl++)
					{
						if(a[sh-1][sl-1] == 1)
							Num++;
					}
				}
				if(b[i-1][j-1] != '#')
					b[i-1][j-1] = Num;
				Num = 0;
			}
		}		
		system("cls");
/*
用作调试功能
		for(i=0; i<h; i++)
		{
			for(int j=0; j<l; j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
*/
		printf("     1 2 3 4 5 6 7 8 9 10\n");
		for(i=0; i<h; i++)
		{
			printf("\n%3d  ",i+1);
			for(int j=0; j<l; j++)
			{
				if((b[i][j] == '#') || (b[i][j] == '?'))
					printf("%c ",b[i][j]);
				else
					printf("%d ",b[i][j]);
			}
		}
		printf("\n\n输入你要扫描的坐标:");
		scanf("%d.%d",&x,&y);


	}while(a[x-1][y-1] == 0 && (b[x-1][y-1] = '#'));

}

