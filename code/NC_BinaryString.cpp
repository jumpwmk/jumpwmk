#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

vector <int > v[21];
vector <int >::iterator it; 
char str[100100],tmp[22];
long long mic[100100];
int pow[22];

int main()
{
	int ii,i,j,n,m,k;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	pow[0] = 1;
	for(i=1;i<=21;i++)
	{
		pow[i] = pow[i-1] * 2;
	}
	while(n--)
	{
		scanf(" %s",tmp);
		k = 0;
		m = strlen(tmp);
		for(i=0;i<m;i++)
		{
			if(tmp[i] == '1')
				k += pow[m-i-1];
		}
		v[m].push_back(k);
	}
	scanf(" %s",str);
	m = strlen(str);
	mic[0] = 1;
	for(i=1;i<=20;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	for(i=1;i<=m;i++)
	{
		k = 0;
		for(j=1;j<=20 && i-j >= 0;j++)
		{
			if(str[i-j] == '1')
			{
				k += pow[j-1];
			}
			it = lower_bound(v[j].begin(),v[j].end(),k);
			if(it != v[j].end() && *it == k)
			{
				mic[i] += mic[i-j];
			}
		}
		mic[i] %= 1000000007;
	}
	printf("%lld\n",mic[m]);
	return 0;
}