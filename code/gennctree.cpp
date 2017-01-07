#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int a[100100];
set <int > ::iterator it;
set <int > s;
vector <int > v;
int n = 100000;

void solution(int m)
{
	int i,x;
	printf("%d\n",n);
	while(s.size() < m)
	{
		x = rand()%1000000;
		s.insert(x);
	}
	for(it = s.begin();it != s.end(); it++)
	{
		v.push_back(*it);
	}
	for(i=0;i<n;i++)
	{
		x = rand()%m;
		a[i] = v[x];
		x = rand()%1000000;
		printf("%d ",min((x+a[i]),1000000));
	}
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	v.clear();
	s.clear();
}

int main()
{
	int i,j,t = 10;
	freopen("../test.in","r",stdin);
	freopen("../10.in","w",stdout);
	srand(time(NULL));
	printf("%d\n",t);
	solution(3);
	solution(50);
	solution(100);
	solution(500);
	solution(3000);
	solution(10000);
	solution(100000);
	solution(5000);
	solution(30);
	solution(70);
	return 0;
}