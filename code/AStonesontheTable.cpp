#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char x[55];
int cnt;

int main()
{
	int i,n;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	scanf(" %s",x);
	for(i=1;i<n;i++)
	{
		if(x[i] == x[i-1])
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}