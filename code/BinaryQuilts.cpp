#include <stdio.h>
#include <queue>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int state[1 << 25];
int x[6][6];
char str[2][6][6];
int chk[6][6];
int st = 0;
int en = 0;
queue <int > q;

void display(int tmp)
{
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			if(tmp & chk[i][j])
				printf("X");
			else printf(".");
		}
		printf("\n");
	}
	printf("\n");
}

void breadth()
{
	int i,j,kk,k,l,tmp,tmp1;
	q.push(st);
	state[st] = 1;
	// memset(state , 0 ,sizeof(state));
	while(!q.empty())
	{
		if(q.front() == en)
			break;
		tmp = q.front();
		// display(tmp);
		q.pop();
		for(kk = 1;kk<=5;kk++)
		{
			for(i=0;i<5-kk+1;i++)
			{
				for(j=0;j<5-kk+1;j++)
				{
					tmp1 = tmp;
					for(k = 0;k < kk;k++)
					{
						for(l = 0;l < kk;l++)
						{
							tmp1 = tmp1 ^ chk[i+k][j+l];
						}
					}
					// display(tmp1);
					if(state[tmp1] == 0)
					{
						state[tmp1] = state[tmp] + 1;
						q.push(tmp1);
					}
				}
			}			
		}
		// // vertical
		for(kk = 2;kk<=5;kk++)
		{
			for(i=0;i<5-kk+1;i++)
			{
				for(j=0;j<5-kk+1;j++)
				{
					tmp1 = tmp;
					for(k = 0;k < kk/2;k++)
					{
						for(l = 0;l < kk;l++)
						{
							if(tmp & chk[i+k][j+l])
							{
								tmp1 = tmp1 | chk[ i + kk - k - 1 ][j+l];
							}
							else
							{
								if(tmp & chk[i+kk-k-1][j+l])
									tmp1 = tmp1 ^ chk[ i + kk - k - 1 ][j+l];
							}

							if(tmp & chk[i + kk - k -1][j+l])
							{
								tmp1 = tmp1 | chk[ i + k ][j+l];
							}
							else
							{
								if(tmp & chk[ i + k ][ j + l ])
									tmp1 = tmp1 ^ chk[ i + k ][j+l];
							}
						}
					}
					// display(tmp1);
					if(state[tmp1] == 0)
					{
						state[tmp1] = state[tmp] + 1;
						q.push(tmp1);
					}
				}
			}			
		}

		// // ------
		for(kk = 2;kk<=5;kk++)
		{
			for(i=0;i<5-kk+1;i++)
			{
				for(j=0;j<5-kk+1;j++)
				{
					tmp1 = tmp;
					for(k = 0;k < kk;k++)
					{
						for(l = 0;l < kk/2;l++)
						{
							if(tmp & chk[i+k][j+kk - l - 1])
							{
								tmp1 = tmp1 | chk[ i + k ][j+l];
							}
							else
							{
								if(tmp & chk[i+k][j+l])
									tmp1 = tmp1 ^ chk[ i + k ][j+l];
							}

							if(tmp & chk[i + k][ j + l ])
							{
								tmp1 = tmp1 | chk[i+k][j+kk-l-1];
							}
							else
							{
								if(tmp & chk[ i + k ][j+kk-l-1])
									tmp1 = tmp1 ^ chk[ i + k ][j+kk-l-1];
							}
						}
					}
					// display(tmp1);
					if(state[tmp1] == 0)
					{
						state[tmp1] = state[tmp] + 1;
						q.push(tmp1);
					}
				}
			}			
		}
	}
	printf("%d\n",state[en]);
	while(!q.empty())
		q.pop();

}

int main()
{
	int i,j,t;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<5;i++)
		{
			scanf(" %s %s",str[0][i],str[1][i]);
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				chk[i][j] = 1 << (i*5+j);
			}
		}
		st = 0;
		en = 0;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(str[0][i][j] == 'X')
					st += chk[i][j];
				if(str[1][i][j] == 'X')
					en += chk[i][j];
			}
		}
		breadth();
	}
	return 0;
}