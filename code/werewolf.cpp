#include <stdio.h>
#include <vector>
#include <queue>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[100100];
int chk[100100];
int in[100100];
queue <int > q;
vector <int > v[100100];

int main()
{
	int i,j,n,t,ii,res;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		res = 0;
		scanf("%d ",&n);
		for(i = 1; i <= n; i++)
		{
			scanf("%d",&x[i]);
			v[x[i]].push_back(i);
			in[x[i]]++;
		}
		for(i = 1; i <= n; i++)
		{
			if(in[i] == 0)
				q.push(i);
		}
		while(!q.empty())
		{
			bool check = true;
			ii = q.front();
			q.pop();
			if(chk[ii])
				check = false;
			for(i = 0; i < v[ii].size(); i++)
			{
				if(chk[v[ii][i]] == 1)
					check = false;
			}
			if(check)
			{
				chk[ii] = 1;
				in[x[ii]]--;
				if(chk[x[ii]] == 0)
				{
					chk[x[ii]] = 2;
					q.push(x[ii]);
				}
			}
			else
			{
				res++;
				chk[ii] = 2;
				in[x[ii]]--;
				if(chk[x[ii]] == 0 and in[x[ii]] == 0)
				{
					q.push(x[ii]);
				}
			}
		}
		for(i = 1; i <= n; i++)
		{
			if(chk[i] == 0)
			{
				ii = i;
				chk[ii] = 2;
				res++;
				ii = x[ii];
				int cnt = 0;
				while(ii != i)
				{
					chk[ii] = cnt + 1; 
					if(chk[ii] == 2)
						res++;
					cnt = (cnt+1)%2;
					ii = x[ii];
				}
			}
		}
		for(i = 1; i <= n; i++)
		{
			chk[i] = 0;
			v[i].clear();
			in[i] = 0;
		}
		printf("%d\n",res);
	}
	return 0;
}