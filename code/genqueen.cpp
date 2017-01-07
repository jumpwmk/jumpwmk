#include <stdio.h>
#include <ctime>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char str[10][10];
int mark[10][10];
int kk[8][2] = {{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{0,1},{0,-1},{-1,0}};

struct pt
{
	int i,j;
};

queue <pt > q;

bool solution()
{
	pt tmp;
	int i,j,k,w;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(str[i][j] == 'Q')
				tmp.i = i,tmp.j = j,mark[i][j] = 1,q.push(tmp);
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		i = tmp.i,j = tmp.j;
		for(k=0;k<8;k++)
		{
			tmp.i = i + kk[k][0];
			tmp.j = j + kk[k][1];
			if(tmp.i < 0 || tmp.i >= 8 || tmp.j < 0 || tmp.j >= 8 || str[tmp.i][tmp.j] == 'X')
				continue; 
			if(mark[tmp.i][tmp.j] == -1)
			{
				mark[tmp.i][tmp.j] = 1;
				q.push(tmp);
			}
		}
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(str[i][j] == 'x' && mark[i][j] == -1)
				return false;
		}
	}
	return true;
}

int main()
{
	int t = 10,i,j,tmp;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../15.in","w",stdout);
	printf("%d\n",t);
	while(t > 0)
	{
		memset(mark,-1,sizeof(mark));
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				str[i][j] = '.';
		i = rand()%8,j = rand()%8;
		str[i][j] = 'Q';
		while(1)
		{
			i = rand()%8,j = rand()%8;
			if(str[i][j] == '.')
			{
				str[i][j] = 'K';
				break;
			}
		}
		while(1)
		{
			i = rand()%8,j = rand()%8;
			if(str[i][j] == '.')
			{
				str[i][j] = 'k';
				break;
			}
		}
		while(1)
		{
			i = rand()%8,j = rand()%8;
			if(str[i][j] == '.')
			{
				str[i][j] = 'x';
				break;
			}
		}
		while(1)
		{
			i = rand()%8,j = rand()%8;
			if(str[i][j] == '.')
			{
				str[i][j] = 'x';
				break;
			}
		}
		while(1)
		{
			i = rand()%8,j = rand()%8;
			if(str[i][j] == '.')
			{
				str[i][j] = 'x';
				break;
			}
		}
		while(1)
		{
			i = rand()%8,j = rand()%8;
			if(str[i][j] == '.')
			{
				str[i][j] = 'x';
				break;
			}
		}
		tmp = rand()%10;
		while(tmp--)
		{
			while(1)
			{
				i = rand()%8,j = rand()%8;
				if(str[i][j] == '.')
				{
					str[i][j] = 'X';
					break;
				}
			}
		}
		if(solution() == true)
		{
			t--;
			for(i=0;i<8;i++)
			{
				for(j=0;j<8;j++)
					printf("%c",str[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}