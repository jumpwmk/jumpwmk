#include <stdio.h>
#include <string.h>
#include <set>
#include <deque>
#include <queue>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,w,m;
	bool operator<(const pt &a)const
	{
		if(w+m == a.w + a.m)
			return i < a.i;
		return w+m < a.w + a.m;
	}
};

int x[100100];
pt chk[100100];
deque <pt > q;
set <pt > s;
set <pt >::iterator it;
pt tmp2,tmp;

int main()
{
	int i,j,n,k;
	// freopen("../49.in","r",stdin);
	// freopen("../49.sol","w",stdout);
	memset(chk,-1,sizeof(chk));
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	tmp.w = 0,tmp.m = 0,tmp.i = 0;
	s.insert(tmp),q.push_back(tmp);
	for(i=1;i<=n;i++)
	{
		while(!q.empty() && i - q.front().i > k)
		{
			tmp = q.front();
			tmp2 = tmp;
			it = s.find(tmp);
			s.erase(it);
			tmp = chk[q.front().i + 1];
            it = s.find(tmp);
			q.pop_front();
			if(it == s.end())
			{
				tmp = tmp2;
				tmp.w = x[tmp.i+1];
				tmp.i++;
				q.push_front(tmp);
				s.insert(tmp);
			}
		}
		tmp.i = -1;
		while(!q.empty() && x[i] > q.back().m)
		{
			tmp = q.back();
			it = s.find(tmp);
			s.erase(it);
			q.pop_back();
		}
		if(tmp.i != -1)
		{
			tmp.m = x[i];
			chk[tmp.i] = tmp;
			q.push_back(tmp);
			s.insert(tmp);
		}
		it = s.begin();
		tmp = *it;
		tmp.w = tmp.w + tmp.m;
		tmp.i = i;
		tmp.m = 0;
		q.push_back(tmp);
		chk[i] = tmp;
		s.insert(tmp);
		x[i] = tmp.w+tmp.m;
	}
	printf("%d\n",x[n]);
	return 0;
}
