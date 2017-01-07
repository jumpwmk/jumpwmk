#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000
#define p 312343335553
#define mod 5000

using namespace std;

struct pt
{
	long long x,y;
};

pt x[1100];
int chk[1100][1100];
queue <int > q;

int main()
{
	int i,j,n = 1000,m;
	long long tmp;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../20.in","w",stdout);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		x[i].x = rand()%1000001;
		x[i].y = rand()%1000001;
		printf("%lld %lld\n",x[i].x,x[i].y);
	}
	for(i=0;i<n;i++)
	{
		m = 0;
		for(j=0;j<n;j++)
		{
			tmp = (x[i].x-x[j].x)*(x[i].x-x[j].x) + (x[i].y-x[j].y)*(x[i].y-x[j].y);
			if(tmp <= p)
			{
				if(rand()%mod)
				{
					m++;
					q.push(j+1);
				}
			}
			else
			{
				if(rand()%mod == 0)
				{
					m++;
					q.push(j+1);
				}
			}
		}
		printf("%d ",m);
		while(!q.empty())
		{
			printf("%d ",q.front());
			q.pop();
		}
		printf("\n");
	}
	return 0;
}