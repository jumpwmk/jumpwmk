#include <stdio.h>
#include <algorithm>

#define pii pair<int, int>
#define pll pair<LL, LL>
#define F first
#define S second
#define B begin()
#define E end()
#define MOD 1000000007
#define itt iterator
#define ritt reverse_iterator
#define LL long long

#define PI (4 * atan(1))

using namespace std;

int n, w, k, h[100005], dif[100005], f, b, m, mn = 2e9, zero, cnt;

int main()
{

		freopen("../test.in","r",stdin);
		freopen("../test.out","w",stdout);

	scanf("%d %d %d", &n, &w, &k);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
		b = max(b, h[i]);
	}

	while(f <= b)
	{
		m = (f + b) / 2;
		zero = 0;
		cnt = 0;
		for(int i = 0; i < n; ++i)
			dif[i] = h[i] - m;
		for(int i = 0; i < n; ++i)
		{
			if(dif[i] > zero)
			{
				cnt += (dif[i] - zero);
				zero = dif[i];
				if(i + w < n)
					dif[i + w] += cnt;
			}
		}
		if(cnt <= k)
		{
			mn = min(mn, m);
			b = m - 1;
		}
		else
			f = m + 1;
	}
	printf("%d\n", mn);
	return 0;
}