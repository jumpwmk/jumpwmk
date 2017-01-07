#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[2000200];
int chk[2000100];
int sum;

int main()
{
	int i,j,n,m,k,chkmax = 0,ii,len,cnt,ans;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
		chkmax = mx(chkmax,x[i]);
	}
	for(i=n;i-n<n;i++)
	{
		x[i] = x[i-n];
	}
	n += n;
	while(m--)
	{
		ans = INF;
		cnt = 0;
		scanf("%d",&k);
		if(k < chkmax)
		{
			printf("NIE\n");
			continue;
		}
		sum = 0;
		for(i=0,j=0;i<n;i++)
		{
			while(sum + x[j] <= k)
			{
				sum+=x[j];
				j = j+1;
			}
			chk[i] = j;
			sum -= x[i];
		}
		len = INF;
		i = 0;
		while(i < n/2)
		{
			cnt++;
			if(chk[i] > n/2)
			{
				// if(n/2 - i < len)
				// 	len = n/2 - i,ii = i;
				break;
			}
			if(chk[i] - i < len)
				len = chk[i]-i,ii = i;
			i = chk[i];
		}
		// printf("%d %d\n",ii,len);
		ans = cnt;
		for(i=ii;i<=ii+len;i++)
		{
			j = i;
			cnt = 0;
			// printf("i = %d\n",i);
			while(j < i+n/2)
			{
				// printf("%d\n",j);
				cnt++;
				j = chk[j];
			}
			ans = mn(cnt,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}