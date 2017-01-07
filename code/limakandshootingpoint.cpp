#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

struct pt
{
	int x,y;
};

pt x[1010];
pt chk[10];
int mark[1010];

int main()
{
	int i,j,n,k;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d %d",&k,&n);
	for(i=1;i<=k;i++)
		scanf("%d %d",&chk[i].x,&chk[i].y);
	for(i=1;i<=n;i++)
		scanf("%d %d",&chk[i].x,&chk[i].y);
	for(i=1;i<=k;i++)
	{

	}
	return 0;
}