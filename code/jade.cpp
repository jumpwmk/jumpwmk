#include <stdio.h>
#include <queue>
#define INF 1000000000

using namespace std;

struct pt
{
	int ii,jj,kk,t;
};

int x[31][31][31][4001];
int chk[31][31][31];
char str[31][31][31];
int kk[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
queue <pt > q;
pt tmp;

pt add(int ii, int jj, int kk, int t)
{
	pt tmp;
	tmp.ii = ii, tmp.jj = jj, tmp.kk = kk, tmp.t = t;
	return tmp;
}

int main()
{
	int i,j,k,r,c,n,t,cnta = 0,cntb = 0;
	freopen("../10.in","r",stdin);
	// freopen("../6.sol","w",stdout);
	scanf("%d %d %d",&r,&c,&n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < r; j++)
		{
			scanf(" %s",str[i][j]);
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < r; j++)
		{
			for(k = 0; k < c; k++)
			{
				if(str[i][j][k] == '#')
					cnta++;
				if(str[i][j][k] == 'o')
					cntb++;
			}
		}
	}
	for(int loop = 0; loop < cnta; loop++)
	{
		scanf("%d %d %d %d",&i,&j,&k,&t);
		i--,j--,k--;
		chk[i][j][k] = t;
	}
	for(int loop = 0; loop < cntb; loop++)
	{
		scanf("%d %d %d %d",&i,&j,&k,&t);
		// printf("%d %d %d %d\n",i,j,k,t);
		i--,j--,k--;
		chk[i][j][k] = t;
	}
	tmp = add(0,0,0,0);
	q.push(tmp);
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		if(t >= 4000)
			break;
		i = tmp.ii, j = tmp.jj, k = tmp.kk, t = tmp.t;
		if(i == n - 1 and j == r - 1 and k == c - 1)
		{
			printf("%d\n",tmp.t);
			return 0;
		}
		if(str[i][j][k] == '#' and t % chk[i][j][k])
		{
			continue;
		}
		// printf("%d %d %d %d\n",i,j,k,t);
		for(int loop = 0; loop < 4; loop++)
		{
			tmp.ii = i, tmp.jj = j + kk[loop][0], tmp.kk = k + kk[loop][1], tmp.t = t + 1;
			if(tmp.jj < 0 or tmp.jj >= r or tmp.kk < 0 or tmp.kk >= c or x[tmp.ii][tmp.jj][tmp.kk][tmp.t])
				continue;
			q.push(tmp);
			x[tmp.ii][tmp.jj][tmp.kk][tmp.t] = 1;
		}
		if(str[i][j][k] == 'o')
		{
			tmp.ii = i + chk[i][j][k], tmp.jj = j, tmp.kk = k, tmp.t = t + 1;
			// printf("%d %d\n",i,chk[i][j][k]);
			if(tmp.ii >= 0 and tmp.ii < n and x[tmp.ii][tmp.jj][tmp.kk][tmp.t] == 0)
			{
				x[tmp.ii][tmp.jj][tmp.kk][tmp.t] = 1;
				q.push(tmp);
			}
		}
	}
	printf("-1\n");
	return 0;
}