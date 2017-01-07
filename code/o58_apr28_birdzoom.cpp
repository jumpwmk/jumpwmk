#include <stdio.h>
#include <set>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,w;
	bool operator <(const pt &a)const
	{
		if(w == a.w)
			return i < a.i;
		return w < a.w;
	}
};

set <pt > s;
set <pt >::iterator it,it2;
set <pt > ans;
set <pt >::iterator itans;
pt tmp;

int main()
{
	int n,k,q,i,j,cnt = 1,num,cmd;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d %d %d",&n,&k,&q);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		tmp.i = cnt++;
		tmp.w = j;
		s.insert(tmp);
	}
	it = s.begin();
	it2 = it;
	for(i=1;i<k;i++)
	{
		if(it2 != s.end())
			it2++;
	}
	while(it2 != s.end())
	{
		tmp.i = it->i;
		tmp.w = it2->w - it->w;
		ans.insert(tmp);
		it2++,it++;
	}
	while(q--)
	{
		scanf("%d %d",&cmd,&num);
		tmp.i = cnt++;
		tmp.w = num;
		if(cmd == 0)
		{

		}
		else
		{
			it = s.find(tmp);
			if(it != s.begin())
			{
				it--;a
			}
		}
	}
	return 0;
}