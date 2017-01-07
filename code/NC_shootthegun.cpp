#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	long long i;
	int w;
};

struct data
{
	long long x,y;
};

pt mic[1000100];
long long check[1000000];
int chk[1010][1010];
data x[1010];

int main()
{
	int n,i,j,ii,m;
	int res = INF,cnt = 0;
	long long tmp,ans;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld",&x[i].x,&x[i].y);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		while(m--)
		{
			scanf("%lld",&tmp);
			if(chk[i][tmp] == 1 && i == 1)
				printf("88\n");
			chk[i][tmp] = 1;
		}
	}
	printf("%d\n",cnt);
	m = 0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(chk[i][j] == 1)
			{
				check[m++] = (x[i].x - x[j].x)*(x[i].x - x[j].x) + (x[i].y - x[j].y)*(x[i].y - x[j].y);
			}
			else
			{
				check[m++] = (x[i].x - x[j].x)*(x[i].x - x[j].x) + (x[i].y - x[j].y)*(x[i].y - x[j].y);
			}
		}
	}
	check[m++] = 0;
	sort(check,check+m);
	m = unique(check,check+m) - check;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			tmp = (x[i].x - x[j].x)*(x[i].x - x[j].x) + (x[i].y - x[j].y)*(x[i].y - x[j].y);
			ii = lower_bound(check,check+m,tmp) - check;
			if(chk[i][j] == 1)
			{
				mic[ii].i = tmp;
				if(tmp > 0)
					cnt++;
				mic[ii].w -= 1;
				mic[0].w += 1;
			}
			else
			{	
				mic[ii].i = tmp;
				mic[ii].w += 1;
			}
		}
	}
	printf("%d\n",cnt);
	bool ch = false;
	res = mic[0].w,ans = 0;
	printf("%d\n",mic[0].w);
	for(i=1;i<m;i++)
	{
		printf("%lld %d\n",mic[i].i,mic[i].w);
		mic[i].w += mic[i-1].w;
		if(mic[i].w < res)
		{
			res = mic[i].w;
			ans = mic[i].i;
		}
	}
	printf("%lld %d\n",ans,res);
	return 0;
}