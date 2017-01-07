#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int x,y;
};

pt x[15010];
int chk[15010];

int checkpath(int i,int j)
{
	return abs(x[i].x - x[j].x) + abs(x[i].y - x[j].y);
}

int main()
{
	int n,i,j,res,ii;
	int ans = 0;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x[i].x,&x[i].y);
	}
	for(i=0;i<n;i++)
		chk[i] = INF;
	chk[0] = -1;
	for(i=0;i<n;i++)
		chk[i] = min(chk[i],checkpath(i,0));
	// for(i=0;i<n;i++)
	// 	printf("%d %d\n",i,chk[i]);
	for(i=0;i<n-1;i++)
	{
		res = INF,ii = 0;
		for(j=0;j<n;j++)
		{
			if(chk[j] >= 0 && chk[j] < res)
				res = chk[j],ii = j;
		}
		// printf("%d %d %d\n",ii,chk[ii],res);
		ans += chk[ii];
		chk[ii] = -1;
		for(j=0;j<n;j++)
			chk[j] = min(chk[j],checkpath(j,ii));
	}
	printf("%d\n",ans);
	return 0;
}