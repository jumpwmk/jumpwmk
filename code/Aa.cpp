#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	int n;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	if(n == 0)
	{
		printf("1\n");
		return 0;
	}
	n--;
	if(n%4 == 0)
		printf("8\n");
	else if(n%4 == 1)
		printf("4\n");
	else if(n%4 == 2)
		printf("2\n");
	else printf("6\n");
	return 0;
}