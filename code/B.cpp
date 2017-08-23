#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

long long gcd(long long a, long long b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	long long i, n, a, b, ans, sum = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld %lld",&ans,&sum);
	for(i = 1; i < n; i++)
	{
		scanf("%lld %lld",&a,&b);
		ans = gcd(ans,a);
		sum += b;
	}
	printf("%lld\n",gcd(ans,sum));
	return 0;
}