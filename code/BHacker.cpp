#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1000000000

using namespace std;

vector <int > x[1000100];
int cnt[1000100];

int main()
{
	int i,j,n,m,mx,tmp;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d",&tmp);
			x[i].push_back(tmp);
		}
	}
	for(i = 1; i <= n; i++)
	{
		sort(x[i].begin(),x[i].end());	
	}
	for(j = 0; j < m; j++)
	{
		mx = -1, tmp = 0;
		for(i = 1; i <= n; i++)
		{
			if(mx < x[i][j])
			{
				mx = x[i][j];
				tmp = i;
			}
		}
		cnt[tmp]++;
	}
	mx = -1,tmp = 0;
	for(i = 1; i <= n; i++)
	{
		if(mx < cnt[i])
		{
			mx = cnt[i];
			tmp = i;
		}
	}
	printf("%d\n",tmp);
	return 0;
}