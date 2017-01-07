#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define mod 1000000

using namespace std;

void solution(int n,int m)
{
	int i;
	printf("%d %d\n",n,m);
	for(i=0;i<n;i++)
	{
		printf("%d\n",rand()%mod);
	}
}

int main()
{
	int t = 5,n,m;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../10.in","w",stdout);
	printf("%d\n",t);
	solution(5000,30);
	solution(5000,60);
	solution(5000,37);
	solution(5000,7);
	solution(5000,100);
	return 0;
}