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
	int n = 600,s = 30000,e = 1;
	printf("%d\n",n);
	for(int i=1;i<n;i++)
	{
		printf("%d %d\n",rand()%i,i);
	}
	printf("%d %d\n",s,e);
	for (int i = 0; i < s; ++i)
	{
		// if(rand()%2)
		// 	printf("1\n");
		// else 
			printf("0 %d %d\n",rand()%n,rand()%n);
	}
	printf("1\n");
	return 0;
}