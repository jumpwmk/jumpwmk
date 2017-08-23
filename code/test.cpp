#include <stdio.h>
#include <iostream>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int main()
{
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);

	pair<int, int> A[5];

	for(int i = 0; i < 5; i++)
	{
		A[i] = {i,i*i};
		cout << A[i].first << " " << A[i].second << endl;
	}

	return 0;
}