#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define mod 2000000000

using namespace std;

long long x[100100];
long long sum[100100];
long long res;

bool solution()
{
	int i,j,n = 100000,k,tmp,chk,tmpchk;
	res = 0;
	for(i=1;i<=n;i++)
	{
		tmp = rand()%mod+1;
		if(rand()%2 == 0)
			tmp *= -1;
		x[i] = tmp;
		sum[i] = x[i] + sum[i-1];
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(sum[i]-sum[j] > res)
			{
				res = sum[i]-sum[j];
				chk = i-j;
			}
			if(sum[i]-sum[j] == res && chk > i-j)
				chk = i-j;
		}
	}
	tmpchk = chk;
	res = 0;
	chk = 0;
	k = (tmpchk*4)/5;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(i-j <= k)
			{
				if(sum[i]-sum[j] > res)
				{
					res = sum[i]-sum[j];
					chk = i-j;
				}
				if(sum[i]-sum[j] == res && chk < i-j)
					chk = i-j;
			}
		}
	}
	if(chk == k)
		return false;
	// printf("- %d %d %d -\n",chk,k,tmpchk);
	printf("%d %d\n",n,k);
	for(i=1;i<=n;i++)
	{
		printf("%lld\n",x[i]);
	}
	return true; 
}

int main()
{
	int t = 5;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../20.in","w",stdout);
	printf("5\n");
	while(t>0)
	{
		if(solution())
		{
			t--;
		}
	}
	return 0;
}