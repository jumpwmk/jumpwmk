#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int mic[1010][1010][11];
char x[1010],y[1010];

int main()
{
	int i,j,k,lenx,leny,n,res = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d %d %s %s",&lenx,&leny,&n,&x[1],&y[1]);
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=lenx;i++)
		{
			for(j=1;j<=leny;j++)
			{
				if(x[i] == y[j])
				{
					mic[i][j][k] = (max(mic[i-1][j-1][k-1],mic[i-1][j-1][k])) + 1;
					res = max(res,mic[i][j][k]);
				}
				else
				{
					mic[i][j][k] = max(mic[i-1][j][k-1],mic[i][j-1][k-1]);
				}
			}
		}
		for(i=1;i<=lenx;i++)
		{
			for(j=1;j<=leny;j++)
			{
				mic[i][j][k] = max(mic[i][j][k],(max(mic[i-1][j][k],mic[i][j-1][k])));
			}
		}
	}
	printf("%d\n",res);
	return 0;
}