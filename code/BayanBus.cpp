#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	int i,j,n;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	printf("+------------------------+\n");
	printf("|");
	n--;
	for(i=0;i<11;i++)
	{
		if(n >= i*3 + 1 or (i == 0 && n+1 >= i*3+1))
			printf("O");
		else 
			printf("#");
		printf(".");
	}
	printf("|D|)\n|");
	for(i=0;i<11;i++)
	{
		if(n >= i*3 + 2 or (i == 0 && n+1 >= i*3+2))
			printf("O");
		else 
			printf("#");
		printf(".");
	}
	printf("|.|\n|");
	if(n >= 2)
	{
		printf("O.......................|\n|");
	}
	else
	{
		printf("#.......................|\n|");
	}
	for(i=0;i<11;i++)
	{
		if(n >= i*3 + 3)
			printf("O");
		else 
			printf("#");
		printf(".");
	}
	printf("|.|)\n");
	printf("+------------------------+\n");
	return 0;
}