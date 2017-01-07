#include <stdio.h>
#include <set>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int cnt[100010];
long long sum[100100];
set <int > s[100100];
int mark[100100];


int main()
{
	int i,j,n,m,a,b,cmd;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	while(scanf("%d %d",&n,&m) != EOF)
	{
		for(i=1;i<=n;i++)
		{
			s[i].clear();
			mark[i] = i;
			s[i].insert(i);
			sum[i] = (long long)i;
			cnt[i] = 1;
		}
		while(m--)
		{
			scanf("%d",&cmd);
			if(cmd == 1)
			{
				scanf("%d %d",&a,&b);
				int aa = mark[a],bb = mark[b];
				if(aa == bb)
					continue;
				if(s[aa].size() > s[bb].size())
					swap(aa,bb);
				while(!s[aa].empty())
				{
					a = *s[aa].begin();

					s[aa].erase(a);
					s[bb].insert(a);
					mark[a] = bb;
					sum[bb] += (long long)a;
					cnt[bb]++;
				}
				sum[aa] = 0ll;
				cnt[aa] = 0;
			}
			else if(cmd == 2)
			{
				scanf("%d %d",&a,&b);
				s[mark[a]].erase(a);
				sum[mark[a]] -= (long long)a;
				cnt[mark[a]]--;
				s[mark[b]].insert(a);
				sum[mark[b]] += (long long)a;
				cnt[mark[b]]++;
				mark[a] = mark[b];
			}
			else
			{
				scanf("%d",&a);
				printf("%d %lld\n",cnt[mark[a]],sum[mark[a]]);
			}
		}
	}
	return 0;
}