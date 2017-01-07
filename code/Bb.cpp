#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[1000100];
int mark[1000100];

int main()
{
	int i,j,n,m;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
		mark[x[i]]++;
	}
	long long cnt = 0;
	for(i = 0;i<n;i++)
	{
		int chk = x[i]^m;
		cnt += (long long)mark[chk];
		// printf("%d %d\n",mark[chk],chk);
	}
	printf("%lld\n",cnt/2);
	return 0;
}