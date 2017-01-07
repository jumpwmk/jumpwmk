#include <stdio.h>
#include <algorithm>
#include <deque>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,w;
};

int x[101][10010];
int mic[10010];
pt tmp;
deque <pt > q;

int main()
{
	int r,c,i,j,k,res = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d %d",&r,&c,&k);

	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			scanf("%d ",&x[i][j]);
	
	for(i=1;i<=r;i++)
	{
		while(!q.empty())
			q.pop_front();
		for(j=1;j<=c;j++)
		{
			while(!q.empty() && x[i][j] >= q.back().w)
			{
				q.pop_back();
			}
			tmp.i = j;
			tmp.w = x[i][j];
			q.push_back(tmp);
			while(!q.empty() && j-q.front().i > k)
				q.pop_front();
			mic[j] = q.front().w;
		}
		while(!q.empty())
			q.pop_front();
		for(j=c;j>=1;j--)
		{
			while(!q.empty() && x[i][j] >= q.back().w)
			{
				q.pop_back();
			}
			tmp.i = j;
			tmp.w = x[i][j];
			q.push_back(tmp);
			while(!q.empty() && q.front().i - j > k)
				q.pop_front();
			mic[j] = mx(mic[j],q.front().w);
		}
		for(j=1;j<=c;j++)
		{
			x[i+1][j] += mic[j];
		}
	}
	for(j=1;j<=c;j++)
	{
		res = mx(res,x[r][j]);
	}
	printf("%d\n",res);
	return 0;
}