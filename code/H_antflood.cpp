#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

struct pt
{
	int ii,w,h,wi;
	bool operator<(const pt &a)const
	{
		if(wi == a.wi)
			return w > a.w;
		return wi > a.wi;
	}	
};

struct ans
{
	int w, wi;
};

vector <pt > v[100100];
bool check[100010];
priority_queue <pt > q;
ans x[100010];
pt tmp;

int main()
{
	int n, m, s, t, i, j, ii, jj, w, h, wi, maxd = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d %d",&s,&t);
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d %d",&ii,&jj,&w,&h);
		maxd = max(maxd, h);
		tmp.ii = ii, tmp.w = w, tmp.h = h, tmp.wi = 0;
		v[jj].push_back(tmp);
		tmp.ii = jj;
		v[ii].push_back(tmp);
	}

	for(int d = 0; d <= maxd; d++)
	{
		for(i = 0; i < n; i++)
			x[i].w = INF, x[i].wi = INF, check[i] = false;
		tmp.ii = s, tmp.w = 0, tmp.wi = 0;
		q.push(tmp);
		x[s].w = 0, x[s].wi = 0;
		while(!q.empty())
		{
			tmp = q.top();
			q.pop();
			// printf("%d %d %d %d\n",tmp.ii,tmp.h, tmp.wi, tmp.w);
			ii = tmp.ii, w = tmp.w, wi = tmp.wi;
			if(ii == t)
			{
				printf("%d %d %d\n", d, tmp.wi, tmp.w);
				return 0;
			}
			if(check[ii] == true)
				continue;
			check[ii] = true;
			for(i = 0; i < v[ii].size(); i++)
			{
				if(v[ii][i].h > d)
					continue;
				tmp.ii = v[ii][i].ii;
				tmp.w = w + v[ii][i].w;
				tmp.wi = wi + (v[ii][i].h > 0 ? v[ii][i].w:0);

				if(x[tmp.ii].wi > tmp.wi)
				{
					x[tmp.ii].wi = tmp.wi;
					x[tmp.ii].w = tmp.w;
					q.push(tmp);
				}
				else if(x[tmp.ii].wi == tmp.wi and x[tmp.ii].w > tmp.w)
				{
					x[tmp.ii].wi = tmp.wi;
					x[tmp.ii].w = tmp.w;
					q.push(tmp);
				}
			}
		}
	}

	return 0;
}