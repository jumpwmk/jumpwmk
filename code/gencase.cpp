#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[100100],chk[100100];

int main()
{
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../10.in","w",stdout);
	int i,j,n = 10000;
	printf("%d 2\n",n);
	for(i = 1; i <= n;i++)
	{
		while(true)
		{
			int tmp = rand()%n;
			if(chk[tmp + 1] == 0)
			{
				chk[tmp + 1] = 1;
				x[i] = tmp + 1;
				break;
			}
		}
	}
	for(i=2;i<=n;i++)
	{
		// if(i <= 20)
			printf("%d %d\n",x[rand()%(i-1) + 1],x[i]);
		// else
		// {
		// 	int tmp = rand()%10 + 1;
		// 	printf("%d %d\n",x[i - tmp],x[i]);
		// }
	}
	return 0;
}