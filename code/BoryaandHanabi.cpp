#include <stdio.h>
#include <algorithm>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int str[500];
int state[6][6];
int cnt[6][6];
bool chk[11];
int scan[6][6];
char x[110][2];
int n;
int ans = 100;

void loop()
{
	int i,j;
	for(i = 1; i <= 5; i++)
	{
		if( chk[ i ] )
		{
			int res = 0, tmp;
			for(j = 1; j <= 5; j++)
			{
				if(state[i][j])
				{
					res++;
					tmp = j;
				}
			}
			if(res == 1)
			{
				state[i][tmp] = 0;
			}
		}
	}
	for(j = 1; j <= 5; j++)
	{
		if( chk[ j + 5 ] )
		{
			int res = 0, tmp;
			for(i = 1; i <= 5; i++)
			{
				if(state[i][j])
				{
					res++;
					tmp = i;
				}
			}
			if(res == 1)
			{
				state[tmp][j] = 0;
			}
		}
	}

}

bool solution()
{
	int i,j;
	memset(cnt, 0 ,sizeof(cnt));
	for(i = 1; i <= 5; i++)
	{
		for(j = 1; j <= 5; j++)
		{
			state[i][j] = scan[i][j];
		}
	}
	for(i = 1; i <= 5; i++)
	{
		if(chk[i])
		{
			for(j = 1;j <= 5; j++)
			{
				cnt[i][j]++;
			}
		}
	}
	for(j = 1; j <= 5; j++)
	{
		if(chk[j+5])
		{
			for(i = 1; i <= 5; i++)
			{
				cnt[i][j]++;
			}
		}
	}
	for(i = 1; i <= 5; i++)
	{
		for(j = 1; j <= 5; j++)
		{
			if(cnt[i][j] == 2)
			{
				state[i][j] = 0;
			}
		}
	}

	loop();
	loop();
	loop();
	loop();
	loop();
	loop();
	loop();
	loop();
	loop();
	loop();
	loop();
	loop();

	int res = 0;
	for(i = 1; i <= 5; i++)
	{
		for(j = 1; j <= 5; j++)
		{
			if(state[i][j])
				res++;
		}
	}
	
	if(res <= 1)
		return true;

	return false;
}

void play(int state,int cnt)
{
	if(state == 11)
	{
		if(solution())
			ans = min(cnt,ans);
		return ;
	}
	chk[state] = true;
	play(state+1,cnt+1);
	chk[state] = false;
	play(state+1,cnt);
}

int main()
{
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf(" %s",x[i]);
	}
	str['R'] = 1, str['G'] = 2, str['B'] = 3, str['Y'] = 4, str['W'] = 5;
	for (int i = 0; i < n; ++i)
	{
		state[str[x[i][0]]][x[i][1] - '0'] = 1;
		scan[str[x[i][0]]][x[i][1] - '0'] = 1;
	}
	
	play(1,0);
	printf("%d\n",ans);
	return 0;
}