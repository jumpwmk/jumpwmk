#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[1100],y[1100];

int main()
{
	int i,j,n,m,ans = INF;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&y[i]);
	}
	sort(x,x+n);
	sort(y,y+m);
	if(n >= 2)
	{
		ans = x[0] + x[1];
	}
	if(m >= 2)
	{
		ans = min(ans,y[0]+y[1]);
	}
	if(n >= 1 && m >= 1)
	{
		ans = min(ans,x[0] + y[0] + 100);
	}
	printf("%d\n",ans);
	return 0;

}