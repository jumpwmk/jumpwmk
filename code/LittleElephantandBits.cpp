#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char x[100010];

int main()
{
	int i,j,n,chk = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf(" %s",x);
	n = strlen(x);
	for(i=0;i<n;i++)
	{
		if(x[i] == '0' && chk == 0)
		{
			chk = 1;
		}
		else if(i == n-1 && chk == 0)
		{
			chk = 1;
		}
		else printf("%c",x[i]);
	}
	return 0;
}