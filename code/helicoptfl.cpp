#include <stdio.h>
#include <algorithm>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,x1,x2,y;
	bool operator <(const pt &a)const
	{
		return y < a.y;
	}
};

pt x[100100];
int seg[900500];
int chk[400500];
int ans[200200];
int check[200200];
int a,b,ii;

bool cmp(int a,int b)
{
	return a == b;
}

void update(int l,int r,int state)
{
	// printf("%d %d %d\n",chk[l],chk[r],state);
	if(l == r)
	{
		seg[state] = ii;
		return;
	}
	if(chk[l] >= a && chk[r] <= b)
	{
		seg[state] = ii;
		return;
	}
	if(seg[state] > 0)
	{
		seg[state*2] = seg[state];
		seg[state*2+1] = seg[state];
		seg[state] = 0;
	}
	int mid = (l+r)/2;
	if(chk[mid] >= a)
		update(l,mid,state*2);
	if(chk[mid+1] <= b)
		update(mid+1,r,state*2+1);
}

void init(int l,int r,int state)
{
	// printf("%d %d\n",l,r);
	if(l == r)
	{
		ans[l] = seg[state];
		// printf("-- %d\n",ans[l]);
		return;
	}
	if(seg[state] > 0)
	{
		seg[state*2] = seg[state];
		seg[state*2+1] = seg[state];
	}
	int mid = (l+r)/2;
	init(l,mid,state*2);
	init(mid+1,r,state*2+1);
}

int main()
{
	int i,j,n,m = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&x[i].x1,&x[i].x2,&x[i].y);
		// printf("%d %d\n",x[i].x1,x[i].x2);
		chk[m++] = x[i].x1*2;
		chk[m++] = x[i].x1*2+1;
		chk[m++] = x[i].x2*2;
		chk[m++] = x[i].x2*2+1;
		x[i].i = i+1;
	}
	sort(x,x+n);
	sort(chk,chk+m);
	m = unique(chk,chk+m) - chk;
	printf("%d\n",m);
	for(i=0;i<n;i++)
	{
		ii = x[i].i;
		a = x[i].x1*2;
		b = x[i].x2*2;
		update(0,m-1,1);
	}
	init(0,m-1,1);
	check[0] = 1;
	for(i=0;i<m;i++)
	{
		if(check[ans[i]] == 0)
		{
			check[ans[i]] = 1;
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}