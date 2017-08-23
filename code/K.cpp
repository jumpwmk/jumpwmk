#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[110][110];

int main()
{
	int r, c, i, j, n, aa, bb, cc, dd, ans = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d %d",&r,&c,&n);
	while(n--)
	{
		scanf("%d %d %d %d",&aa,&bb,&cc,&dd);
		aa++,bb++,cc++,dd++;
		x[aa][bb]++;
		x[aa][dd + 1]--;
		x[cc + 1][bb]--;
		x[cc + 1][dd + 1]++;
	}
	for(i = 1; i <= r; i++)
	{
		for(j = 1; j <= c; j++)
		{
			x[i][j] += x[i-1][j] + x[i][j-1] - x[i-1][j-1];
			if(x[i][j] > 0)
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}