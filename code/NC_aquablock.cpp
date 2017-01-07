#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
 	int i,j;
}; 
pt tmp;
pt x[31][200000];
char str[30300][30];

int main()
{
	int i,j,r,c;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
	{
		scanf(" %s",x[i]);
	}
	for(j=0;j<c;j++)
	{
		tmp.i = r-1,tmp.j = j;
		for(i=r-1;i>0;i--)
		{
			if(str[i][j] == 'X')
			{
				tmp.i = i-1,tmp.j = j;
			}
			x[j][]
		}
	}
	return 0;
}