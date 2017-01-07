#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

string str;
map <string, int> m;
int x[3000];

int main()
{
	int i,j,n,ans = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cin >> str;
		m[str] = i;
	}
	for(i=1;i<=n;i++)
	{
		cin >> str;
		x[i] = m[str];
	}
	ans = (n*(n-1))/2;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(x[i] > x[j])
				ans--;
		}
	}
	printf("%d/%d\n",ans,(n*(n-1))/2);
	return 0;
}