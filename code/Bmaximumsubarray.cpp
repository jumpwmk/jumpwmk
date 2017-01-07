#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char str[5005][5005];
int chk[5005];
int srt[5005];

int main()
{
	int i,j,r,c,ans = 0,tmp1,tmp2;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&r,&c);

	for(i=1;i<=r;i++)
		scanf(" %s",&str[i][1]);

	for(j=1;j<=c;j++)
	{
		for(i=1;i<=r;i++)
		{
			if(str[i][j] == '1')
				chk[i]++;
			else chk[i] = 0;
			srt[i] = chk[i];
		}
		sort(srt+1,srt+r+1);
		for(i=1;i<=r;i++)
		{
			// printf("%d ",srt[i]);
			ans = mx(ans,srt[i]*(r-i+1));
		}
		// printf("\n");
	}
	printf("%d\n",ans);
	return 0;
}