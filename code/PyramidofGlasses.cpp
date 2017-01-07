#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[11][11];

void play(int i,int j,int w)
{
	int tmp;
	if(i > 10)
		return;
	x[i][j] += w;
	if(x[i][j] > 512)
	{
		tmp = x[i][j] - 512;
		tmp/=2;
		play(i+1,j,tmp);
		play(i+1,j+1,tmp);
		x[i][j] = 512;
	}
}

int main()
{
	int n,t,i,j,cnt = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&t);
	for(i=0;i<t;i++)
	{
		play(1,1,512);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(x[i][j] == 512)
			{
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}