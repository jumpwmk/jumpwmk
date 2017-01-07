#include <stdio.h>
#include <vector>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int a,b;
long long mod = 1000000009;
long long cnt[100100];
long long sum = 0;
int ch;
vector <int > v[100100];

void play(int ii,int ago)
{
	if(ii == b)
	{
		sum -= cnt[ii];
		cnt[ii] *= 2;
		cnt[ii] %= mod;
		sum += cnt[ii];
		sum = ((sum%mod) + mod)%mod;
		ch = 1;
		return;
	}
	for (int i = 0; i < v[ii].size(); ++i)
	{
		if(v[ii][i] != ago)
		{
			play(v[ii][i],ii);
			if(ch)
			{
				sum -= cnt[ii];
				cnt[ii] *= 2;
				cnt[ii] %= mod;
				sum += cnt[ii];
				sum = ((sum%mod) + mod)%mod;
				return;
			}
		}
	}
}

int main()
{
	int n,q,s,e;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		sum++;
		cnt[i] = 1;
	}
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d",&s,&e);
		v[s].push_back(e);
		v[e].push_back(s);
	}
	scanf("%d %d",&s,&e);
	int m = s+e;
	while(m--)
	{
		int cmd;
		scanf("%d",&cmd);
		ch = 0;
		if(cmd == 1)
		{
			printf("%lld\n",sum);
		}
		else
		{
			scanf("%d %d",&a,&b);
			play(a,-1);
		}
	}
	return 0;
}