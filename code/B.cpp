#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int mic[110];
int x[110];
int ans[110];

int main()
{
	int i,n,m;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		mic[i] = mic[i-1]+x[i];
	}
	int a,b;
	while(m--)
	{
		scanf("%d %d",&a,&b);
		if(mic[b] - mic[a-1] < 0)
			continue;
		// printf("%d %d\n",a,b);
		ans[a]++;
		ans[b+1]--;
	}
	long long res = 0;
	for(i=1;i<=n;i++)
	{
		ans[i] += ans[i-1];
		res += (long long)ans[i]*x[i];
	}
	printf("%lld\n",res);
	return 0;
}