#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <queue>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int ii,jj,kk,t;
};

pt add(int ii,int jj,int kk,int t)
{
	pt tmp;
	tmp.ii = ii, tmp.jj = jj, tmp.kk = kk, tmp.t = t;
	return tmp;
}


int main()
{
	int i,j,k,tmp, t = 100000, n = 30, r = 30, c = 30;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../1.in","w",stdout);
	printf("%d %d %d\n",r,c,n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < r; j++)
		{
			for(k = 0; k < c; k++)
			{
				int tmp = rand()%20;
				if(tmp == 0)
				{

				}
				if(tmp % 2 == 0)
				{
					printf("")
				}
			}
		}
	}
	return 0;
}