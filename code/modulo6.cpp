#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	int n,s;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&s);
	if(n == 1 && s == 3)
	{
		printf("-1\n");
		return 0;
	}
	if(s%3 != 0 || 9*n-1 < s)
		printf("-1\n");
	else
	{
		for(int i=0;i<n;i++)
		{
			if(s > 0)
			{
				if(i == n-2 && (s - min(9,s)) % 2 != 0)
				{
					// printf("\n%d %d\n",i,s-min(9,s));
					printf("%d",min(8,s-1));
					s -= min(8,s-1);
					// printf("%d",s);
				}
				else
				{
					printf("%d",min(9,s));
					s -= min(9,s);
				}
			}
			else
				printf("0");
		}
	}
	printf("\n");
	return 0;
}