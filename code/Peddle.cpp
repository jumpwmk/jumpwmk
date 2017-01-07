#include <stdio.h>
#include <algorithm>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	long long mark,w;
};

int chk[100100]; //high
int parent[100010];
int mark[100100];
int LCA[100010][19];
int pow[19];
int cnt[100100];
int check[100100]; //group HLD
int nub[100010];
int m;
long long ans;
int a,b;
vector <int > v[100100];
pt segment[400400];

void play(int ii,int ago)
{
	int i,iii = -1,res = 0;
	parent[ii] = ago;

	chk[ii] = chk[ago] + 1;

	LCA[ii][0] = ago;
	for(i=1;i<18;i++)
	{
		LCA[ii][i] = LCA[LCA[ii][i-1]][i-1];
		if(LCA[ii][i] == 0)
			break;
	}

	for(i=0;i<v[ii].size();i++)
		if(v[ii][i] != ago)
			play(v[ii][i],ii);

	for(i=0;i<v[ii].size();i++)
	{
		cnt[ii] += cnt[v[ii][i]];
		if(v[ii][i] != ago && res < cnt[v[ii][i]])
		{
			res = cnt[v[ii][i]];
			iii = v[ii][i];
		}
	}
	if(iii == -1)
		cnt[ii] = 1;
	else
	{
		mark[iii] = 1;
		cnt[ii]++;
	}
	// printf("%d %d\n",ii,cnt[ii]);
}

void creat(int ii)
{
	int i;
	for(i=0;i<v[ii].size();i++)
	{
		if(v[ii][i] != parent[ii] && mark[v[ii][i]] == 1)
		{
			nub[v[ii][i]] = m++;
			check[v[ii][i]] = a;
			creat(v[ii][i]);
			break;
		}
	}
}

void sumka(int l,int r,int state)
{
	// printf("** %d %d %d\n",l,r,state);
	if(l == r)
	{
		ans += segment[state].w;
		return;
	}	
	if(l >= a && r <= b)
	{
		// if(segment[state].w > 0)
		// 	printf("&& %d %d\n",l,r);
		ans += segment[state].w;
		return;
	}
	int mid = (l+r)/2;
	if(segment[state].mark > 0)
	{
		segment[state*2].mark += segment[state].mark;
		segment[state*2].w += segment[state].mark*(mid-l+1);
		segment[state*2+1].mark += segment[state].mark;
		segment[state*2+1].w += segment[state].mark*(r-mid);
		segment[state].mark = 0;
	}
	if(mid >= a)
		sumka(l,mid,state*2);
	if(mid+1 <= b)
		sumka(mid+1,r,state*2+1);
	segment[state].w = segment[state*2].w + segment[state*2+1].w;
}

void sum(int ii,int tmp)
{
	while(check[ii] != check[tmp])
	{
		a = nub[check[ii]];
		b = nub[ii];
		// printf("=====  %d %d %d %d %d  ====\n",check[ii],ii,a,b,1);
		sumka(1,m-1,1);
		// printf("ans = %lld\n",ans);
		ii = check[ii];
		ii = parent[ii];
	}
	a = nub[tmp]+1;
	b = nub[ii];
	// printf("= %d %d %d %d %d\n",tmp,ii,a,b,1);
	sumka(1,m-1,1);
	// printf("ans = %lld\n",ans);
}

void findB(int ii,int jj)
{
	int i,j,res,tmp,k;
	if(chk[ii] < chk[jj])
		swap(ii,jj);
	res = chk[ii]-chk[jj];
	for(i=17;i>=0;i--)
	{
		if(pow[i] <= res)
		{
			res -= pow[i];
			tmp = LCA[ii][i];
			sum(ii,tmp);
			ii = tmp;
		}
	}
	k = 17;
	// printf("%d %d\n",ii,jj);
	while(ii != jj)
	{
		for(;k>0;k--)
		{
			if(LCA[ii][k] == LCA[jj][k] && LCA[ii][k-1] != LCA[jj][k-1])
			{
				tmp = LCA[ii][k-1];
				sum(ii,tmp);
				tmp = LCA[jj][k-1];
				sum(jj,tmp);
				ii = LCA[ii][k-1];
				jj = LCA[jj][k-1];
			}
		}
		if(ii != jj && k == 0)
		{
			tmp = LCA[ii][0];
			sum(ii,tmp);
			tmp = LCA[jj][0];
			sum(jj,tmp);
			ii = LCA[ii][0];
			jj = LCA[jj][0];
		}
	}
}

