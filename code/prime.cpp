#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

long long gcd(long long a,long long b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    long long i,j,n,a,b,q,cnt,mod = 1000000007;
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    scanf("%lld",&q);
    for(i=0;i<q;i++)
    {
        cnt = 0;
        scanf("%lld %lld %lld",&n,&a,&b);
        for(j=a;j<=b;j++)
        {
            if(gcd(n,j) == 1)
            {
                cnt += j;
                cnt %= mod;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}