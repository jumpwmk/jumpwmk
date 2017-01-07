#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[110];
int mark[110];
int head;
long long chk;

void play(int ii)
{
	if(ii == head && mark[ii] > 0)
	{
		chk = mark[ii];
		return;
	}
	if(mark[x[ii]] != 0 && head != x[ii])
	{
		printf("-1\n");
		exit(0);\
	}
	mark[x[ii]] = mark[ii] + 1;
	play(x[ii]);
}

int main()
{
	int i,j,n;
	long long cnt = 1,tmp;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d",&x[i]);
	}
	for(i = 1; i <= n; i++)
	{
		if(mark[i] == 0)
		{
			head = i;
			play(i);
			if(chk == 2)
				chk = 1;
			tmp = chk * cnt;
			tmp /= __gcd(chk,cnt);
			cnt = tmp;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}