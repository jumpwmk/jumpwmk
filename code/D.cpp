#include <stdio.h>
#include <algorithm>
#include <map>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int x,y,z;
	bool operator<(const pt &a)const
	{
		if(x == a.x)
		{
			if(y == a.y)
				return z < a.z;
			return y < a.y;
		}
		return x < a.x;
	}
};

struct data
{
	int i,w;
	bool operator<(const data &a)const
	{
		if(w == a.w)
			return i < a.i;
		return w < a.w;
	}
};

pt x[100100];
map <int , map <int, data> > m;

int main()
{
	int i,j,n,zz,nn,w1,w2;
	double ans = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d",&x[i].x,&x[i].y,&x[i].z);
	}
	for (int i = 0; i < n; ++i)
	{
		if(ans < min(x[i].x/2.0,min(x[i].y/2.0,x[i].z/2.0)))
		{
			nn = 1,w1 = i + 1;
			ans = min(x[i].x/2.0,min(x[i].y/2.0,x[i].z/2.0));
		}
		
		zz = x[i].z + max(m[x[i].x][x[i].y].w,m[x[i].y][x[i].x].w);
		if(ans < min(x[i].x/2.0,min(x[i].y/2.0,zz/2.0)))
		{
			nn = 2,w1 = i + 1;
			if(m[x[i].x][x[i].y].w > m[x[i].y][x[i].x].w)
				w2 = m[x[i].x][x[i].y].i + 1;
			else
				w2 = m[x[i].y][x[i].x].i + 1;
			ans = min(x[i].x/2.0,min(x[i].y/2.0,zz/2.0));
		}

		zz = x[i].y + max(m[x[i].x][x[i].z].w,m[x[i].z][x[i].x].w);
		if(ans < min(x[i].x/2.0,min(x[i].z/2.0,zz/2.0)))
		{
			nn = 2,w1 = i + 1;
			if(m[x[i].x][x[i].z].w > m[x[i].z][x[i].x].w)
				w2 = m[x[i].x][x[i].z].i + 1;
			else
				w2 = m[x[i].z][x[i].x].i + 1;
			ans = min(x[i].x/2.0,min(x[i].z/2.0,zz/2.0));
		}

		zz = x[i].x + max(m[x[i].y][x[i].z].w,m[x[i].z][x[i].y].w);
		if(ans < min(x[i].y/2.0,min(x[i].z/2.0,zz/2.0)))
		{
			nn = 2,w1 = i + 1;
			if(m[x[i].y][x[i].z].w > m[x[i].z][x[i].y].w)
				w2 = m[x[i].y][x[i].z].i + 1;
			else
				w2 = m[x[i].z][x[i].y].i + 1;
			ans = min(x[i].y/2.0,min(x[i].z/2.0,zz/2.0));
		}

		data chk;
		chk.i = i;
		chk.w = x[i].z;
		m[x[i].x][x[i].y] = max(m[x[i].x][x[i].y],chk);

		chk.i = i;
		chk.w = x[i].x;
		m[x[i].y][x[i].z] = max(m[x[i].y][x[i].z],chk);

		chk.i = i;
		chk.w = x[i].y;
		m[x[i].x][x[i].z] = max(m[x[i].x][x[i].z],chk);
	}
	printf("%d\n",nn);
	if(nn == 1)
		printf("%d\n",w1);
	else printf("%d %d\n",w2,w1);
	return 0;
}