#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <deque>
#define INF 1000000000

using namespace std;

struct pt
{
	int x,y;
};

bool cmpx(pt a,pt b)
{
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

struct data
{
	int ii,y;
};

data tmp;
deque <data > mx,mn;
pt x[100100];

int main()
{
	int i,j,q,n,h,ans = INF;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&q);
	while(q--)
	{
		ans = INF;
		while(!mx.empty())
			mx.pop_back();
		while(!mn.empty())
			mn.pop_back();
		scanf("%d %d",&n,&h);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x[i].x,&x[i].y);
		}
		sort(x,x+n,cmpx);
		int l = 0,r = 1;
		tmp.ii = 0,tmp.y = x[0].y;
		mx.push_back(tmp);
		mn.push_back(tmp);
		while(r <= n)
		{
			// printf("- %d %d %d %d\n",l,r,mx.front().y,mn.front().y);
			if(mx.front().y - mn.front().y >= h)
			{
				ans = min(ans,x[r-1].x - x[l].x);
				// printf("%d %d\n",x[r-1].x,x[l].x);
				l++;
				while(mx.front().ii < l)
				{
					mx.pop_front();
				}
				while(mn.front().ii < l)
				{
					mn.pop_front();
				}
			}
			else
			{
				if(r == n)
					break;
				tmp.ii = r;
				tmp.y = x[r++].y;
				while(!mx.empty() && mx.back().y <= tmp.y)
				{
					mx.pop_back();
				}
				mx.push_back(tmp);
				while(!mn.empty() && mn.back().y >= tmp.y)
				{
					mn.pop_back();
				}
				mn.push_back(tmp);
			}
		}
		if(ans == INF)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}