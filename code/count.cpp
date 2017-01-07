#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

int fen[200200];
int n,k;

void up(int ii)
{
	while(ii <= n)
	{
		fen[ii]++;
		ii += (ii & -ii);
	}
}

int sum(int ii,int jj)
{
	int res = 0;
	ii--;
	while(ii > 0)
	{
		res -= fen[ii];
		ii -= (ii & -ii);
	}
	while(jj > 0)
	{
		res += fen[jj];
		jj -= (jj & -jj);
	}
	return res;
}

void solution()
{
	int ii = 1;
	for(int i = 0; i < n;i++)
	{
		int res = sum(ii,n);
		if(n - ii + 1 - res < k)
		{
			// printf("= %d %d =\n",n-ii+1-res,k);
			k -= n - ii + 1 - res;
			int res2 = sum(1,n);
			if(n - res2 < k)
			{
				k %= n-res2;
			}
			if(k == 0)
				k = n - res2;
			ii = 1;
			i--;
			continue;
		}
		else
		{
			int l = ii,r = n;
			while(l < r)
			{
				int mid = (l+r)/2;
				int res = sum(ii,mid);
				if(mid - ii + 1 - res < k)
				{
					l = mid + 1;
				}
				else
				{
					r = mid;
				}
				// printf("%d %d\n",l,r);
			}
			up(l);
			if(i == n - 1)
				printf("%d\n",l);
			ii = l+1;
			k = l;
		}
	}
}

int main()
{
	int i,j;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&k);
	solution();
	return 0;
}