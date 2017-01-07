#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
struct tii{
	int x,y,type,time;
};

tii tmp;
int vx[] = {-1,0,1,-1,1,-1,0,1}, vy[] = {-1,-1,-1,0,0,1,1,1};
void solve()
{
	queue <tii> q;
	char in;
	int mtime[10][10][32],MIN=2000; // min time
	int a[10][10],cnt=0,sx,sy;
	int x,y,nx,ny,type,time;
	
	for (int i=0;i<10;i++)
		for (int j=0;j<10;j++)
			for (int k=0;k<32;k++)
				mtime[i][j][k] = 2000;
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++)
		{
			scanf(" %c",&in);
			a[i][j] = 0; 
			if (in == 'x')
				a[i][j] = ++cnt;
			else if (in == 'K' || in == 'X' )
				a[i][j] = -1;
			else if (in == 'k')
				a[i][j] = 10;
			else if (in == 'Q')
				sx = i, sy = j;
		}
	// q.push(tii{sx,sy,1,0});
	tmp.x = sx,tmp.y = sy,tmp.type = 1,tmp.time = 0;
	q.push(tmp);
	mtime[sx][sy][1] = 0; 
	// printf("%d %d\n",sx,sy );
	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		type = q.front().type;
		time = q.front().time;
		// mtime[nx][ny][type] = time[]
		// printf("%d %d %d %d\n",x,y,time,type );
		q.pop();
		if (time > 10) continue;
		for (int i=0;i<8;i++) // dir
			for (int j=1;j<=8;j++) // dist
			{	
				// printf("%d %d %d\n",x,y,i );
				nx = x+j*vx[i],ny = y+j*vy[i];
				if (nx < 1 || nx > 8 || ny < 1 || ny > 8) break;
				if (a[nx][ny] < 0 ) break; // can't go
				if (0 <= a[nx][ny] && a[nx][ny] < 10 )
				{
					if (time+1 < mtime[nx][ny][(type|(1<<a[nx][ny]))]) 
					{
						mtime[nx][ny][(type|(1<<a[nx][ny]))] = time+1;
						tmp.x = nx,tmp.y = ny,tmp.type = (type|(1<<a[nx][ny])),tmp.time = time+1;
						q.push(tmp);
					}
					if ((type & (1<<a[nx][ny])) == 0) // eat and stop
					{
						break ;
					}
					// printf("P %d %d %d %d  from %d %d\n",nx,ny,type|(1<<a[nx][ny]),time,x,y );
				}

				if (a[nx][ny] == 10 && type == 31)
				{	
					// printf("E %d %d %d %d  from %d %d\n",nx,ny,type,time,x,y );
					MIN = min(MIN,time+1);
					break;
				}
				else if (a[nx][ny] == 10)
					break;
			}
	}
	printf("%d\n",MIN );
	return ;
}


int main()
{
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)
		solve();
	return 0;
}