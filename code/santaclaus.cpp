#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	int i,j,n,ans;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	ans = 0;
	for(i=1;ans + i <= n;i++)
	{
		ans += i;
	}
	printf("%d\n",i-1);
	for(j = 1;j<i-1;j++)
	{
		printf("%d ",j);
	}
	printf("%d\n",j + n - ans);
	return 0;
}