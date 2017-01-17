#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	for(int i = 0; i < 10; i += 2)
		printf("%d\n",i);
	return 0;
}