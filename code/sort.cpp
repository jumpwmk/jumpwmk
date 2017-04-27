#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

int x[100100];
int fen[100100];
int n;

void update(int ii)
{
	while(ii <= n)
	{
		fen[ii]++;
		ii += (ii & -ii);
	}
}

int query(int ii)
{
	int sum = 0;
	while(ii > 0)
	{
		sum += fen[ii];
		ii -= (ii & -ii);
	}
	return sum;
}

int main()
{
	int i, tmp, t;
	long long sum = 0;
	freopen("../10.in","r",stdin);
	freopen("../10.sol","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(fen,0,sizeof(fen));
		memset(x,0,sizeof(x));
		sum = 0;
		scanf("%d",&n);
		for(i = 1; i <= n; i++)
		{
			scanf("%d",&tmp);
			x[tmp] = i;
		}
		for(i = n; i >= 1; i--)
		{
			sum += (long long)query(x[i]);
			update(x[i]);
		}
		if(sum % 2 == 0)
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}