#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[5050];

int main()
{
	int i,j,n,ans = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		x[tmp]++;
	}
	for(i = 1;i <= n;i++)
	{
		if(x[i] == 0)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}