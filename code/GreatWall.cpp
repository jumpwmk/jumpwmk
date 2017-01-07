#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[100100];
int chk[200200];

int main()
{
	int i,j,n,w,k;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	int l = 0, r = 0, mid;
	scanf("%d %d %d",&n,&w,&k);
	for(i = 1; i <= n; i++)
	{
		scanf("%d ",&x[i]);
		r = max(x[i],r);
	}
	while(l < r)
	{
		int mid = (l + r)/2;
		int cnt = 0;
		// printf(" === %d ===\n",mid);
		for(i = 1; i <= n; i++)
		{
			chk[i] += chk[i - 1];
			if(x[i] - chk[i] > mid)
			{
				int tmp = (x[i] - chk[i]) - mid;
				// printf("%d %d\n",x[i],chk[i]);
				cnt += tmp;
				chk[ i ] += tmp;
				chk[ i + w ] -= tmp;
			}
			chk[i - 1] = 0;
		}
		chk[ n ] = 0;
		// printf("%d\n",cnt);
		if(cnt <= k)
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n",l);
	return 0;
}