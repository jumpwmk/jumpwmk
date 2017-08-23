#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define mod 663224321

using namespace std;

long long x[1100];
long long chk[1100][1100];
long long power[1100];
long long c = 331612161;

void initial()
{
	int i,j;
	power[0] = 1;
	for(i = 1; i <= 1000; i++)
		power[i] = power[i-1]*2;
	for(i = 1; i <= 1000; i++)
		power[i] = (power[i] + mod - 1)%mod;
	chk[1][0] = chk[1][1] = 1;
	for(i = 2; i <= 1000; i++)
	{
		chk[i][0] = chk[i][i] = 1;
		for(j = 1; j < i; j++)
		{
			chk[i][j] = (chk[i-1][j] + chk[i-1][j-1])%mod;
		}
	}
	return;
}

int main()
{
	int i,j,n,k;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	initial();
	x[0] = 1, x[1] = 1, x[2] = 1;
	for(i = 3; i <= n; i++)
	{
		for(j = ((i-1)/2)+1; j < i; j++)
		{
			x[i] += (((power[j] * power[(i-1) - j])%mod * (x[j] * x[(i-1) - j])%mod)%mod * chk[i-1][j])%mod;
			// printf("%d %d %lld %lld %lld %lld %lld %lld\n",i,j,power[j],power[(i-1) - j],x[j],x[(i-1) - j],chk[i-1][j],(((power[j] * power[(i-1) - j])%mod * (x[j] * x[(i-1) - j])%mod)%mod * chk[i-1][j])%mod);
			x[i] %= mod;
			// printf(" %lld\n",x[i]);
		}
		if(i%2)
			x[i] = (x[i] + (((((power[(i-1)/2] * power[(i-1)/2])%mod * (x[(i-1)/2] * x[(i-1)/2])%mod))%mod * chk[i-1][(i-1)/2])%mod *c)%mod)%mod;
		printf("%lld\n",x[i]);
	}
	return 0;
}