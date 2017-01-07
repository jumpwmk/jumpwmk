#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

long long n,a,b,c;

int main()
{
	int i,j,k;
	long long ans = (long long)INF*INF;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
	for(i=0;i<=30;i++)
		for(j=0;j<=30;j++)
			for(k=0;k<=30;k++)
			{
				// printf("%d %d %d %lld %d\n",i,j,k,(n + 1*i + 2*j + 3*k),(n + 1*i + 2*j + 3*k) % 4 == 0);
				if((n + 1*i + 2*j + 3*k) % 4 == 0)
					ans = min(ans,i*a+j*b+k*c);
			}
	printf("%lld\n",ans);
	return 0;
}