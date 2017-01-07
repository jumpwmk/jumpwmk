#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char str[100100];
int a[100100];
int b[100100];

int main()
{
	int i,j,n,k,res = 1;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&k);
	scanf(" %s",str);
	if(str[0] == 'a')
		a[0] = 1,b[0] = 0;
	else
		b[0] = 1,a[0] = 0;
	// printf("%d %d\n",a[0],b[0]);
	for(i=1;i<n;i++)
	{
		if(str[i] == 'a')
			a[i] = a[i-1] + 1,b[i] = b[i-1];
		else
			b[i] = b[i-1] + 1,a[i] = a[i-1];
		// printf("%d %d\n",a[i],b[i]);
		if(a[i] <= k)
			res = i+1;
		else
		{
			j = lower_bound(a,a+i+1,a[i]-k) - a;
			// printf("%d %d\n",i,j);
			res = mx(res,i-j);
		}
		if(b[i] <= k)
			res = i+1;
		else
		{
			j = lower_bound(b,b+i+1,b[i]-k) - b;
			// printf("%d %d\n",i,j);
			res = mx(res,i-j);
		}
	}
	printf("%d\n",res);
	return 0;
}