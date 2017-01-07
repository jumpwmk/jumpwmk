#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char x[10010];

int main()
{
	int n,x1,x2;
	bool check = false;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		scanf(" %s",x);
		scanf("%d %d",&x1,&x2);
		if(x1 >= 2400 && x2 > x1)
		{
			check = true;
		}
	}
	if(check)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}