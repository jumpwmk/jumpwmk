#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define mod 1000000007
#define INF 1000000000

using namespace std;

struct pt
{
	int i;
	long long w;
	bool operator <(const pt &a)const
	{
		if(i == a.i)
			return w < a.w;
		return i < a.i;
	}
};

set <pt > s[100100];
int x[100100],chk[100100];
vector <pt > v[100100];
pt tmp,tmp2;
set <pt >::iterator it;

int main()
{
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	int i,j,n,cmd,m = 0;
	long long w;
    tmp.i=INT_MIN,tmp.w=1;
    // v[0].push_back(tmp);
    // s[0].insert(tmp);
    // chk[0]=INT_MIN;
	scanf("%d %d",&n,&cmd);
	tmp.i = cmd,tmp.w = 1;
	v[m].push_back(tmp);
	s[m].insert(tmp);
	chk[m++] = cmd;
	while(--n)
	{
		scanf("%d",&cmd);
		i = lower_bound(chk,chk+m,cmd) - chk;
		if(i == m)
			m++;
		if(i == 0)
			continue;
		tmp.i = cmd,tmp.w = 0;
		it = s[i-1].lower_bound(tmp);
		if(it == s[i-1].end())
			w = 0;
		else
			w = it->w;
		tmp.w = v[i-1].back().w - w;
		if(!v[i].empty())
			tmp.w += v[i].back().w;
		if(!v[i].empty() && v[i].back().i == cmd)
		{
			tmp2 = v[i].back();
			v[i].pop_back();
			it = s[i].lower_bound(tmp2);
			s[i].erase(it);
		}
		if(tmp.w < 0)
			tmp.w += mod;
		tmp.w %= mod;
		v[i].push_back(tmp);
		s[i].insert(tmp);
		chk[i] = cmd;
	}
	printf("%lld\n",v[m-1].back().w%mod);
	return 0;
}