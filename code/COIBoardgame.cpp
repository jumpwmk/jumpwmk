#include <stdio.h>
#include <queue>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,j,state;
};

int mark[510][510][20];
int kk[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char str[510][510];
int chk[4] = {1,2,4};
int r,c;
queue <pt > q;
pt tmp;
pt x[4];

void solution()
{
	int i,j,k,state,cnt;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		i = tmp.i,j = tmp.j,state = tmp.state;
		// printf("%d %d %d\n",i,j,state);
		if(str[i][j] == 'E')
		{
			printf("%d\n",mark[i][j][state]);
			return;
		}
		cnt = mark[i][j][state];
		for(k=0;k<4;k++)
		{
			tmp.i = i+kk[k][0];
			tmp.j = j+kk[k][1];
			tmp.state = state;
			if(tmp.i < 0 || tmp.i >= r || tmp.j < 0 || tmp.j >= c)
				continue;
			if(str[tmp.i][tmp.j] == '#')
				continue;
			if(str[tmp.i][tmp.j] == 'j')
				tmp.state = tmp.state|1;
			if(str[tmp.i][tmp.j] == 'b')
				tmp.state = tmp.state|2;
			if(str[tmp.i][tmp.j] == 'p')
				tmp.state = tmp.state|4;
			if(str[tmp.i][tmp.j] == 'J' && (tmp.state&1) == 0)
				continue;
			if(str[tmp.i][tmp.j] == 'B' && (tmp.state&2) == 0)
				continue;
			if(str[tmp.i][tmp.j] == 'P' && (tmp.state&4) == 0)
				continue;
			if(mark[tmp.i][tmp.j][tmp.state] != -1)
				continue;
			mark[tmp.i][tmp.j][tmp.state] = cnt+1;
			q.push(tmp);
		}
	}
	printf("-1\n");
	return;
}

int main()
{
	int i,j;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
		scanf(" %s",str[i]);
	memset(mark,-1,sizeof(mark));
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(str[i][j] == 'S')
			{
				tmp.i = i,tmp.j = j,tmp.state = 0;
				mark[i][j][0] = 0;
				q.push(tmp);
			}
		}
	}
	solution();
	return 0;
}