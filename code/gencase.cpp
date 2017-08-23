#include<bits/stdc++.h>
using namespace std;
long long p[110];
int main()
{
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        int n;
        long long a,b,now = 0,mx,ans,tmp;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%lld",&p[i]);
        sort(p+1,p+n+1);
        scanf("%lld %lld",&a,&b);
        int s = lower_bound(p+1,p+n+1,a) - p;
        if(s == n+1)
        {
            printf("%lld\n",b);
            continue;
        }
        now = p[s] - a;
        if(now > p[s-1] - a && s-1 != 0)
            now = abs(a-p[s-1]),s--;
        mx = now,ans = a;
        for(int i=s+1; i<=n; i++)
        {
            if(p[i-1] < a)
                continue;
            now = p[i]-p[i-1];
            now = now/2;
            tmp = min(b,p[i-1]+now);
            now = min(abs(tmp-p[i]),abs(tmp-p[i-1]));
            if(now > mx)
                mx = now,ans = tmp;
        }
        if(b >= p[n])
        {
            now = b-p[n];
            if(now > mx)
                mx = now,ans = b;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
