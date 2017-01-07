#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,w;
	bool operator<(const pt &a)const
	{
		if(i == a.i)
			return w < a.w;
		return i < a.i;
	}
};

pt x[200010];
pt tmp;

int main()
{
	int n,s,e,m = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&s,&e);
		x[m].i = s,x[m++].w = 1;
		x[m].i = e+1,x[m++].w = -1;
	}
	int i;
	sort(x,x+m);
	s = x[0].w;
	for(i=1;i<m;i++)
	{
		x[i].w += x[i-1].w;
		// printf("%d %d\n",x[i].i,x[i].w);
		s = mx(x[i].w,s);
	}
	printf("%d\n",s);
	return 0;
}