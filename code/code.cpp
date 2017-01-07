#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

double x[220];
double res = 0;

void check(int i,int j)
{
	double tmp;
	tmp = x[i]*(1.000000-x[j]) + x[j]*(1.0000000-x[i]);
	// printf("%d %d %lf\n",i,j,x[i]*(1.000000-x[j]));
	res = mx(res,tmp);
}

int main()
{
	int i,j,n,m,t;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%lf",&x[i]);
		if(m == 0)
		{
			printf("0.000000\n");
			continue;
		}
		check(1,2);
		check(1,3);
		check(2,3);
		printf("%lf\n",res);
	}
	return 0;
}