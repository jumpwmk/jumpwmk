#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	int n,m,i,j;
	long long cnt = 0,tmp,tmp2;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=0;i<5;i++)
	{
		tmp = n/5;
		if(n%5 >= i)
			tmp++;
		if(i == 0)
			tmp--;
		tmp2 = m/5;
		if(m%5 >= (5-i)%5)
			tmp2++;
		if(i == 0)
			tmp2--;
		// printf("%lld %lld\n",tmp,tmp2);
		cnt += tmp*tmp2;
	}
	printf("%I64d\n",cnt);
	return 0;
}