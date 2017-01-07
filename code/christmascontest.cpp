#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

long long x[100100];
long long y[100100];
long long yy[2][40];

int main()
{
	int i,j,n,m;
	long long ans = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld",&y[i]);
		for(j=0;j<30;j++)
		{
			if((y[i] & (1 << j)))
			{
				yy[1][j]++;
			}
			else
			{
				yy[0][j]++;
			}
		}
	}
	long long test = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<30;j++)
		{
			if((x[i] & (1 << j)))
			{
				ans += (long long)(1 << j) * yy[0][j];
			}
			else
			{
				ans += (long long)(1 << j) * yy[1][j];
			}
			// printf("%d %d %lld\n",i,j,ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}