#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	int t,n;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n = (n*2)-1;
		// printf("%d %d %d\n",(n+1)/2,1,n);
		n = ((n+1)/2*(1+n))/2;
		printf("%d\n",n);
	}
	return 0;
}