#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char x[330][330];
int kk[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int r,c,state,K;
int chk[330][330][4];
int mark[330][330];
bool ans = false;

void play(int i,int j)
{
	state++;
	mark[i][j] = 1;
	if(state == K)
	{
		ans = true;
		printf("%d %d\n",i,j);
		return;
	}
	for(int k = 0;k < 4;k++)
	{
		int ii,jj;
		ii = i + kk[k][0];
		jj = j + kk[k][1];
		if(ii < 1 || ii > r || jj < 1 || jj > c || x[ii][jj] == '#')
		{
			if(chk[ii][jj][k] == 0)
			{
				chk[ii][jj][k] = 1;
				state++;
				if(state == K)
				{
					printf("%d %d\n",i,j);
					ans = true;
					return;
				}
			}
			continue;
		}
	}
	// printf("%d %d %d\n",i,j,state);
	for(int k = 0;k < 4;k++)
	{
		int ii,jj;
		ii = i + kk[k][0];
		jj = j + kk[k][1];

		if(state >= K)
		{
			return;
		}
		if(ii < 1 || ii > r || jj < 1 || jj > c || x[ii][jj] == '#' || mark[ii][jj])
		{
			continue;
		}
		play(ii,jj);
	}
}

int main()
{
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	int i,j,s,t,q;
	scanf("%d",&q);
	while(q--)
	{
		memset(chk,0,sizeof(chk));
		memset(mark,0,sizeof(mark));
		scanf("%d %d %d",&r,&c,&K);
		for(i=1;i<=r;i++)
			scanf(" %s",&x[i][1]);
		scanf("%d %d",&s,&t);
		state = -1;
		ans = false;
		play(s,t);
		if(ans == false)
		{
			printf("no solution\n");
		}
	}
	return 0;
}