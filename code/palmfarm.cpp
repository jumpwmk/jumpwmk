#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

int mic[2][110][2011];
int x[110][110];

int main()
{
	int i,j,k,r,c,tmp2,tmp7,chk;
	freopen("../10.in","r",stdin);
	freopen("../10.sol","w",stdout);
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	for(j=0;j<=c;j++)
	{
		for(k=0;k<=2000;k++)
		{
			mic[0][j][k] = -INF;
		}
	}
	mic[0][1][0] = 0;
	for(i=1;i<=r;i++)
	{
		for(j=0;j<=c;j++)
		{
			for(k=0;k<=2000;k++)
			{
				mic[i%2][j][k] = -INF;
			}
		}
		for(j=1;j<=c;j++)
		{
			tmp2 = tmp7 = 0;
			while(x[i][j] > 0 && x[i][j] % 2 == 0)
			{
				tmp2++;
				x[i][j] /= 2;
			}
			while(x[i][j] > 0 && x[i][j] % 7 == 0)
			{
				tmp7++;
				x[i][j] /= 7;
			}
			for(k=0;k<=2000;k++)
			{
				chk = mx(0,k-tmp7);
				if((mx(mic[i%2][j-1][chk],mic[(i+1)%2][j][chk])) < 0)
					break;
				// printf("%d %d %d %d %d\n",i,j,k,mic[i%2][j-1][k-tmp7],mic[(i+1)%2][j][k-tmp7]);
				mic[i%2][j][k] = ((mx(mic[i%2][j-1][chk],mic[(i+1)%2][j][chk])) + tmp2);
				if(mic[i%2][j][k] < 0)
					mic[i%2][j][k] = -INF;
			}
		}
	}
	int res = -INF;
	for(k=0;k<=2000;k++)
	{
		// printf("%d %d\n",mic[r%2][c][k],k);
		res = mx(res,(mn(mic[r%2][c][k],k)));
	}
	printf("%d\n",res);
	return 0;
}