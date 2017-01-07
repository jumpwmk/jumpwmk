#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char x[330][330];

int main()
{
	int q = 5;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../2.in","w",stdout);
	printf("%d\n",q);
	while(q--)
	{
		int r = 30,c = 30,k = 100;
		printf("%d %d %d\n",r,c,k);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				int random = rand()%10;
				if(random == 0)
				{
					x[i][j] = '#';
					printf("#");
				}
				else
				{
					x[i][j] = '.';
					printf(".");
				}
			}
			printf("\n");
		}
		while(true)
		{
			int i = rand()%r;
			int j = rand()%c;
			if(x[i][j] == '.')
			{
				printf("%d %d\n",i+1,j+1);
				break;
			}
			
		}
	}
	return 0;
}