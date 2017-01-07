#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

int mic[1000010];
int x[11];
int chk[11];

int main()
{
	int i,j,m,p,k,tmp,ii,res;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d %d",&p,&m,&k);
	for(i=0;i<=m;i++)
	{
		mic[i] = INF;
	}
	mic[0] = 0;
	for(j=1;j<=k;j++)
	{
		scanf("%d",&tmp);
		x[j] = tmp;
		for(i=tmp;i<=m;i++)
		{
			mic[i] = mn(mic[i],mic[i-tmp]+1);
		}
	}
	res = INF;
	for(i=p;i<=m;i++)
	{
		if(res > mic[i] + mic[i-p])
		{
			res = mic[i]+mic[i-p];
			ii = i;
		}
	}
	printf("%d %d\n",mic[ii],mic[ii-p]);
	i = ii,j = k;
	while(i > 0)
	{
		if(i - x[j] >= 0 && mic[i-x[j]]+1 == mic[i])
		{
			chk[j]++;
			i -= x[j];
		}
		else
			j--;
	}
	for(i=1;i<=k;i++)
		printf("%d ",chk[i]);
	printf("\n");
	memset(chk,0,sizeof(chk));
	i = ii - p,j = k;
	while(i > 0)
	{
		if(i - x[j] >= 0 && mic[i-x[j]]+1 == mic[i])
		{
			chk[j]++;
			i -= x[j];
		}
		else
			j--;
	}
	for(i=1;i<=k;i++)
		printf("%d ",chk[i]);
	printf("\n");
	return 0;
}