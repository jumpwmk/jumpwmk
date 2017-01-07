#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

int r[11][11][100010];
int l[11][11][100010];

int main()
{
	int i,j,k,R,C,n,m,r1,r2,c1,c2;
	freopen("../10.in","r",stdin);
	freopen("../10.sol","w",stdout);
	scanf("%d %d %d %d",&R,&C,&n,&m);
	while(n--)
	{
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
		for(i=1;i<c1;i++)
		{
			for(j=c1;j<=c2;j++)
			{
				l[i][j][r1]++;
				r[i][j][r2]++;
			}
		}
		for(i=c1;i<=c2;i++)
		{
			for(j=i;j<=C;j++)
			{
				l[i][j][r1]++;
				r[i][j][r2]++;
			}
		}
	}
	for(i=1;i<=C;i++)
	{
		for(j=i;j<=C;j++)
		{
			for(k=1;k<=R;k++)
				r[i][j][k] += r[i][j][k-1];
			for(k=R;k>=1;k--)
				l[i][j][k] += l[i][j][k+1];
		}
	}
	while(m--)
	{
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
		printf("%d\n",r[c1][c2][R] - r[c1][c2][r1-1] - l[c1][c2][r2+1]);
	}
	return 0;
}