#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int ii,w;
	bool operator<(const pt &a)const
	{
		return w > a.w;
	}
};

long long fen[3][1000010];
pt x[1000010];
int n;

void update(int ii,int jj,long long w)
{
	while(jj <= n)
	{
		fen[ii][jj] += w;
		jj += (jj & -jj);
	}
}

long long sum(int ii,int jj)
{
	long long res = 0;
	while(jj > 0)
	{
		res += fen[ii][jj];
		jj -= (jj & -jj);
	}
	return res;
}

int main()
{
	int i,j;
	long long ans = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i].w);
		x[i].ii = i;
	}
	sort(x+1,x+n+1);
	for(i=1;i<=n;i++)
	{
		int ii = x[i].ii;
		// printf("%d %d\n",ii,x[i].w);
		update(1,ii,1);
		// printf(" %d \n",ii);

		long long res = sum(1,ii - 1);
		// printf("= %d %lld\n",2,res);
		update(2,ii,res);

		ans += sum(2,ii - 1);
	}
	printf("%lld\n",ans);
	return 0;
}