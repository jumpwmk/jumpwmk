#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int mic[110][3];
int x[110];

int main()
{
	int n,i,j;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=1;i<=n;i++)
	{
		mic[i][0] = mic[i][1] = mic[i][2] = INF;
		if(x[i] == 1 || x[i] == 3)
		{
			mic[i][1] = min(mic[i][1],(min(mic[i-1][0],mic[i-1][2])));
		}
		if(x[i] == 2 || x[i] == 3)
		{
			mic[i][2] = min(mic[i][2],(min(mic[i-1][0],mic[i-1][1])));
		}
		mic[i][0] = (min(mic[i-1][0],min(mic[i-1][1],mic[i-1][2]))) + 1;
	}
	printf("%d\n",min(mic[n][0],(min(mic[n][1],mic[n][2]))));
	return 0;
}