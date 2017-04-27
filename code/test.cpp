#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

double p[1010],s[1010];

int main()
{
	int i,j,t,n;
	double k;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&t);
	for(int loop = 1; loop <= t; loop++)
	{
		printf("Case #%d: ",loop);
		scanf("%lf %d",&k,&n);
		for(i = 0; i < n; i++)
		{
			scanf("%lf %lf",&p[i],&s[i]);
		}
		double l = 0.0,r = 1ll<<32,mid;
		int tt = 400;
		while(tt--)
		{
			mid = (l+r)/2.0;
			bool ch = true;
			for(i = 0; i < n; i++)
			{
				if(s[i] >= mid)
				{
					continue;
				}
				if(p[i]*mid < k*(mid-s[i]))
				{
					break;
				}
			}
			if(i < n)
				r = mid;
			else
				l = mid;
		}
		printf("%lf\n",l);
	}
	return 0;
}