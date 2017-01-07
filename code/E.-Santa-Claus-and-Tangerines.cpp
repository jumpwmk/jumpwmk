#include <algorithm>
#include <stdio.h>
#include <set>

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

struct compare
{
	bool operator () (int x, int y)
	{
		return x > y;
	}
};

int n, k, a[1000005], cur[10000005], x, ans, val, ccnt;
LL sum, cnt;
set<int, compare> mset;

void upd(int id, int num)
{
	if(val <= id)
		ccnt += num;
	cur[id] += num;
}

int main()
{

	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i)
    {
    	scanf("%d", &a[i]);
    	sum += a[i];
    }

    if(sum < k)
    {
		printf("-1\n");
		return 0;
	}

	cnt = n;
	for(int i = 0; i < n; ++i)
	{
		printf(">> %d -> %d\n", a[i], cur[a[i]] + 1);
		mset.insert(a[i]);
		++cur[a[i]];
	}

	if(n >= k)
	{
		for(set<int, compare>::itt it = mset.B; it != mset.E; ++it)
		{
			val = *it;
			ccnt += cur[*it];
			if(ccnt >= k)
				break;
		}
	}

	while(*mset.B != 1)
	{
		x = *mset.B;
		printf("%d: %d\n", x, cur[x]);
		mset.erase(mset.B);

		ccnt -= cur[x];
		if(x % 2 == 1)
		{
			upd(x/2, cur[x]);
			upd(x/2 + 1, cur[x]);
			mset.insert(x/2);
			mset.insert(x/2 + 1);
		}
		else
		{
			upd(x/2, 2 * cur[x]);
			mset.insert(x/2);
		}
		printf("%d + %d -> %d\n", cnt, cur[x], cnt + cur[x]);
		cnt += cur[x];
		return 0;

		if(cnt >= k)
		{
			while(ccnt < k)
			{
				printf("%d: %d\n", val, ccnt);
				val = *mset.upper_bound(val);
				ccnt += cur[val];
			}
			while(ccnt - cur[val] >= k)
			{
				ccnt -= cur[val];
				val = *(--mset.find(val));
			}
			ans = max(ans, val);
		}
	}

	ans = max(ans, val);

    printf("%d", ans);
    return 0;
}

