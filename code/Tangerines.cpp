#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#define ii pair<int, int>
#define X first
#define Y second
#define pb push_back
#define vi vector<int>
#define vii vector< pair<int, int> >
typedef long long ll;
using namespace std;
int f[30005];
vector<int> adj[30005];
int h[30005];
void dfs(int u, int par, int lev)
{
	h[u] = lev;
	for(int i= 0; i< (int) adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v == par) continue;
		dfs(v, u, lev+1);
	}
}
bool cmp(int a, int b)
{
	return h[a] < h[b];
}
int main()
{

			freopen("../test.in","r",stdin);
			freopen("../test.out","w",stdout);

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i< n-1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
		f[a]++; f[b]++;
	}
	dfs(1, 0, 1);
	int res = 0;
	for(int i = 1; i<= n; i++)
	{
		res += (f[i] == 1);
	}
	int ans = (res/2) + (res%2);
	printf("%d\n", ans);
	vector<int> ei;
	if(m == 2)
	{
		for(int i = 1; i<= n; i++)
		{
			if(f[i] == 1) ei.pb(i);
		}
		sort(ei.begin(), ei.end(), cmp);
		int k = (int) ei.size();
		//for(int i = 0; i< k; i++) printf("%d ", ei[i]);
		// printf("%d\n",k);
		for(int i = 0; i< k; i++)
		{
			if(i < k-i-1) printf("%d %d\n", ei[i], ei[k-i-1]);
		}
		if(k%2) printf("1 %d\n", ei[k/2]);
	}
	return 0;
}