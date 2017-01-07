#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char str[5005][5005];
int chk[5005];
int x[5005][5005];

void play1(int l,int r,int ii,int i,int j)
{
	while(l<r)
	{
		int mid = (l+r)/2 + 1;
		if(x[i][j] - x[ii-1][j] - x[i][mid-1] + x[ii-1][mid-1] == 0)
			l = mid;
		else
			r = mid-1;
	}
}

void play2(int l,int r,int ii,int i,int j)
{
	while(l<r)
	{
		int mid = (l+r)/2 + 1;
		if(x[i][j] - x[ii-1][j] - x[i][mid-1] + x[ii-1][mid-1] == 0)
			l = mid;
		else
			r = mid-1;
	}
}

int main()
{
	int i,j,r,c;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d %d",&r,&c);

	for(i=1;i<=r;i++)
		scanf(" %s",&str[i][1]);

	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			x[i][j] = x[i-1][j] + x[i][j-1] - x[i-1][j-1];
			if(str[i][j] == '1')
				x[i][j]++;
		}
	}

	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(str[i][j] == '1')
				chk[j]++;
			else chk[j] = 0;
		}
		for(j=1;j<=c;j++)
		{
			play1(1,j,i-chk[j]+1,i,j);
			play2(j,c,i-chk[j]+1,i,j);
		}
	}
	printf("%d\n",min(cnt+cnt2+1,cnt+2+1));
	return 0;
}