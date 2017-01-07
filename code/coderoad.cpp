#include <cstdio>
#include <cstdlib> // ABS
#include <algorithm>
using namespace std;
struct tii{
	int x,y; // x = isreprt , y = is nonreport
	long long pos;
	bool operator < (const tii &a) const{
		if (pos < a.pos) return true;
		return false;
	}
};


int pos[1010][2],adj[1010][1010],cnt=0;
tii tmp;
tii list[1000010];

int main()
{
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	int n,m,rep=0,in;
	int nowrep=0,nowunrep=0,mindiff=2e6;
	long long ans;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&pos[i][0],&pos[i][1]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&in);
			adj[i][in] = 1;
			rep++;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (adj[i][j])
			{
				tmp.x = 1,tmp.y = 0;
				tmp.pos = (long long) (pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0]) +(long long)(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]);
				list[++cnt] = tmp;
			}
			else
			{
				tmp.x = 0,tmp.y = 1;
				tmp.pos = (long long) (pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0]) +(long long)(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]);
				list[++cnt] = tmp;
			}
		}
	}
	printf("%d\n",rep);
	sort(list+1,list+1+cnt);
	for (int i=1;i<=cnt;i++)
	{
		nowrep += list[i].x, nowunrep += list[i].y;
		if(list[i].pos == 1943162)
		{
			printf("%d\n", nowrep + nowunrep);
		}
		if (abs(nowrep-rep)+nowunrep < mindiff && list[i].pos != list[i+1].pos)
			ans = list[i].pos, mindiff= abs(nowrep-rep)+nowunrep;
	}
	printf("%lld %d \n", ans,mindiff);
	return 0;
}