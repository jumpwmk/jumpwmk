#include <stdio.h>
#include <math.h>
#include <set>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int w,i;
	bool operator<(const pt &a)const
	{
		if(w == a.w)
			return i < a.i;
		return w < a.w;
	}
};

set <pt > s;
int x[200100];
int ans[200100];
int chk[200100];
set <pt >::iterator it;
pt tmp;

int main()
{
	int i,j,n;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(i=1;i<=n;i++)
		ans[i] = INF;
	ans[1] = 0;
	ans[x[1]] = min(ans[1]+1,ans[x[1]]);
	tmp.i = x[1],tmp.w = x[1] + 1;
	s.insert(tmp);
	for(i=2;i<=n;i++)
	{
		while(!s.empty())
		{
			it = s.begin();
			tmp = *it;
			if(tmp.i >= i)
				break;
			s.erase(it);
		}
		if(!s.empty())
		{
			it = s.begin();
			// printf("%d %d %d\n",i,it->i,it->w);
			ans[i] = min(it -> w - i,ans[i-1]+1);
		}
		else
			ans[i] = ans[i-1] + 1;

		ans[x[i]] = min(ans[x[i]],ans[i]+1);
		tmp.i = x[i],tmp.w = x[i] + ans[x[i]];
		s.insert(tmp);
		// printf("%d %d\n",tmp.i,tmp.w);
	}
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}