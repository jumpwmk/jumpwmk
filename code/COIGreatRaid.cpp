#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,j,w;
	bool operator<(const pt &a)const
	{
		return w < a.w;
	}
};

int x[100100];
int head[100100];
pt data[1000100];

int findhead(int ii)
{
	int tmp = ii,ha;
	while(ii != head[ii])
		ii = head[ii];
	ha = ii;
	ii = tmp;
	while(ii != head[ii])
	{
		tmp = ii;
		ii = head[ii];
		head[tmp] = ha;
	}
	return ha;
}

int main()
{
	int n,e,i,j,ii,jj,w;
	long long sum = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&data[i].i,&data[i].j);
		data[i].w = x[data[i].i]+x[data[i].j];
	}
	sort(data,data+e);
	for(i=1;i<=n;i++)
		head[i] = i;
	for(i=0;i<e;i++)
	{
		ii = data[i].i,jj = data[i].j,w = data[i].w;
		int ha = findhead(ii),hb = findhead(jj);
		if(ha == hb)
			continue;
		// printf("%d\n",w);
		head[ha] = hb;
		sum += (long long)w;
	}
	printf("%lld\n",sum);
	return 0;
}