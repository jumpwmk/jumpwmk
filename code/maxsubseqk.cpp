#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

long long x[100100];
long long sum[100100];
int n,k;
long long chk[100100];

long long play(int l,int r)
{
	int i,j;
	int mid = (l+r)/2;
	long long resl = 0,resr = 0,res;
	if(l == r)
		return mx(0,x[l]);
	resl = play(l,mid);
	resr = play(mid+1,r);
	res = mx(resl,resr);

	chk[mid-l+1] = 0;

	for(i = mid,j = 1;i >= l && j <= k;i--,j++)
	{
		chk[j] = mx(sum[mid] - sum[i-1],chk[j-1]);
	}
	for(i = mid+1,j = 1;i <= r && j <= k;i++,j++)
	{
		res = mx(res,sum[i] - sum[mid] + chk[mn(k-j,mid-l+1)]);
	}
	return res;
}

int main()
{
	int i,j,t;
	// freopen("../20.in","r",stdin);
	// freopen("../20.sol","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		memset(sum,0,sizeof(sum));
		memset(chk,0,sizeof(chk));
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			sum[i] = sum[i-1]+x[i];
		}
		printf("%lld\n",play(1,n));
	}
	return 0;
}