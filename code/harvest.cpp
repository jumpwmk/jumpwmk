#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	long long w,mark;
};

vector<int > v[80100];
pt seg[400100];
long long mod = 1000000009;
int ch[80010];
int chkstate[80010];
int headinheavy[80010];
int sum[80100];
int lca[80100][25],pw[25];
int parentlight[80100];
int posinsegment[80100];
int childheavy[80100];
int n,m,a,b;

void play(int ii,int ago)
{
	lca[ii][0] = ago;
	for (int i = 1; i < 20; ++i)
	{
		if(lca[ii][i-1] == -1)
			break;
		lca[ii][i] = lca[lca[ii][i-1]][i-1];
	}
	for (int i = 0; i < v[ii].size(); ++i)
	{
		if(v[ii][i] != ago)
		{
			chkstate[v[ii][i]] = chkstate[ii] + 1;
			play(v[ii][i],ii);
		}
	}
}

void creathld(int ii,int ago)
{
	for (int i = 0; i < v[ii].size(); ++i)
	{
		if(v[ii][i] != ago)
		{
			creathld(v[ii][i],ii);
		}
	}
	int chk = 0,child = -1;
	sum[ii]++;
	for (int i = 0; i < v[ii].size(); ++i)
	{
		if(v[ii][i] != ago)
		{
			sum[ii] += sum[v[ii][i]];
			if(chk < sum[v[ii][i]])
			{
				chk = sum[v[ii][i]];
				child = v[ii][i];
			}
		}
	}
	childheavy[ii] = child;
	for (int i = 0; i < v[ii].size(); ++i)
	{
		if(child != v[ii][i] && v[ii][i] != ago)
		{
			parentlight[v[ii][i]] = ii;
		}
	}
}

void chkposinsegment(int ii,int head)
{
	posinsegment[ii] = m++;
	headinheavy[ii] = head;
	if(childheavy[ii] != -1)
		chkposinsegment(childheavy[ii],head);
}

void update(int l,int r,int state)
{
	if(l == r)
	{
		seg[state].w *= 2;
		seg[state].mark *= 2;
		seg[state].w %= mod;
		seg[state].mark %= mod;
		return;
	}
	if(l >= a && r <= b)
	{
		seg[state].w *= 2;
		seg[state].mark *= 2;
		seg[state].w %= mod;
		seg[state].mark %= mod;
		return;
	}
	if(seg[state].mark != 1)
	{
		seg[state*2].mark *= seg[state].mark;
		seg[state*2].w *= seg[state].mark;
		seg[state*2].mark %= mod;
		seg[state*2].w %= mod;
		seg[state*2 + 1].mark *= seg[state].mark;
		seg[state*2 + 1].w *= seg[state].mark;
		seg[state*2 + 1].mark %= mod;
		seg[state*2 + 1].w %= mod;
		seg[state].mark = 1;
	}
	int mid = (l+r)/2;
	if(mid >= a)
		update(l,mid,state*2);
	if(mid+1 <= b)
		update(mid+1,r,state*2+1);
	seg[state].w = (seg[state*2].w + seg[state*2+1].w)%mod;
}

void findlca(int ii,int jj)
{
	while(headinheavy[ii] != headinheavy[jj])
	{
		if(chkstate[headinheavy[ii]] <= chkstate[headinheavy[jj]])
		{
			a = posinsegment[headinheavy[jj]],b = posinsegment[jj];
			update(0,n-1,1);
			jj = parentlight[headinheavy[jj]];
		}
		else
		{
			a = posinsegment[headinheavy[ii]],b = posinsegment[ii];
			update(0,n-1,1);
			ii = parentlight[headinheavy[ii]];
		}
	}
	if(chkstate[ii] <= chkstate[jj])
	{
		a = posinsegment[ii],b = posinsegment[jj];
		update(0,n-1,1);
	}
	else
	{
		a = posinsegment[jj],b = posinsegment[ii];
		update(0,n-1,1);
	}
}

void init(int l,int r,int state)
{
	seg[state].mark = 1;
	if(l == r)
	{
		seg[state].w = 1;
		seg[state].mark = 1;
		ch[l] = state;
		return;
	}
	int mid = (l+r)/2;
	init(l,mid,state*2);
	init(mid+1,r,state*2+1);
	seg[state].w = seg[state*2].w + seg[state*2+1].w;
}

int main()
{
	int i,j,s,e;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	pw[0] = 1;
	memset(lca,-1,sizeof(lca));
	memset(parentlight,-1,sizeof(parentlight));
	memset(posinsegment,-1,sizeof(posinsegment));
	init(0,n-1,1);
	for (int i = 1; i < 20; ++i)
	{
		pw[i] = pw[i-1]*2;
	}
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d",&s,&e);
		v[s].push_back(e);
		v[e].push_back(s);
	}
	play(0,-1);
	creathld(0,-1);
	m = 0;
	for (int i = 0; i < n; ++i)
		if(posinsegment[i] == -1)
			chkposinsegment(i,i);
	scanf("%d %d",&s,&e);
	m = s+e;
	int cmd;
	while(m--)
	{
		scanf("%d",&cmd);
		if(cmd == 1)
		{
			printf("%lld\n",seg[1].w);
		}
		else
		{
			scanf("%d %d",&s,&e);
			findlca(s,e);
		}
	}
	return 0;
}