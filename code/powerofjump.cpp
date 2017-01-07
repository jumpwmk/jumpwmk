#include <stdio.h>
#include <algorithm>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define mod 1000000007
#define INF 1000000000

using namespace std;

long long tmp[5010];
long long cnt[5010];
long long x[5010];
long long fen[2][5010];
int n;

void update(int k,int ii,long long w)
{
	while(ii <= n)
	{
		fen[k][ii] += w;
		ii += (ii & -ii);
	}
}

long long sum(int k,int ii)
{
	long long ans = 0;
	while(ii >= 1)
	{
		ans += fen[k][ii];
		ii -= (ii & -ii);
	}
	return ans%mod;
}

int main()
{
	int i,j,k,m,t;
	long long res = 0,chk;
	// freopen("../10.in","r",stdin);
	// freopen("../10.sol","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		res = 0;
		memset(fen,0,sizeof(fen));
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			tmp[i] = x[i];
		}
		sort(tmp+1,tmp+n+1);
		for(i=1;i<=n;i++)
		{
			j = lower_bound(tmp+1,tmp+n+1,x[i]) - tmp;
			x[i] = j;
		}
		cnt[1] = 1;
		update(0,x[1],cnt[1]);
		for(i=2;i<=n;i++)
		{
			chk = sum(0,x[i]-1);
			cnt[i] = chk;
			update(0,x[i],cnt[i]);
		}
		res += cnt[n];
		for(k=1;k<=m;k++)
		{
			memset(fen,0,sizeof(fen));
			for(i=1;i<=n;i++)
			{
				chk = sum(k%2,x[i]-1) + sum((k+1)%2,n) - sum((k+1)%2,x[i]-1);
				chk %= mod;
				if(chk < 0)
					chk += mod;
				update((k+1)%2,x[i],cnt[i]);
				cnt[i] = chk;
				update(k%2,x[i],cnt[i]);
			}
			res += cnt[n];
		}
		res %= mod;
		printf("%lld\n",res);
	}
	return 0;
}