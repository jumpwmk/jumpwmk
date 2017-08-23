#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[200];

int main()
{
	int t,i,j,n,a,b,res = 0,chk,ans;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d",&x[i]);
		}
		scanf("%d %d",&a,&b);
		for(i = a; i <= b; i++)
		{
			chk = INF;
			for(j = 0; j < n; j++)
			{
				chk = min(chk,abs(i - x[j]));
			}
			if(res < chk)
			{
				res = chk;
				ans = i;
			}
		}
		printf("%d\n",ans);
		
	}
	return 0;
}