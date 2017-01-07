#include <stdio.h>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[10100];
int mic[10100][3];
vector <int > v[10100];


void play(int ago,int ii)
{
	int i,chk = INF;
	// printf("%d\n",ii);

	for(i = 0;i < v[ii].size(); i++)
		if(v[ii][i] != ago)
			play(ii,v[ii][i]);

	int sum0 = 0,sum1 = 0,sum2 = 0;

	if(v[ii].size() == 1 && ago != 0)
	{
		mic[ii][0] = 0;
		mic[ii][1] = x[ii];
		mic[ii][2] = x[ii];
		return;
	}

	for(i = 0;i < v[ii].size();i++)
	{
		sum0 += mn(mic[v[ii][i]][1],mic[v[ii][i]][2]);
		sum1 += mn(mic[v[ii][i]][1],mic[v[ii][i]][2]);
		sum2 += mn(mic[v[ii][i]][0],(mn(mic[v[ii][i]][1],mic[v[ii][i]][2])));
	}

	for(i = 0;i < v[ii].size();i++)
	{
		if(v[ii][i] != ago)
		{
			chk = mn(chk,mic[v[ii][i]][2] - mic[v[ii][i]][1]);
		}
	}
	if(chk < 0)
		chk = 0;
	mic[ii][0] = sum0;
	mic[ii][1] = sum1 + chk;
	mic[ii][2] = sum2 + x[ii];
	return;
}

int main()
{
	int i,j,n,a,b;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	if(n == 1)
	{
		printf("%d\n",x[1]);
		return 0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	play(0,1);
	for(i=1;i<=n;i++)
	{
		printf("%d %d %d %d\n",i,mic[i][0],mic[i][1],mic[i][2]);
	}
	printf("%d\n",mn(mic[1][1],mic[1][2]));
	return 0;
}