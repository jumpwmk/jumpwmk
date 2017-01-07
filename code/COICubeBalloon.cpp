#include <stdio.h>
#include <queue>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int a,w,t;
	bool operator<(const pt &a)const
	{
		return t > a.t;
	}
};

long long x[100100];
int l[100100];
priority_queue <pt > q;
pt tmp;
long long sum;

int main()
{
	int n,m,i,j,cmd,a,b,t,w,aa,bb;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
		l[i] = 0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&cmd);
		while(!q.empty())
		{
			tmp = q.top();
			a = tmp.a,t = tmp.t,w = tmp.w;
			if(t > i)
				break;
			q.pop();
			if(t < i)
				continue;
			while(l[a] != 0)
				a = l[a];
			x[a] += (long long) w;
		}
		if(cmd == 1)
		{
			scanf("%d",&a);
			if(l[a] == 0)
				continue;
			aa = l[a];
			while(l[aa] > 0)
			{
				x[aa] -= x[a];
				aa = l[aa];
			}
			if(aa > 0)
				x[aa] -= x[a];
			l[a] = 0;
		}
		if(cmd == 2)
		{
			scanf("%d %d %d %d",&a,&b,&t,&w);
			tmp.t = t,tmp.w = w;
			aa = a,bb = b;
			while(l[aa] != 0)
				aa = l[aa];
			while(l[bb] != 0)
				bb = l[bb];
			if(a == bb)
				continue;
			aa = l[a];
			while(l[aa] > 0)
			{
				x[aa] -= x[a];
				aa = l[aa];
			}
			if(aa > 0)
				x[aa] -= x[a];
			x[bb] += x[a];
			l[a] = bb;
			tmp.a = a;
			q.push(tmp);
		}
		if(cmd == 3)
		{
			scanf("%d",&a);
			while(l[a] > 0)
				a = l[a];
			printf("%lld\n",x[a]);
		}
	}
	return 0;
}