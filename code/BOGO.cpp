#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[200100];

int main()
{
	// freopen("../10.in","r",stdin);
	// freopen("../10.sol","w",stdout);
	int i,j,n,m,p;
	int res = -1;
	scanf("%d %d %d",&n,&m,&p);
	x[0] = 0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	x[++n] = m;
	sort(x,x+n+1);
	for(i=1;i<=n;i++)
	{
		if(i-2*p < 0)
			res = mx(res,x[i]);
		else
			res = mx(res,x[i]-x[i-2*p]);
		if(i+2*p > n)
			res = mx(res,m-x[i]);
		else
			res = mx(res,x[i+2*p]-x[i]);
	}
	printf("%lld\n",(long long)res*(long long)res);
	return 0;
}