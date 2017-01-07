#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int n = 40000,m = 10000,w = 100000,k = 10;

int main()
{
	int i,j,ii,jj;
	srand(time(NULL));
	// freopen("../test.in","r",stdin);
	// freopen("../10.in","w",stdout);
	printf("%d %d %d\n",n,m,k);
	while(n--)
	{
		i = rand()%w;
		j = rand()%w;
		ii = rand()%w;
		jj = rand()%w;
		if(i > ii)
			swap(i,ii);
		if(j > jj)
			swap(j,jj);
		printf("%d %d %d %d\n",i,j,ii,jj);
	}
	while(m--)
	{
		i = rand()%w;
		j = rand()%(k+1);
		if(rand()%2 == 0)
			j = i-j;
		else
			j = i+j;
		if(j < 0)
			j = 0;
		if(j >= w)
			j = w-1;
		if(i < 0 || i >= w || j < 0 || j >= w)
			while(1);
		printf("%d %d\n",i,j);
	}
	return 0;
}