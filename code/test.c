#include <stdio.h>
#include <string.h>
#define mx(a,b) a>b ? a:b

int x[2][50050];
char a[50050],b[50050];

int main()
{
	int i,j,lena,lenb;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf(" %s %s",&a[1],&b[1]);
	lena = strlen(&a[1]), lenb = strlen(&b[1]);
	// printf("%d %d\n",lena,lenb);
	for(i = 1; i <= lena; i++)
	{
		for(j = 1; j <= lenb; j++)
		{
			if(a[i] == b[j])
				x[i%2][j] = x[(i+1)%2][j - 1] + 1;
			else 
				x[i%2][j] = mx(x[i%2][j - 1],x[(i+1)%2][j]);
		}
	}
	printf("%d\n",x[lena%2][lenb]);
	return 0;
}