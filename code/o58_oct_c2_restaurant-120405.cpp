#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[330][330];
int mark[330][330];

int main()
{
	int n,t,i,j,k;
	// freopen("../20.in","r",stdin);
	// freopen("../20.sol","w",stdout);
	scanf("%d %d",&n,&t);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(i == k || j == k)
					continue;
				if(x[i][j] == x[i][k]+x[k][j])
					break;
			}
			if(k == n+1)
			{
				mark[i][++mark[i][0]] = j;
				mark[j][++mark[j][0]] = i;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(mark[i][0] >= 3)
		{
			printf("%d\n",i);
			if(t == 2)
				printf("%d\n",mark[i][0]);
		}
	}

	return 0;
}