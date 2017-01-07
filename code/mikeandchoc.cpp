#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

long long m = 200000;
long long chk[200000];

int main()
{
	long long i,j,n,l,r,mid,cnt,ans;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	for(i=1;i<=m;i++)
	{
		chk[i] = i*i*i;
	}
	scanf("%lld",&n);
	l = 1,r = 1LL << 60;
	while(l < r)
	{
		mid = (l+r)/2;
		ans = 0;
		for(i=2;i<=m;i++)
		{
			cnt = mid/chk[i];
			ans += cnt;
		}
		if(ans >= n)
			r = mid;
		else l = mid+1;
	}
	ans = 0;
	for(i=2;i<=m;i++)
	{
		cnt = l/chk[i];
		ans += cnt;
	}
	// printf("%lld %lld\n",l,ans);
	if(ans != n)
		printf("-1");
	else
		printf("%lld\n",l);
	return 0;
}