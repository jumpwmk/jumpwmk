#include <stdio.h>
#include <vector>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define mod 1000000007

using namespace std;

long long x[100100];
vector <int > v[100100];
long long ans;

void play(int ii,int ago)
{
	for(int i = 0; i < v[ii].size(); i++)
	{
		if(v[ii][i] == ago)
			continue;
		play(v[ii][i],ii);
	}
	x[ii] = 1;
	for(int i = 0; i < v[ii].size(); i++)
	{
		if(v[ii][i] == ago)
			continue;
		x[ii] *= (x[v[ii][i]] + 1);
		x[ii] %= mod;
	}
	ans += x[ii];
	ans %= mod;
}

int main()
{
	int i, j, n, a, b;
	// freopen("../10.in","r",stdin);
	// freopen("../10.sol","w",stdout);
	scanf("%d",&n);
	for(i = 0; i < n - 1; i++)
	{
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	play(1,0);
	printf("%lld\n",ans);
	return 0;
}