#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	string str;
	int p;
	bool operator<(const pt &a)const
	{
		if(str == a.str)
			return p < a.p;
		return str < a.str;
	}
};

pt x[100010];

int main()
{
	int i,j,n,k;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		cin >> x[i].str;
		cin >> x[i].p;
	}
	sort(x,x+n);
	for(i=0;i<n;i++)
		cout << x[i].str << " " << x[i].p << endl;
	return 0;
}