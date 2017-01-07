#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[1010][1010];

int main()
{
	int i,j,r,c;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	int cnt = 0 ;
	for(i=0;i<r;i++)
	{
		int tmp = 0;
		for(j=0;j<c;j++)
		{
			if(tmp == 1 && x[i][j] == 0)
				cnt++;
			if(x[i][j] == 1)
				tmp = 1;
		}
	}
	for(i=0;i<r;i++)
	{
		int tmp = 0;
		for(j=c-1;j>=0;j--)
		{
			if(tmp == 1 && x[i][j] == 0)
				cnt++;
			if(x[i][j] == 1)
				tmp = 1;
		}
	}
	for(j=0;j<c;j++)
	{
		int tmp = 0;
		for(i=0;i<r;i++)
		{
			if(tmp == 1 && x[i][j] == 0)
				cnt++;
			if(x[i][j] == 1)
				tmp = 1;
		}
	}
	for(j=0;j<c;j++)
	{
		int tmp = 0;
		for(i=r-1;i>=0;i--)
		{
			if(tmp == 1 && x[i][j] == 0)
				cnt++;
			if(x[i][j] == 1)
				tmp = 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}