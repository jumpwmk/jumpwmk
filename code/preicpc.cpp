#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <time.h>

#define SQR(_x) ((_x)*(_x))
#define NL printf("\n")
#define LL long long
#define DB double
#define PB push_back
#define INF 1<<30
#define LB lower_bound
#define UB upper_bound
#define F front
#define PQ priority_queue

using namespace std;

int main()
{
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	int t;
	int lenx,leny,i,j;
	bool ans;
	bool c;
	char x[20000],y[20000],chk;
	scanf("%d",&t);
	while(t--)
	{
		int cnt = 0,cnt2,chk2;
		scanf(" %s %s",x,y);
		lenx = strlen(x);
		leny = strlen(y);
		ans = true;
		for(i = 0,j = 0; i < lenx and j < leny;)
		{
			cnt = 0;
			chk = y[j];
			for(;j < leny;j++)
			{
				if(chk != y[j])
					break;
				cnt++;
			}
			// printf("%c %d\n",chk,cnt);
			while(true)
			{
				cnt2 = 0;
				chk2 = x[i];
				c = false;
				for(;i < lenx;i++)
				{
					if(chk2 != x[i] and x[i] != '*' and x[i] != '+')
						break;
					if(x[i] == chk2 and x[i+1] != '*')
						cnt2++,c = true;
					if(x[i] == '*' or x[i] == '+')
						c = true;
				}
				if(chk != chk2 and cnt2 > 0)
				{
					ans = false;
					break;
				}
				if(chk2 == chk)
					break;
			}
			// printf("%c %d %d\n",chk2,cnt2,c);
			if(cnt < cnt2)
			{
				ans = false;
				break;
			}
			if(cnt > cnt2 and c == false)
			{
				ans = false;
				break;
			}
		}	
		while(i < lenx)
		{
			cnt2 = 0;
			chk2 = x[i];
			c = false;
			for(;i < lenx;i++)
			{
				if(chk2 != x[i] and x[i] != '*' and x[i] != '+')
					break;
				if(x[i] == chk2 and x[i+1] != '*')
					cnt2++,c = true;
				if(x[i] == '*' or x[i] == '+')
					c = true;
			}
			if(cnt2 > 0)
				ans = false;
		}
		if(i != lenx or j != leny)
			ans = false;
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
