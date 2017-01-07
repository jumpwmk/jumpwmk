#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

long long ans = 1;

int main()
{
	int i,n;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		ans = ans + (ans * 3);
	}
	printf("%lld\n",ans);
	return 0;
}