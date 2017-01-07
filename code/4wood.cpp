#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

int x[100100];

int main()
{
	int i,j;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	x[1] = x[2] = x[3] = 1, x[4] = 2;
	for(i=5;i<=100000;i++)
	{
		x[i] = x[i-1] + x[i-4];
		x[i] %= 100003;
	}
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",x[n]);
	}
	return 0;
}