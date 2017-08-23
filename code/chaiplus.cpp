#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int x[300];

int main() 
{
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,n,a,b,res,ans = -1,chk = 0;
        scanf("%d",&n);
        for(i = 0; i < n; i++)
            scanf("%d",&x[i]);
        scanf("%d %d",&a,&b);
        if( a > b )
            swap(a,b);
        sort(x,x+n);
        for(j = 0; j < n; j++)
        {
           printf("%d ",x[j]); 
        }
        printf("\n");
        if(a >= x[n - 1])
        {
            printf("%d\n",b);
            continue;
        }
        if(b <= x[0])
        {
            printf("%d\n",a);
            continue;
        }
        for(i = 0; i < n - 1; i++)
        {
            if(x[i] >= a)
                break;
        }
        for(n = n;n > 1;n--)
        {
            if(x[n-1] <= b)  
                break;
            chk++;
        }


        if(i > 0)
        {
            j = (x[i] + x[i - 1])/2;
            j = max(j, a);
            ans = min(abs(x[i-1] - j),abs(x[i] - j));
            res = j;
        }
        else
        {
            ans = x[0] - a;  
            res = a;
        }

        for(i = i+1; i <= n - 1; i++)
        {
            //printf("= %d %d =",x[i],x[i-1]);
            j = (x[i] + x[i - 1])/2;
            if(min(abs(x[i-1] - j),abs(x[i] - j)) > ans)
                res = j;
            ans = max(ans,(min(abs(x[i-1] - j),abs(x[i] - j))));
        }

        if(chk)
        {
            j = (x[n] + x[n - 1])/2;
            j = min(j, b);
            if(min(abs(x[i-1] - j),abs(x[i] - j)) > ans)
                res = j;
            ans = max(ans,(min(abs(x[i-1] - j),abs(x[i] - j))));
        }
        else
        {
            if(b - x[n - 1] > ans)
                res = b;
            ans = max(ans,b - x[n - 1]);   
        }

        printf("%d\n",res);
    }
    return 0;
}
