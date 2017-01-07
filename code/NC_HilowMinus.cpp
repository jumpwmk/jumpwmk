#include <stdio.h>
#include <deque>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,w;
};

int x[1000010];
deque <pt > q;
pt tmp;

int main()
{
	int i,j,n,m,chk;
	int ans;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	m = n-m;
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	for(i=2;i<=m;i++)
	{
		chk = x[i]-x[i-1];
		// printf("%d %d\n",x[i],x[i-1]);
		while(!q.empty() && chk <= q.back().w)
		{
			q.pop_back();
		}
		tmp.i = i-1;
		tmp.w = chk;
		q.push_back(tmp);
	}
	ans = q.front().w + x[m] - x[1];
	// printf("%d %d %d %d\n",ans,x[m],x[1],q.front().w);
	for(i=m+1,j=2;i<=n;i++,j++)
	{
		chk = x[i]-x[i-1];
		while(!q.empty() && chk <= q.back().w)
		{
			q.pop_back();
		}
		tmp.i = i-1;
		tmp.w = chk;
		q.push_back(tmp);
		while(q.front().i < j)
			q.pop_front();
		ans = mn(q.front().w + x[i] - x[j],ans);
	}
	printf("%d\n",ans);

	return 0;
}