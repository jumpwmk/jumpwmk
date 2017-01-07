#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[1000010];

int main()
{
	int i,j,n;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	x[ 0 ]  = 0;
	for(i = 1;i <= n;i++)
	{
		x[i] = -1;
		if(i >= 7 && x[ i - 7 ] >= 0)
			x[i] = x[i-7] + 1;
		else if(i >= 4 && x[i-4] >= 0)
			x[i] = x[i-4];
	}
	if(x[n] == -1)
	{
		printf("-1\n");
		return 0;
	}
	int sum = n - 7 * x[n];
	while(sum > 0)
	{
		sum -= 4;
		printf("4");
	}
	for(i=0;i<x[n];i++)
		printf("7");
	printf("\n");
	return 0;
}