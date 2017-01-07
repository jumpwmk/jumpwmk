#include <stdio.h>
#include <queue>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

priority_queue <int > q;

int main()
{
	int i,j,n,tmp;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		q.push(-tmp);
	}
	for(i=1;!q.empty();i++)
	{
		while(!q.empty() && -q.top()<i)
			q.pop();
		if(q.empty())
			break;
		q.pop();
	}
	printf("%d\n",i);
	return 0;
}