#include <map>
#include <stdio.h>
#include <queue>

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

int n, m, a[200005], srt[200005], mnodd = 1, mneven = 2, evencnt, oddcnt, cnt, id, x;
map<int, int> mmap;
queue<int> mq;
bool no;

int main()
{

        freopen("../test.in","r",stdin);
        freopen("../test.out","w",stdout);


    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
    	scanf("%d", &a[i]);
    	srt[i] = a[i];
    	++mmap[a[i]];
    	if(a[i] % 2 == 0)
    		++evencnt;
    	else
    		++oddcnt;
    }
    for(map<int, int>::itt it = mmap.B; it != mmap.E; ++it)
    {
    	if(it->S > 1)
    		mq.push(it->F);
    }

    sort(srt, srt + n);

    while(!mq.empty())
    {
    	x = mq.front();
    	if(mmap[x] == 1)
    	{
    		mq.pop();
    		continue;
    	}

    	while(mmap.find(mneven) != mmap.E && mneven <= m)
    		mneven += 2;
    	while(mmap.find(mnodd) != mmap.E && mnodd <= m)
    		mnodd += 2;

    	if(evencnt > oddcnt || (evencnt == oddcnt && x % 2 == 1))	//get odd
    	{
    		if(mnodd > m)
    		{
    			no = true;
    			break;
    		}
    		++mmap[mnodd];
    		--mmap[x];
    		if(evencnt > oddcnt)
    		{
    			--evencnt;
    			++oddcnt;
    		}
    		mnodd += 2;
    	}
    	if(evencnt < oddcnt || (evencnt == oddcnt && x % 2 == 0))	//get even
    	{
    		if(mneven > m)
    		{
    			no = true;
    			break;
    		}
    		++mmap[mneven];
    		--mmap[x];
    		if(oddcnt > evencnt)
    		{
    			--oddcnt;
    			++evencnt;
    		}
    		mneven += 2;
    	}
    	++cnt;
    }

    id = 0;

    while(evencnt > oddcnt && !no)									//get odd
    {
    	if(srt[id] % 2 == 1)
    	{
    		++id;
    		continue;
    	}
    	while(mmap.find(mnodd) != mmap.E && mnodd <= m)
    		mnodd += 2;

    	if(mnodd > m)
		{
			no = true;
			break;
		}
    	++cnt;
    	++mmap[mnodd];
		--mmap[srt[id]];
		--evencnt;
		++oddcnt;
		mnodd += 2;
		++id;
    }

    id = 0;
    
    while(oddcnt > evencnt && !no)									//get even
    {
    	if(srt[id] % 2 == 0)
    	{
    		++id;
    		continue;
    	}
    	while(mmap.find(mneven) != mmap.E && mneven <= m)
    		mneven += 2;

    	if(mneven > m)
		{
			no = true;
			break;
		}

    	++cnt;
    	++mmap[mneven];
		--mmap[srt[id]];
		--oddcnt;
		++evencnt;
		mneven += 2;
		++id;
    }

    if(no)
    	printf("-1\n");
    else
    {
    	id = 0;
    	printf("%d\n", cnt);
    	for(int i = 0; i < n; ++i)
    	{
    		if(mmap[a[i]] == 1)
    		{
				printf("%d ", a[i]);
				mmap[a[i]] = 0;
    		}
    		else
    		{
    			while(mmap[srt[id]] == 0)
    				++id;
    			printf("%d ", srt[id]);
    			mmap[srt[id]] = 0;
    		}
    	}
    }
    return 0;
}

