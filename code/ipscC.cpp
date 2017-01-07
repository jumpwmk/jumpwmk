#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

long long mod =  1000000009;
int x[100100];
int mark[100100];
long long chk[100100];
long long cnt[100100];
long long mst[100100];

int play(int ii)
{
	if(mark[ii])
		return 0;
	mark[ii] = 1;
	return play(x[ii]) + 1;
}

long long check(long long x,long long pow)
{
	long long tmp = 0;
	if(pow == 1)
	{
		return x%mod;
	}
	if(pow == 0)
		return 1;
	tmp = check(x,pow/2);
	// printf("%lld\n",tmp);
	if(pow%2 == 0)
		return (tmp*tmp)%mod;
	else
		return (((tmp*tmp)%mod)*x)%mod;
}

int main()
{
	int i,j,n,t;
	long long res = 0,tmp,ch;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&t);
	tmp = 1;
	for(i=1;i<=100000;i++)
	{
		tmp *= i;
		tmp %= mod;
	}
	chk[100000] = check(tmp,mod-2);
	for(i=99999;i>=1;i--)
	{
		chk[i] = chk[i+1]*(i+1);
		chk[i]%=mod;
	}
	cnt[0] = 1;
	for(i=1;i<=100000;i++)
	{
		cnt[i] = cnt[i-1]*i;
		cnt[i] %= mod;
	}
	// mst[1] = 1;
	// for(i=2;i<=100000;i++)
	// {
	// 	mst[i] = check(i,i-2);
	// }
	while(t--)
	{
		ch = 0;
		memset(mark,0,sizeof(mark));
		scanf("%d",&n);
		res =1;
		for(i=1;i<=n;i++)
			scanf("%d",&x[i]);
		for(i=1;i<=n;i++)
		{
			if(mark[i] == 0)
			{
				tmp = play(i);
				if(tmp == 1)
					continue;
				res = res*check(tmp,tmp-2);
				res %= mod;
				res *= chk[tmp-1];
				ch += tmp-1;
				res %= mod;
			}
		}
		if(ch >= 2)
			res = res*cnt[ch];
		// printf("%lld\n",ch);
		res %= mod;
		// printf("= %lld\n",2*cnt[ch]);
		printf("%lld\n",res);
	}
	return 0;
}