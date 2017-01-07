#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[200200];

int main()
{
	int i,j,tmp,n,s,cnt = 0,chk = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&s);
	for(i = 1; i <= n; i++)
	{
		scanf("%d",&x[i]);
		if(i == s)
		{
			if(x[i] != 0)
				cnt++;
			x[i] = 0;
		}
	}
	sort(x+1,x+n+1);
	tmp = 1;
	for(i = 2; i <= n; i++)
	{
		if(x[i] > tmp)
		{
			// printf("%d\n",x[i]);
			while(chk > 0 && x[i] > tmp)
			{
				tmp++;
				cnt++;
				chk--;
			}
			while(i <= n && x[i] > tmp)
			{
				// printf("%d %d ==\n",i,n);
				cnt++;
				tmp++;
				n--;
			}
		}
		else if(x[i] == 0)
		{
			chk++;
		}
		if(x[i] == tmp)
		{
			tmp++;
		}
	}
	printf("%d\n",cnt+chk);
	return 0;
}