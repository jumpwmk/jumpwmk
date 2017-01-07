#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

int mic[30003][1000];
int x[30003];
int n,d,m;

int play(int a,int b)
{
	int res = x[a];
	if(a > m)
		return 0;
	if(b-500+d == 0)
		return 0;
	if(mic[a][b] != -1)
		return mic[a][b];
	// printf("%d %d\n",a,b-500+d);
	res = mx(res,play(a+b-500+d-1,b-1) + x[a]);
	res = mx(res,play(a+b-500+d,b) + x[a]);
	res = mx(res,play(a+b-500+d+1,b+1) + x[a]);
	// if(x[a] > 0)
		// printf("%d %d %d\n",a,b-500+d,res);
	return mic[a][b] = res;
}

int main()
{
	int i,j,tmp;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&d);
	while(n--)
	{
		scanf("%d",&tmp);
		m = mx(m,tmp);
		x[tmp]++;
	}
	memset(mic,-1,sizeof(mic));
	printf("%d\n",play(d,500));
	return 0;
}