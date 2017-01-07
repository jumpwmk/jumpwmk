#include <stdio.h>
#include <stdlib.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

int x[100100];
int mic[100100][2];

int main()
{
	int i,j,n,t,tmp;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&x[1]);
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x[i]);
			tmp = x[i]-x[i-1];
			if(tmp < 0)
				tmp *= -1;
			mic[i][0] = mx(mic[i-1][0],mic[i-1][1] + x[i-1] - 1);
			mic[i][1] = mx(mic[i-1][0]+x[i]-1,mic[i-1][1] + tmp);
		}
		// for(i=1;i<=n;i++)
		// 	printf("%d %d\n",mic[i][0],mic[i][1]);
		printf("%d\n",mx(mic[n][0],mic[n][1]));
	}
	return 0;
}