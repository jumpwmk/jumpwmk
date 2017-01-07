#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int mark[10][10][100];
char str[10][10];
int n = 8;
int m;
int check[6] = {1,2,4,8,16,32};
int kk[8][2] = {{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{0,1},{0,-1},{-1,0}};
int chk[10][10];

struct pt
{
	int i,j,state;	
};

queue <pt > q;
pt tmp;

void Debug(int i,int j,int state,int ii,int jj,int state2)
{
	// if(i == 1 && j == 4 && state == 15)
	// {
	// 	printf("%d %d %d\n",i,j,state);
	// 	// printf("%d %d %d %d %d %d\n",i,j,state,ii,jj,state2);
	// }
	// if(i == 5 && j == 0 && state == 15)
	// {
	// 	printf("%d %d %d\n",i,j,state);
	// 	// printf("%d %d %d %d %d %d\n",i,j,state,ii,jj,state2);
	// }
	// if(i == 2 && j == 3 && state == 11)
	// {
	// 	printf("%d %d %d\n",i,j,state);
	// 	// printf("%d %d %d %d %d %d\n",i,j,state,ii,jj,state2);
	// }
	// if(i == 5 && j == 6 && state == 10)
	// {
	// 	printf("%d %d %d\n",i,j,state);
	// 	// printf("%d %d %d %d %d %d\n",i,j,state,ii,jj,state2);
	// }
	// if(i == 3 && j == 6 && state == 2)
	// {
	// 	printf("%d %d %d\n",i,j,state);
	// 	// printf("%d %d %d %d %d %d\n",i,j,state,ii,jj,state2);
	// }
	// if(i == 2 && j == 5 && state == 2)
	// {
	// 	printf("%d %d %d\n",i,j,state);
	// }
}

void solution()
{
	int i,j,k,ii,state,w;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		i = tmp.i,j = tmp.j,state = tmp.state,w = mark[i][j][state];
		// if(i == 2&& j == 5 &&w == 1)
		// 	printf("%d %d %d %d\n",i,j,state,w); 
		// if(i == 2 && j == 3 && w == 2)
		// 	printf("%d %d %d %d\n",i,j,state,w); 
		// if(i == 5 && j == 0 && w == 3 && state == 7)
		// 	printf("%d %d %d %d\n",i,j,state,w); 
		// if(i == 2 && j == 3 && w == 4 && state == 7)
		// 	printf("%d %d %d %d\n",i,j,state,w); 
		// if(i == 5 && j == 6 && w == 5 && state == 15)
		// 	printf("%d %d %d %d\n",i,j,state,w); 
		if(str[i][j] == 'k')
		{
			printf("%d\n",w);
			while(!q.empty())
				q.pop();
			return;
		}
		for(k=0;k<8;k++)
		{
			for(ii=0;;ii++)
			{
				tmp.i = i + kk[k][0]*ii;
				tmp.j = j + kk[k][1]*ii;
				if(tmp.i < 0 || tmp.i >= 8 || tmp.j < 0 || tmp.j >= 8 || str[tmp.i][tmp.j] == 'X' || str[tmp.i][tmp.j] == 'K')
					break;
				tmp.state = state;
				// if(i == 5 && j == 0 && state == 7 && w == 3)
				// 	printf("== %d %d %d %d\n",tmp.i,tmp.j,tmp.state,w);
				if(chk[tmp.i][tmp.j] == 5)
				{
					if(tmp.state == 15)
					{
						// printf("%d %d %d\n",i,j,state);
						tmp.state += 16;
						printf("%d\n",w+1);
						while(!q.empty())
							q.pop();
						return;
					}
					else break;
				}
				if(chk[tmp.i][tmp.j] > 0)
				{
					if((tmp.state&check[chk[tmp.i][tmp.j]-1]) == 0)
					{
						tmp.state = tmp.state|check[chk[tmp.i][tmp.j]-1];
						if(mark[tmp.i][tmp.j][tmp.state] == -1)
						{
							Debug(tmp.i,tmp.j,tmp.state,i,j,state);
							q.push(tmp);
							mark[tmp.i][tmp.j][tmp.state] = w+1;
							break;
						}
						else
						{	
							break;
						}
					}
					else
					{
						if(mark[tmp.i][tmp.j][tmp.state] == -1)
						{
							Debug(tmp.i,tmp.j,tmp.state,i,j,state);
							q.push(tmp);
							mark[tmp.i][tmp.j][tmp.state] = w+1;
						}
						continue;
					}
				}
				if(mark[tmp.i][tmp.j][tmp.state] == -1)
				{
					Debug(tmp.i,tmp.j,tmp.state,i,j,state);
					q.push(tmp);
					mark[tmp.i][tmp.j][tmp.state] = w+1;
				}	
			}
		}
	}
	printf("-1\n");
	return;
}

int main()
{
	int t,i,j;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		m = 0;
		memset(mark,-1,sizeof(mark));
		memset(chk,0,sizeof(chk));
		for(i=0;i<n;i++)
			scanf(" %s",str[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(str[i][j] == 'Q')
				{
					tmp.i = i,tmp.j = j,tmp.state = 0;
					mark[i][j][0] = 0;
					str[i][j] = '.';
					q.push(tmp);
				}
				if(str[i][j] == 'x')
				{
					chk[i][j] = ++m;
				}
				if(str[i][j] == 'k')
				{
					chk[i][j] = 5;
				}
			}
		}
		solution();
	}
	return 0;
}