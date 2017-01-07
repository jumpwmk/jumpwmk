#include <stdio.h>
#include <string.h>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int chk[404][404];
vector <int > v[404];
int x[404];
bool check = false;
int cnt[2][404];
int mic[404];
int st;

void play(int ii,int state)
{
	int i;
	for(i=0;i<v[ii].size();i++)
	{
		if(x[v[ii][i]] == state)
		{
			check = true;
			return;
		}
		else if(x[v[ii][i]] == -1)
		{
			x[v[ii][i]] = state^1;
			cnt[state^1][st]++;
			play(v[ii][i],state^1);
		}
	}
}

int main()
{
	int i,j,n,m,q;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&n,&m);
		memset(chk,0,sizeof(chk));
		memset(x,-1,sizeof(x));
		memset(cnt,0,sizeof(cnt));
		check = false;
		for(i=1;i<=n;i++)
		{
			v[i].clear();
			chk[i][i] = 1;
		}
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			chk[a][b] = chk[b][a] = 1;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(chk[i][j] == 0)
				{
					v[i].push_back(j);
				}
			}
		}
		st = 0;
		for(i=1;i<=n;i++)
		{
			if(check == true)
			{
				printf("-1\n");
				break;
			}
			if(x[i] == -1)
			{
				x[i] = 1;
				cnt[1][st]++;
				play(i,1);
				st++;
			}
		}
		memset(mic,0,sizeof(mic));
		mic[0] = 1;
		for(i=0;i<st;i++)
		{
			for(j=n;j>=0;j--)
			{
				if(j - cnt[1][i] >= 0 && mic[j - cnt[1][i]])
					mic[j] = 1;
				if(j - cnt[0][i] >= 0 && mic[j - cnt[0][i]])
					mic[j] = 1;
			}
		}
		for(j=n/2;j>=0;j--)
		{
			if(mic[j])
				break;
		}
		if(check == false)
			printf("%d\n",n-2*j);
	}
	return 0;
}