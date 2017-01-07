#include <stdio.h>
#include <vector>
#include <queue>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,w,state;
	bool operator<(const pt &a)const
	{
		if(w > a.w)
			return true;
		return false;
	}
};

priority_queue <pt > q;
vector <pt > v[100100];
pt tmp;

int mark[10010][2];

int main()
{
	int n,m,i,j,s,e,w,state;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d %d",&s,&e,&w);
		tmp.i = e,tmp.w = w;
		v[s].push_back(tmp);
		tmp.i = s;
		v[e].push_back(tmp);
	}
	for(i=1;i<=n;i++)
		mark[i][0] = mark[i][1] = INF;
	tmp.i = 1,tmp.state = 0,tmp.w = 0;
	q.push(tmp);
	mark[1][0] = 0;
	while(!q.empty())
	{
		tmp = q.top();
		i = tmp.i,w = tmp.w,state = tmp.state;
		q.pop();
		if(mark[i][state] < w)
			continue;
		if(i == n)
		{
			printf("%d.14\n",w);
			return 0;
		}
		mark[i][state] = -1;
		for(j=0;j<v[i].size();j++)
		{
			tmp.w = w + v[i][j].w;
			tmp.i = v[i][j].i;
			tmp.state = state;
			if(mark[tmp.i][tmp.state] > tmp.w)
			{
				mark[tmp.i][tmp.state] = tmp.w;
				q.push(tmp);
			}
			if(state == 0)
			{
				tmp.w = w;
				tmp.i = v[i][j].i;
				tmp.state = state + 1;
				if(mark[tmp.i][tmp.state] > tmp.w)
				{
					mark[tmp.i][tmp.state] = tmp.w;
					q.push(tmp);
				}
			}
		}
	}
	return 0;
}