#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[10010];

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	int i,j,n,m,l;
	long long ans = 0;
	scanf("%d %d %d",&n,&m,&l);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&x[i]);
		ans += x[i];
	}
	sort(x,x+n,cmp);
	for(i = l; i < n; i += m)
	{
		if(i + m - l > n)
			break;
		for(j = i; j < i + m - l and j < n; j++)
		{
			ans -= x[j];
			// printf("%d %d %d\n",j,i + m,x[j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}