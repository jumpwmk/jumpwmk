#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[100010];
int l[100010];
int r[100010];

int main()
{
	int i,j,n,ans = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(x[i] <= x[i-1])
			r[i] = 1;
		else
			r[i] = r[i - 1] + 1;
		ans = mx(ans,r[i]);
	}
	if(ans < n)
	{
		ans++;
	}
	for(i = n;i >= 1;i--)
	{
		if(x[i] >= x[i + 1])
			l[i] = 1;
		else
			l[i] = l[i + 1] + 1;
	}
	for(i = 2;i < n;i++)
	{
		if(x[i + 1] - 2 >= x[i - 1])
		{
			// printf("%d %d\n",i,l[i+1] + r[i-1] + 1);
			ans = mx(ans,l[i+1] + r[i-1] + 1);
		}
	}
	printf("%d\n",ans);
	return 0;
}