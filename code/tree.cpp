#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int check[100100];
int x[100100];
int chk[100100];
int mark[100100];
vector <int > v[1000100];
vector <int >::iterator it;
stack <int > stk;

int main()
{
	int i,j,n,t,res;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		res = 0;
		for(i=0;i<=1000000;i++)
			v[i].clear();
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&check[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&x[i]);
		for(i=n;i>=1;i--)
		{
			while(!stk.empty() && x[stk.top()] <= x[i])
				stk.pop();
			if(stk.empty())
				chk[i] = n;
			else chk[i] = stk.top() - 1;
			stk.push(i);
		}
		while(!stk.empty())
			stk.pop();
		for(i=1;i<=n;i++)
		{
			mark[i] = v[x[i]].size();
			v[x[i]].push_back(i);
		}
		for(i=1;i<=1000000;i++)
		{
			for(j=0;j<v[i].size();)
			{
				// printf("%d %d %d\n",v[i][j],check[v[i][j]],x[i]);
				if(check[v[i][j]] == i)
				{
					j++;
					continue;
				}
				it = upper_bound(v[i].begin(),v[i].end(),chk[v[i][j]]);
				res++;
				// printf("%d %d %d\n",i,j,*it);
				if(it == v[i].end())
					break;
				j = mark[*it];
			}
		}
		printf("%d\n",res);
	}
	return 0;
}