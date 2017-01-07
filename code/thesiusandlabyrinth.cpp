#include <stdio.h>
#include <algorithm>
#include <queue>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,j,state;
};

int chk[500];
int change[12];
int mark[1010][1010][4];
int kk[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int check[12][4] = {{0,0,0,0},{1,1,1,1},{0,1,0,1},{1,0,1,0},{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},{1,1,1,0},{1,0,1,1},{0,1,1,1},{1,1,0,1}};
char str[1010][1010];
int x[1010][1010][4];
queue <pt > q;
int r,c;

void initial()
{
	chk['*'] = 0;
	chk['+'] = 1;
	chk['-'] = 2;
	chk['|'] = 3;
	chk['^'] = 4;
	chk['>'] = 5;
	chk['v'] = 6;
	chk['<'] = 7;
	chk['L'] = 8;
	chk['R'] = 9;
	chk['U'] = 10;
	chk['D'] = 11;
	change[0] = 0;
	change[1] = 1;
	change[2] = 3;
	change[3] = 2;
	change[4] = 5;
	change[5] = 6;
	change[6] = 7;
	change[7] = 4;
	change[8] = 10;
	change[9] = 11;
	change[10] = 9;
	change[11] = 8;
}

void solution()
{
	int ii,jj,w,state;
	int i,j,k;
	pt tmp;
	scanf("%d %d",&tmp.i,&tmp.j);
	tmp.i--,tmp.j--;
	tmp.state = 0;
	mark[tmp.i][tmp.j][tmp.state] = 0;
	q.push(tmp);
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		ii = tmp.i,jj = tmp.j,state = tmp.state,w = mark[ii][jj][state];
		// printf("%d %d %d %d %d\n",ii,jj,state,w,x[ii][jj][state]);
		for(k=0;k<4;k++)
		{
			tmp.i = ii + kk[k][0],tmp.j = jj + kk[k][1],tmp.state = state;
			if(tmp.i >= 0 && tmp.i < r && tmp.j >= 0 && tmp.j < c && check[x[ii][jj][state]][k] == 1 && check[x[tmp.i][tmp.j][tmp.state]][(k+2)%4] && mark[tmp.i][tmp.j][tmp.state] == -1)
			{
				q.push(tmp);
				mark[tmp.i][tmp.j][tmp.state] = w + 1;
			}
		}
		tmp.i = ii,tmp.j = jj,tmp.state = (state+1)%4;
		if(mark[tmp.i][tmp.j][tmp.state] == -1)
		{
			mark[tmp.i][tmp.j][tmp.state] = w + 1;
			q.push(tmp);
		}
	}
	scanf("%d %d",&ii,&jj);
	ii--,jj--;
	printf("%d\n",min((min(mark[ii][jj][0],mark[ii][jj][1])),(min(mark[ii][jj][2],mark[ii][jj][3]))));
}

int main()
{
	int i,j;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
		scanf("%s",str[i]);
	initial();
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			x[i][j][0] = chk[str[i][j]];
		}
	}
	for(int k=0;k<3;k++)
	{
		for(int i = 0;i<r;i++)
		{
			for(int j = 0;j<c;j++)
			{
				x[i][j][k+1] = change[x[i][j][k]];
			}
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			for(int k=0;k<4;k++)
				mark[i][j][k] = -1;
		}
	}
	solution();
	return 0;
}