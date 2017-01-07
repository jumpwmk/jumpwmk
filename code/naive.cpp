#include <stdio.h>
#include <stdlib.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

long long x[100100];

int main()
{
	int n,k,st,en,size = 0,i,j,t;
	freopen("../10.in","r",stdin);
	freopen("../10.sol","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		long long res = -(long long)INF*1000000,sum = -(long long)INF*1000000,cnt = 0;
		size = 0;
		scanf("%d %d",&n,&k);
		// printf("%d %d\n",n,k);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			cnt += x[i];
			if(x[i] + sum > 0)
			{
				sum += x[i];
				if(res < sum)
				{
					res = sum;
					size = i-st+1;
				}
			}
			else
			{
				sum = x[i];
				st = i;
				if(res < sum)
				{
					res = sum;
					size = 1;
				}
			}
			x[i] += x[i-1];
		}
		// printf("%d %lld\n",size,res);
		res = 0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
			{
				if(i-j >= 0 && res < x[i]-x[i-j])
				{
					res = x[i]-x[i-j],st = i-j+1,en = i;
				}
			}
		}
		printf("%lld\n",res);
		// printf("%d\n",en-st+1);
		// for(i=st;i<=en;i++)
		// 	printf("%lld\n",x[i]-x[i-1]);
	}
	return 0;
}