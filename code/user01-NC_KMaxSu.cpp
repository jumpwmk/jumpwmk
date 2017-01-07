#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct pii
{
	long long x;
	int pos;
	bool operator < (const pii &a) const{
		if (x < a.x) return false;
		else return true;
	}
};
priority_queue <pii> q;
long long a[100010];

int main()
{
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	int n,Q,l,r,k;
	long long MAX=0,sum=0;
	scanf("%d",&Q);
	while (Q--)
	{	
		while (!q.empty())
			q.pop();
		MAX = 0;
		scanf("%d%d",&n,&k);
		for( int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for (int i=1;i<=n;i++)
			a[i] += a[i-1];
		// for (int i=1;i<=n;i++)
		// 	printf("%d ",a[i] );
		pii tmp;
		tmp.x = a[1];
		tmp.pos = 1;
		q.push(tmp);
		for (int i=2;i<=n;i++)
		{
			tmp.x = a[i];
			tmp.pos = i;
			q.push(tmp);
			while (!q.empty() && q.top().pos < i-k)
				q.pop();
			//printf("TOP %d , NOW %d , %d\n",q.top().x , a[i],a[i]-q.top().x );
			MAX = max(MAX,(long long)(a[i]-q.top().x));
			printf("%lld , %lld %lld\n",q.top().x , a[i],a[i]-q.top().x );
		}
		printf("%lld\n",max(MAX,a[1]) );
	}
	return 0;
}