#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

int dd[1001];
int rr[1001];
char str[1010][1010];

int main()
{
	int i,j,r,c,n = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
		scanf(" %s",&str[i][1]);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			// printf("%c",str[i][j]);
			if(str[i][j] == '*')
			{
				dd[j]++,rr[i]++,n++;
			}
		}
		// printf("\n");
	}
	// printf("%d\n",n);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(str[i][j] == '.' && dd[j] + rr[i] == n)
			{
				// printf("%d %d\n",dd[j],rr[i]);
				printf("YES\n%d %d\n",i,j);
				return 0;
			}
			if(str[i][j] == '*' && dd[j] + rr[i] - 1 == n)
			{
				printf("YES\n%d %d\n",i,j);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}