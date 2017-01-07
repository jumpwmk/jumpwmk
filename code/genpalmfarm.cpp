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
	int r,c,i,j;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../10.in","w",stdout);
	r = 100,c = 100;
	printf("%d %d\n",r,c);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			printf("%d ",rand()%1000000000);
		}
		printf("\n");
	}
	return 0;
}