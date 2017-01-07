#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[100100];

int main()
{
	int i,n = 100000,k = 1;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../49.in","w",stdout);
	printf("%d %d\n",n,k);
	for(i=1;i<=n;i++)
	{
		printf("%d ",rand()%1000 + 1);
	}
	return 0;
}