void inska(int l,int r,int state)
{
	// printf("%d %d %d %lld\n",l,r,state,segment[state].w);
	if(l == r)
	{
		segment[state].w++;
		return;
	}	
	if(l >= a && r <= b)
	{
		segment[state].mark++;
		segment[state].w += r-l+1;
		return;
	}
	int mid = (l+r)/2;
	if(segment[state].mark > 0)
	{
		segment[state*2].mark += segment[state].mark;
		segment[state*2].w += segment[state].mark*(mid-l+1);
		segment[state*2+1].mark += segment[state].mark;
		segment[state*2+1].w += segment[state].mark*(r-mid);
		segment[state].mark = 0;
	}
	if(mid >= a)
		inska(l,mid,state*2);
	if(mid+1 <= b)
		inska(mid+1,r,state*2+1);
	segment[state].w = segment[state*2].w + segment[state*2+1].w;
	// printf("== %d %d %d %lld\n",l,r,state,segment[state].w);
}

void ins(int ii,int tmp)
{
	// printf("%d %d %d %d\n",ii,tmp,check[ii],check[tmp]);
	while(check[ii] != check[tmp])
	{
		a = nub[check[ii]];
		b = nub[ii];
		// printf("+= %d %d\n",a,b);
		inska(1,m-1,1);
		ii = check[ii];
		ii = parent[ii];
	}
	// printf("=== %d %d\n",ii,tmp);
	if(ii == tmp)
		return;
	a = nub[tmp]+1;
	b = nub[ii];
	// printf("* %d %d\n",a,b);
	inska(1,m-1,1);
}

void findA(int ii,int jj)
{
	int i,j,res,tmp,k;
	if(chk[ii] < chk[jj])
		swap(ii,jj);
	res = chk[ii]-chk[jj];
	for(i=17;i>=0;i--)
	{
		if(pow[i] <= res)
		{
			res -= pow[i];
			tmp = LCA[ii][i];
			ins(ii,tmp);
			ii = tmp;
		}
	}
	k = 17;
	while(ii != jj)
	{
		for(;k>0;k--)
		{
			if(LCA[ii][k] == LCA[jj][k] && LCA[ii][k-1] != LCA[jj][k-1])
			{
				tmp = LCA[ii][k-1];
				ins(ii,tmp);
				tmp = LCA[jj][k-1];
				ins(jj,tmp);
				ii = LCA[ii][k-1];
				jj = LCA[jj][k-1];
			}
		}
		if(ii != jj && k == 0)
		{
			tmp = LCA[ii][0];
			ins(ii,tmp);
			tmp = LCA[jj][0];
			ins(jj,tmp);
			ii = LCA[ii][0];
			jj = LCA[jj][0];
		}
	}
}

void debug(int l,int r,int state)
{
	printf(" = %d %d %d %lld\n",l,r,state,segment[state].w);
	int mid = (l+r)/2;
	if(l == r)
		return;
	debug(l,mid,state*2);
	debug(mid+1,r,state*2+1);
}

int main()
{
	int i,j,q,n,s,e,ii,jj;
	char cmd;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&q);

	pow[0] = 1;
	for(i = 1;i<19;i++)
		pow[i] = pow[i-1] * 2;

	for(i=1;i<n;i++)
	{
		scanf("%d %d",&s,&e);
		v[s].push_back(e);
		v[e].push_back(s);
	}

	play(1,0);
	
	m = 1;
	for(i=1;i<=n;i++)
	{
		if(mark[i] == 0)
		{
			a = i;
			nub[i] = m++;
			check[i] = i;
			cnt[i] = a;
			creat(i);
		}
	}

	// for(i=1;i<=n;i++)
	// {
		// printf("%d %d\n",i,check[i]);
	// }

	while(q--)
	{
		scanf(" %c %d %d",&cmd,&ii,&jj);
		if(cmd == 'A')
		{
			findA(ii,jj);
			// printf("%d %d\n",ii,jj);
			// debug(1,m-1,1);
		}
		else
		{
			ans = 0;
			findB(ii,jj);
			printf("%lld\n",ans);
		}
	}
	return 0;
}