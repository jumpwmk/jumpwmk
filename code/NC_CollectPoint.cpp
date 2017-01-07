#include <stdio.h>
#include <set>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

set <long long > s;
set <long long >::iterator it;

int main()
{
	long long tmp,mic = 0,m,ans = 0;
	int i,j,n;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	s.insert(0);
	scanf("%d %lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&tmp);
		tmp %= m;
		mic += tmp;
		mic %= m;
		// printf("%lld\n",mic);
		s.insert(mic);
		it = s.upper_bound(mic);
		if(it != s.end())
			ans = mx(ans,mic+m-*it);
		ans = mx(ans,mic);
	}
	printf("%lld\n",ans);
	return 0;
}