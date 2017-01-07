#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

long long x[100100];
int chk[100100];
long long sum;
long long tmp;

int main()
{
	int i,j,n,ch = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=100000;i++)
	{
		x[i] = (long long)i-1;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		chk[j] = 1;
	}
	for(i=2;i<=100000;i++)
	{
		ch = 0;
		tmp = (long long)x[i];
		for(j=i;j<=100000;j+=i)
		{
			if(chk[j])
			{
				ch = 1;
			}
			x[j] -= tmp;
		}
		if(ch)
		{
			// printf("%d %lld\n",i,tmp);
			sum += (long long)tmp;
		}
	}
	printf("%lld\n",sum);
	return 0;
}