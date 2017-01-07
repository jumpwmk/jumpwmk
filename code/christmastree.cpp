#include <stdio.h>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

vector<int > x[100010];

int main()
{
	int i,j,a,b,n;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i = 0;i < n - 1;i++)
	{
		scanf("%d %d",&a,&b);
		x[a].push_back(b);
		x[b].push_back(a);
	}
	for(i = 1;i <= n;i++)
	{
		if(x[i].size() >= 4)
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	return 0;
}