#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,j,w,state;
	bool operator <(const pt &a)const
	{
		if(w == a.w)
			return i < a.i;
		return w < a.w;
	}
};

int x[100100];
int head[100100];
int chk[100100];
long long res = 0,mm;
pt e[100100];
vector <int > ans;
vector <pt > vc[100100];
vector <pt > v[100100];
queue <pt > q,q2;
pt tmp;

void play(int ii,int ago)
{
	int i;
	for(i=0;i<vc[ii].size();i++)
	{
		if(vc[ii][i].i != ago)
		{
			play(vc[ii][i].i,ii);
		}
	}
	x[ii] = 0;
	for(i=0;i<vc[ii].size();i++)
	{
		if(vc[ii][i].i != ago)
		{
			if(res < (long long)(mm-x[vc[ii][i].i])*(long long)x[vc[ii][i].i])
			{
				ans.clear();
				ans.push_back(vc[ii][i].state);
				res = (long long)(mm-x[vc[ii][i].i])*(long long)x[vc[ii][i].i];
			}
			else if(res == (long long)(mm-x[vc[ii][i].i])*(long long)x[vc[ii][i].i])
			{
				ans.push_back(vc[ii][i].state);
			}
			x[ii] += x[vc[ii][i].i];
		}
	}
	x[ii] += chk[ii];
}

int findhead(int ii)
{
	int ha,tmp = ii;
	while(ii != head[ii])
		ii = head[ii];
	ha = ii, ii = tmp;
	while(ii != head[ii])
	{
		tmp = ii;
		ii = head[ii];
		head[tmp] = ha;
	}
	return ha;
}

void solution()
{
	mm = 0;
	while(!q.empty())
	{
		q2.push(q.front());
		tmp = q.front();
		q.pop();
		// printf("= %d %d %d\n= %d %d %d\n",tmp.i,chk[tmp.i],vc[tmp.i].empty(),tmp.j,chk[tmp.j],vc[tmp.j].empty());
		// printf("[%d] %d\n",tmp.j,vc[tmp.j].size());
		if(vc[tmp.j].empty())
		{
			// printf("*\n");
			mm += chk[tmp.j];
		}
		vc[tmp.j].push_back(tmp);
		swap(tmp.i,tmp.j);
		// printf("[%d] %d\n",tmp.j,vc[tmp.j].size());
		if(vc[tmp.j].empty())
		{
			// printf("*\n");
			mm += chk[tmp.j];
		}
		vc[tmp.j].push_back(tmp);
	}
	// printf("%lld\n",mm);
	play(tmp.i,-1);
	while(!q2.empty())
	{
		tmp = q2.front();
		q2.pop();
		// printf("--- %d %d\n",tmp.i,tmp.j);
		vc[tmp.i].clear();
		vc[tmp.j].clear();
		tmp.i = findhead(tmp.i);
		tmp.j = findhead(tmp.j);
		head[tmp.j] = tmp.i;
		chk[tmp.i] += chk[tmp.j]; 
	}
}

int main()
{
	int n,m;
	int i,j,cmd;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		head[i] = i;
	for(i=0;i<m;i++)
	{
		scanf("%d",&cmd);
		chk[cmd] = 1;
	}
	m = 1;
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d %d",&tmp.j,&tmp.i,&tmp.w);
		tmp.state = i;
		v[tmp.j].push_back(tmp);
		swap(tmp.j,tmp.i);
		v[tmp.j].push_back(tmp);
		e[m++] = tmp;
	}
	sort(e+1,e+m);
	for(i=1;i<m;i++)
	{
		if(e[i].w == e[i-1].w)
		{
			tmp = e[i];
			tmp.i = findhead(tmp.i);
			tmp.j = findhead(tmp.j);
			// printf("%d %d\n",tmp.i,tmp.j);
			q.push(tmp);
		}
		else
		{
			// printf("------\n");
			solution();
			tmp = e[i];
			tmp.i = findhead(tmp.i);
			tmp.j = findhead(tmp.j);
			q.push(tmp);
		}
	}
	// printf("------\n");
	solution();
	printf("%lu %lld\n",ans.size(),res);
	for(i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}