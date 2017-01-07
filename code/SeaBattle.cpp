#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char x[200200];
int res[200200];
int data[200200];

int main()
{
	int i,j,n,a,b,k,tmp = 0,cnt = 0,chk = 0,mx = 0,cc = 0,ans = 0;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d %d %d %d",&n,&a,&b,&k);
	scanf("%s",&x[1]);
	int j = 0;
	for(i = 1;i <= n;i++)
	{
		if(x[i] == '1')
		{
			if(tmp >= b)
			{
				if(mx < tmp)
				{
					mx = tmp;
					cc = i-tmp;
				}
				data[chk] = tmp/b;
				chk++;
			}
			cnt += tmp/b;
			tmp = 0;
		}
		else
		{
			tmp++;
		}
	}
	cnt += tmp/b;
	if(tmp >= b)
	{
		data[chk] = tmp/b;
		chk++;
	}
	if(chk >= a)
	{
		for(i = cc+b-1; i <= tmp; i += cc)
		{
			res[ans] = i;
			ans++;
		}
		
	}
	return 0;
}