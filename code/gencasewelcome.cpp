#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[5000];

int main()
{
	srand(time(NULL));
	// freopen("../1.in","r",stdin);
	freopen("../10.in","w",stdout);
	int n = 2017;
	printf("%d\n",n);
	for(int i = 0; i < n; i++)
	{
		while(true)
		{
			int tmp = rand() % 4000 + 1;
			if( x[tmp] == 0)
			{
				printf("%d ",tmp);
				x[tmp] = 1;
				break;
			}
		}
	}
	printf("\n");
	return 0;
}