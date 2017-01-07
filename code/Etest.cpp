#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	int i,j;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("test.in","w",stdout);
	printf("%d\n",1000);
	for(i=1;i<=1000;i++)
	{
		for(j=1;j<=1000;j++)
		{
			// printf("%d ",(rand()%1000 + 1)*2*5*5*2);
			printf("0 ");
		}
		printf("\n");
	}
	return 0;
}