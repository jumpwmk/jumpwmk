#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <map>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,w,fuel;
	bool operator<(const pt &a)const
	{
		if(w == a.w)
			return fuel > a.fuel;
		else return w > a.w;
	}
};

struct data
{
	int i,w;
};

vector <data > v[55];
map <string, int > ma;
string str[55];
int chk[55],n;
int x[55][110];
int st,en;
priority_queue <pt > q;
pt tmp;

void dijktra()
{
	int i,j;
	tmp.i = st,tmp.w = 0,tmp.fuel = chk[st];
	q.push(tmp);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=100;j++)
		{
			x[i][j] = INF;
		}
	}
	while(!q.empty())
	{
		tmp = q.top();
		q.pop();
		if(tmp.i == en)
		{
			while(!q.empty())
				q.pop();
			cout << tmp.w << "\n";
			return;
		}
		if(x[tmp.i][tmp.fuel] <= tmp.w)
			continue;
		// printf("%d %d %d\n",tmp.i,tmp.fuel,tmp.w);
		x[tmp.i][tmp.fuel] = tmp.w;
		int ii = tmp.i,w = tmp.w,fuel = tmp.fuel;
		for(i = 0;i<v[ii].size();i++)
		{
			tmp.i = v[ii][i].i;
			tmp.w = w + v[ii][i].w;
			if(fuel < v[ii][i].w)
				continue;
			tmp.fuel = fuel + chk[tmp.i] - v[ii][i].w;
			// printf("-- %d %d %d\n",tmp.i,tmp.w,tmp.fuel);
			if(tmp.fuel > 100)
				tmp.fuel = 100;
			if(tmp.w < x[tmp.i][tmp.fuel])
				q.push(tmp);
		}
	}
	printf("Impossible\n");
}

int main()
{
		freopen("../test.in","r",stdin);
		freopen("../test.out","w",stdout);
	int i,t,m,w;
	cin >> t;
	string tmp1,tmp2;
	while(t--)
	{
		cin >> n;
		for(i=0;i<n;i++)
		{
			cin >> str[i] >> chk[i];
			if(str[i] == "start")
				st = i;
			if(str[i] == "end")
				en = i;
			ma[str[i]] = i;
		}
		cin >> m;
		for(i=0;i<m;i++)
		{
			cin >> tmp1 >> tmp2 >> w;
			data d;
			d.i = ma[tmp2];
			d.w = w;
			v[ma[tmp1]].push_back(d);
			d.i = ma[tmp1];
			v[ma[tmp2]].push_back(d);
		}
		dijktra();
		for(i=0;i<n;i++)
			v[i].clear();
		for(i=0;i<n;i++)
			ma[str[i]] = 0;
	}
	return 0;
}