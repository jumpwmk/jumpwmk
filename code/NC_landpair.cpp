#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

int x[52][52];
int mic[5000010];
int tmp[52][52];
int count[5000010];

int main()
{
	int i,j,ii,jj,n,m = 0;
	int cnt = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x[i][j]);
			tmp[i][j] = x[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			x[i][j] += x[i][j-1] + x[i-1][j] - x[i-1][j-1];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			// printf("%d %d\n",i,j);
			m++;
			for(ii = 1;ii<i;ii++)
			{
				for(jj=1;jj<j;jj++)
				{
					if(mic[x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1] + 2500000] == m)
						count[x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1] + 2500000]++;
					else
						count[x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1] + 2500000] = 1;
					mic[x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1] + 2500000] = m;
					// printf("= %d %d %d %d %d\n",ii,jj,i-1,j-1,x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1]);
				}
			}
			for(ii = i;ii<=n;ii++)
			{
				for(jj=j;jj<=n;jj++)
				{
					if( mic[x[ii][jj]-x[i-1][jj]-x[ii][j-1]+x[i-1][j-1] + 2500000] == m)
					{
						// printf("%d %d %d %d %d\n",i,j,ii,jj,x[ii][jj]-x[i-1][jj]-x[ii][j-1]+x[i-1][j-1]);
						cnt+= count[x[ii][jj]-x[i-1][jj]-x[ii][j-1]+x[i-1][j-1] + 2500000];
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			x[i][j] = tmp[i][n-j+1];
			x[i][j] += x[i-1][j] + x[i][j-1] - x[i-1][j-1];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			// printf("%d %d\n",i,j);
			m++;
			for(ii = 1;ii<i;ii++)
			{
				for(jj=1;jj<j;jj++)
				{
					if(mic[x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1] + 2500000] == m)
						count[x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1] + 2500000]++;
					else
						count[x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1] + 2500000] = 1;
					mic[x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1] + 2500000] = m;
					// printf("= %d %d %d %d %d\n",ii,jj,i-1,j-1,x[i-1][j-1]-x[ii-1][j-1]-x[i-1][jj-1]+x[ii-1][jj-1]);
				}
			}
			for(ii = i;ii<=n;ii++)
			{
				for(jj=j;jj<=n;jj++)
				{
					if( mic[x[ii][jj]-x[i-1][jj]-x[ii][j-1]+x[i-1][j-1] + 2500000] == m)
					{
						// printf("%d %d %d %d %d\n",i,j,ii,jj,x[ii][jj]-x[i-1][jj]-x[ii][j-1]+x[i-1][j-1]);
						cnt+= count[x[ii][jj]-x[i-1][jj]-x[ii][j-1]+x[i-1][j-1] + 2500000];
					}
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}