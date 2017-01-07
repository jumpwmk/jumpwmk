#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../test.in","w",stdout);
	printf("%d\n",1000);
	for(int i=1;i<=1000;i++)
	{
		printf("%d\n",rand()%1000);
	}
	return 0;
}