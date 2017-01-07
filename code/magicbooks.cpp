#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int x,a;
};

pt data[100100];
int mark[100300];
int x[300300];
int chk[300300];
int n,k,s,m = 0;
int a,b;

bool cmp(int a,int b)
{
	if(a == b)
		return true;
	return false;
}

void up(int w,int state)
{
	x[state] = mx(x[state],w);
	if(state == 1)
		return;
	up(w,state/2);
}

void init(int l,int r,int state)
{
	if(l == r)
	{
		mark[l] = state;
		return;
	}
	int mid = (l+r)/2;
	init(l,mid,state*2);
	init(mid+1,r,state*2+1);
}

int query(int l,int r,int state)
{
	int tmp = -INF,mid,ll,rr;
	if(l == r)
	{
		return x[state];
	}
	if(chk[l] >= a && chk[r] <= b)
	{
		return x[state];
	}
	mid = (l+r)/2;
	if(chk[mid] >= a)
	{
		ll = query(l,mid,state*2);
		tmp = mx(ll,tmp);
	}
	if(chk[mid+1] <= b)
	{
		rr = query(mid+1,r,state*2+1);
		tmp = mx(rr,tmp);
	}
	return tmp;
}

int main()
{
	int i,j,tmp;
	int res = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d %d",&n,&k,&s);
	chk[m++] = s;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&data[i].x,&data[i].a);
		chk[m++] = data[i].x;
	}
	sort(chk,chk+m);
	m = unique(chk,chk+m,cmp) - chk;
	init(0,m-1,1);
	for(i=0;i<300000;i++)
		x[i] = -INF;
	i = lower_bound(chk,chk+m,s) - chk;
	up(0,mark[i]);
	for(i=0;i<n;i++)
	{
		a = data[i].x - k;
		b = data[i].x + k;
		tmp = query(0,m-1,1);
		tmp += data[i].a;
		if(tmp > 0)
		{
			res = mx(res,tmp);
			j = lower_bound(chk,chk+m,data[i].x) - chk;
			up(tmp,mark[j]);
		}
	}
	printf("%d\n",res);
	return 0;
}