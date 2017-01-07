#include <stdio.h>
#include <algorithm>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i;
	long long w;
};

vector <pt > v[100100];
long long x[100100];
int cnt[100100];
pt tmp;
int res = 0;

void cut(int ii)
{
	res++;
	for(int i=0;i<v[ii].size();i++)
	{
		cut(v[ii][i].i);
	}
	return;
}

void play(int ii,long long w)
{
	int i;
	if(w > x[ii])
	{
		cut(ii);
		return;
	}
	for(i=0;i<v[ii].size();i++)
	{
		play(v[ii][i].i,(mx((w+v[ii][i].w),0)));
	}
}

int main()
{
	int i,j,n;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%I64d",&x[i]);
	for(i=2;i<=n;i++)
	{
		scanf("%d %I64d",&j,&tmp.w);
		tmp.i = i;
		v[j].push_back(tmp);
	}
	play(1,0);
	printf("%d\n",res);
	return 0;
}