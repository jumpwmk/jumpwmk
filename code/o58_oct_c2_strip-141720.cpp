#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[100100][100];
int n,m,k;
struct pt
{
	int x,y;
};

pt check(int xx,int yy)
{
	pt tmp;
	if(xx-yy > 10)
	{
		tmp.x = xx,tmp.y = 0;
		return tmp;
	}
	else if(yy - xx > 10)
	{
		tmp.x = yy-10,tmp.y = 20;
		return tmp;
	}
	else
	{
		tmp.y = 10-xx+yy;
		tmp.x = xx;
		return tmp;
	}
}

int main()
{
	int i,j,k,x1,y1,x2,y2,a,b;
	pt tmp;
	freopen("../10.in","r",stdin);
	freopen("../10.sol","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		x1++,x2++,y1++,y2++;
		tmp = check(x1,y1);
		x[tmp.x][tmp.y]++;
		tmp = check(x2+1,y2+1);
		x[tmp.x][tmp.y]++;
		tmp = check(x2+1,y1);
		x[tmp.x][tmp.y]--;
		tmp = check(x1,y2+1);
		x[tmp.x][tmp.y]--;
	}
	for(i=1;i<=100000;i++)
	{
		for(j=0;j<=20;j++)
		{
			if(j-1 < 0)
				x[i][j] += x[i-1][j]-x[i-1][j]+x[i-1][j+1];
			else
				x[i][j] += x[i][j-1]-x[i-1][j]+x[i-1][j+1];
		}
		x[i][21] = x[i][20];
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x1,&y1);
		x1++,y1++;
		tmp = check(x1,y1);
		printf("%d\n",x[tmp.x][tmp.y]);
	}
	return 0;
}