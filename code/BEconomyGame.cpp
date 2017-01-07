#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	int res = 0,n,i,j;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<=n;i+=1234567)
	{
		for(j=0;i+j<=n;j+=123456)
		{
			if((n-i-j)%1234 == 0)
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}