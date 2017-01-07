#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

int mark[200200];
int head[200200];
int x[200200];
int res = -1,cnt,ch;

int findhead(int ii)
{
	int ha,tmp = ii;
	while(ii != head[ii])
		ii = head[ii];
	ha = ii;
	ii = tmp;
	while(ii != head[ii])
	{
		tmp = ii;
		ii = head[ii];
		head[tmp] = ha;
	}
	return ha;
}

void play(int ii)
{
	if(mark[ii])
	{
		x[ii] = res;
		return;
	}
	mark[ii] = 1;
	play(x[ii]);
}

void check(int ii)
{
	if(mark[ii])
	{
		if(x[ii] != ii)
		{
			if(ch == 1)
			{
				x[ii] = ii;
				cnt++;
			}
			ch = 1;
		}
		return;
	}
	mark[ii] = 1;
	check(x[ii]);
}

int main()
{
	int i,j,n,ha,hb;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		head[i] = i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		ha = findhead(i);
		hb = findhead(x[i]);
		head[ha] = hb;
	}
	for(i=1;i<=n;i++)
	{
		head[i] = findhead(i);
		ch = 0;
		check(i);
		if(head[i] == i && ch == 0 && res == -1)
		{
			res = i;
			head[i] =  -1;
		}
	}
	cnt = 0;
	ch = 1;
	// printf("%d\n",res);
	for(i=1;i<=n;i++)
	{
		if(head[i] == i)
		{
			if(res == -1)
			{
				check(i);
				res = i;
			}
			else
			{
				cnt++;
				play(i);
			}
		}
	}
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
		printf("%d ",x[i]);
	printf("\n");
	return 0;
}