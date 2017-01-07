#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pii;
int N;
vector<pii> candies;
vector<long long> wagons;
vector<pair<pii, int> > output;

using namespace std;

int main()
{
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
	{
		long long p, t;
		scanf("%lld%lld", &p, &t);
		candies.push_back(pii(p + t, t - p));
	}
	sort(candies.begin(), candies.end());
	for (int i = 0; i < N; i++) 
	{
		long long a = candies[i].first, b = -candies[i].second;
		int pos = lower_bound(wagons.begin(), wagons.end(), b) - wagons.begin();
		if (pos == (int) wagons.size()) 
		{
			wagons.push_back(b);
		} 
		else 
		{
			wagons[pos] = b;
		}
		output.push_back(make_pair(pii((a + b) / 2, (a - b) / 2), pos + 1));
	}
	printf("%lu\n", wagons.size());
	for (int i = 0; i < N; i++) {
		printf("%lld %lld %d\n", output[i].first.first, output[i].first.second, output[i].second);
	}
	return 0;
}