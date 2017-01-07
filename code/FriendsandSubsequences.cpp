#include <stdio.h>
#include <algorithm>
#define INF 1000000009

using namespace std;

struct pt
{
	int mx,mn;
};

int x[200100];
int y[200100];
pt seg[600100];
int a,b;
int chkmx,chkmn;

void find(int l,int r,int state)
{
	if(l >= a && r <= b)
	{
		chkmx = max(chkmx,seg[state].mx);
		chkmn = min(chkmn,seg[state].mn);
		return;
	}
	int mid = (l+r)/2;
	if(mid >= a)
		find(l,mid,state*2);
	if(mid+1 <= b)
		find(mid+1,r,state*2 + 1);
}

void initial(int l,int r,int state)
{
	if(l == r)
	{
		seg[state].mx = x[l];
		seg[state].mn = y[l];
		return;
	}
	int mid = (l+r)/2;
	initial(l,mid,state*2);
	initial(mid+1,r,state*2+1);
	seg[state].mx = max(seg[state*2].mx,seg[state*2+1].mx);
	seg[state].mn = min(seg[state*2].mn,seg[state*2+1].mn);
}

int main()
{
	int n,i,j,ll,rr;	
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&y[i]);
	}
	initial(1,n,1);
	int l,r,mid;
	long long ans = 0;
	for(i=1;i<=n;i++)
	{
		l = i,r = n;
		while(l < r)
		{
			mid = (l+r)/2 + 1;
			chkmn = INF;
			chkmx = -INF;
			a = i,b = mid;
			find(1,n,1);
			// printf("%d %d %d %d\n",i,mid,chkmx,chkmn);
			if(chkmx > chkmn)
				r = mid - 1;
			else if(chkmx < chkmn)
				l = mid + 1;
			else l = mid;
		}
		// printf("%d %d %d %d\n",i,l,chkmx,chkmn);
		if(l == n+1)
			l--;
		rr = l;
		l = i,r = n;
		while(l < r)
		{
			mid = (l+r)/2;
			chkmn = INF;
			chkmx = -INF;
			a = i,b = mid;
			find(1,n,1);
			// printf("%d %d %d %d\n",i,mid,chkmx,chkmn);
			if(chkmx > chkmn)
				r = mid - 1;
			else if(chkmx < chkmn)
				l = mid + 1;
			else r = mid;
		}
		chkmn = INF;
		chkmx = -INF;
		a = i,b = l;
		find(1,n,1);
		if(chkmx != chkmn)
			continue;
		ll = l;
		if(ll > rr)
			continue;
		// printf("%d %d %d\n",i,ll,rr);
		ans += (long long)(rr - ll + 1);
	}
	printf("%I64d\n",ans);
	return 0;
}