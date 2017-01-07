#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,w;
};

vector <pt > v[200200];
pt tmp;
long long x[200200];
vector <int > chk[200200];
vector <int > ans[200200];
int cnt[200200];
int head[200200];
int state[200200];
int tmpp[200020];
int LCA[200100][20];
int LCA2[200100][20];
int pw[20];
long long res[200200];

void play(int ii,long long sum)
{
	int i,j;
	for(i = 1;i < 20;i++)
	{
		LCA[ii][i] = LCA[LCA[ii][i-1]][i-1];
		LCA2[ii][i] = LCA[LCA[ii][i-1]][i-1];
	}
	for(i=0;i<v[ii].size();i++)
	{
		LCA[v[ii][i].i][0] = ii;
		res[v[ii][i].i] = sum + v[ii][i].w;
		play(v[ii][i].i,res[v[ii][i].i]);
		cnt[ii] += cnt[v[ii][i].i];
	}
	cnt[ii]++;
}

void play2(int ii)
{
	int i,j,mx = 0,jj = 0;
	for(i=0;i<v[ii].size();i++)
	{
		if(mx < cnt[v[ii][i].i])
		{
			mx = cnt[v[ii][i].i];
			j = v[ii][i].i;
		}
	}
	for(i=0;i<v[ii].size();i++)
	{
		if(j == v[ii][i].i)
		{
			LCA2[v[ii][i].i][0] = ii;
			head[j] = head[ii];
			state[j] = state[ii] + 1;
			chk[head[j]].push_back(v[ii][i].i);
			ans[head[j]].push_back(0);
		}
		else
		{
			tmpp[v[ii][i].i] = ii;
			chk[v[ii][i].i].push_back(v[ii][i].i);
			ans[v[ii][i].i].push_back(0);
			ans[v[ii][i].i].push_back(0);
			state[v[ii][i].i] = 0;
			head[v[ii][i].i] = v[ii][i].i;
		}
		play2(v[ii][i].i);
	}
}

int main()
{
	int i,j,n,a,b;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	pw[0] = 1;
	tmpp[1] = 0;
	chk[1].push_back(1);
	ans[1].push_back(0);
	ans[1].push_back(0);
	state[1] = 0;
	head[1] = 1;
	for(i=1;i<20;i++)
		pw[i] = pw[i-1] * 2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&x[i]);
	for(i=2;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		tmp.i = i;
		tmp.w = b;
		v[a].push_back(tmp);
	}
	play(1,0);
	play2(1);
	// for(i=1;i<=n;i++)
	// {
	// 	printf("%d %d\n",i,head[i]);
	// }
	for(i = 1;i <= n;i++)
	{
		// printf("=== %d\n",i);
		int l = 0,r = n;
		while(l < r)
		{
			// printf("= = %d %d\n",l,r);
			int mid = (l+r)/2 + 1;
			int chk = mid;
			int ii = i;
			for(j = 19;j >= 0; j--)
			{
				if(pw[j] <= chk)
				{
					ii = LCA[ii][j];
					chk -= pw[j];
				}
			}
			// printf("%d %d %lld %lld\n",mid,ii,res[i],res[ii]);
			if(res[i] - res[ii] <= x[i])
			{
				l = mid;
			}
			else
			{
				r = mid-1;
			}
		}
		int chk = l;
		int ii = i;
		for(j = 19;j >= 0; j--)
		{
			if(pw[j] <= chk)
			{
				chk -= pw[j];
				ii = LCA[ii][j];
			}
		}
		if(ii == 0)
			ii = 1;
		int mid = l;
		int jj = i;
		// printf("-- %d %d\n",ii,jj);
		while(jj > 0)
		{
			// printf(" %d & %d %d\n",jj,head[jj],head[ii]);
			if(head[jj] != head[ii])
			{
				ans[head[jj]][0]++;
				ans[head[jj]][state[jj]+1]--;
				jj = tmpp[head[jj]];
				// printf("%d\n",jj);
			}
			else
			{
				ans[head[ii]][state[ii]]++;
				ans[head[ii]][state[jj]+1]--;
				break;
			}
		}
	}
	memset(state,0,sizeof(state));
	for(int i=1;i<=n;i++)
	{
		for(j=0;j<(int)chk[i].size();j++)
		{
			if(j > 0)
				ans[i][j] += ans[i][j-1];
			state[chk[i][j]] = ans[i][j];
		}
		// printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",state[i]-1);
	}
	printf("\n");
	return 0;
}