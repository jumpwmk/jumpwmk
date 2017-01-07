#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

int x[5000];

int main()
{
	int i,j,n,a,ans = -1,tmp = INF;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		x[a]++;
	}
	for(i=1;i<=4000;i++)
	{
		if(x[i] && abs(i - 2017) < tmp)
		{
			tmp = abs(i - 2017);
			ans = i;
			// printf("%d\n",i);
		}
	}
	printf("%d\n",ans);
	return 0;
}