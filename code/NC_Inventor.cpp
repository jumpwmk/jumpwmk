#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int s,t,i;
	bool operator<(const pt &a)const
	{
		if(t*a.s == a.t*s)
			return i < a.i;
		return t*a.s < a.t*s;
	}
};

pt x[1010];

int main()
{
	int i,n;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i].t,&x[i].s);
		x[i].i = i;
	}
	sort(x+1,x+n+1);
	for(i=1;i<=n;i++)
	{
		printf("%d ",x[i].i);
	}
	printf("\n");
	return 0;
}