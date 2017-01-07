#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	long long c,v;
	bool operator<(const pt &a)const
	{
		if(c == a.c)
			return v > a.v;
		return c < a.c;
	}
};

pt x[200200];
long long data[200200];
long long k,s,t;

bool cmp(pt a,pt b)
{
	if(a.v > b.v)
		return true;
	return false;
}

bool solution(long long ii)
{
	long long i;
	long long v = x[ii].v;
	long long x,y;
	long long cnt = 0ll;
	// printf("----- %lld\n",v);
	for(i = 0; i < k; i++)
	{
		long long c = data[i] - (i > 0 ? data[i-1]:0);
		if(c > v)
		{
			return false;
		}
		if(2*c <= v)
		{
			cnt += (long long)c;
			continue;
		}
		x = v - c;
		y = 2*c - v;
		cnt += (long long)x + 2ll * y;
	}
	long long c = s - (i > 0 ? data[i-1]:0);
	if(c > v)
	{
		// printf("%lld %lld\n",c,v);
		return false;
	}
	if(2*c <= v)
	{
		cnt += (long long)c;
	}
	else
	{
		x = v - c;
		y = 2*c - v;
		cnt += (long long)x + 2ll * y;
	}
	// if(ii == 1)
	// 	printf("%lld\n",cnt);
	if(cnt <= (long long)t)
		return true;
	else return false;
}

int main()
{
	long long i,j,n;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%lld %lld %lld %lld",&n,&k,&s,&t);
	for(i = 0; i < n; i++)
	{
		scanf("%lld %lld",&x[i].c,&x[i].v);
	}
	for(i = 0; i < k; i++)
	{
		scanf("%lld",&data[i]);
	}
	sort(data,data+k);
	sort(x,x+n);
	n = unique(x,x+n,cmp) - x;
	long long l = 0, r = n-1;
	while(l < r)
	{
		long long mid = (l+r)/2;
		if(solution(mid))
			r = mid;
		else l = mid+1;
	}
	if(solution(l))
		printf("%lld\n",x[l].c);
	else printf("-1\n");
	return 0;
}