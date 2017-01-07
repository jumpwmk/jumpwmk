#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 1000000000

using namespace std;

long long create[10010];
long long sell[10010];
long long chk[10010];
long long check[10010];

int main()
{
	int i,j,n;
	long long c,ch = 0;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d %lld",&n,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%lld ",&create[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&sell[i]);
	}
	for(i=n;i >= 1;i--)
	{
		chk[i] = sell[i] - create[i] + ch;
		ch += max(0ll,(min(c,sell[i]-create[i])));
	}
	for(i=1;i<=n;i++)
	{
		long long cnt = create[i] - sell[i];
		if(cnt <= 0)
			continue;
		memset(check,0,sizeof(check));
		for(j = i + 1;j <= n && cnt > 0;j++)
		{
			long long res = min(c,min(cnt,sell[j] - create[j]));
			if(res > 0)
			{
				create[j] += res;
				chk[j] -= res;
				cnt -= res;
				check[j] += res;
			}
		}
		for(j = i + 1;j <= n && cnt > 0;j++)
		{
			long long res = min((min(c - check[j],chk[j])),cnt);
			if(res < 0)
				res = 0;
			// printf("%d %d %lld\n",i,j,res);
			create[j] += res;
			chk[j] -= res;
			cnt -= res;
		}
		create[i] = sell[i];
	}
	long long ans = 0;
	for(i=1;i<=n;i++)
	{
		ans += create[i];
		// printf(" %d %lld\n",i,create[i]);
	}
	printf("%lld\n",ans);
	return 0;
}