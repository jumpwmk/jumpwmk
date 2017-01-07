#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[110];

int main()
{
	int i,j,n,s,e;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		if(x[i] == 1)
			s = i;
		if(x[i] == n)
			e = i;
	}
	if(s > e)
		swap(s,e);
	printf("%d\n",max(n-s,e-1));
	return 0;
}