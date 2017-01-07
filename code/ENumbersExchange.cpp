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

int n, m, a[200005], mnodd = 1, mneven = 2, evencnt, oddcnt, cnt, id, x;
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
        ++mmap[a[i]];
        if(mmap[a[i]] > 1)
            mq.push(i);
        if(a[i] % 2 == 0)
            ++evencnt;
        else
            ++oddcnt;
    }

    while(!mq.empty())
    {
        x = mq.front();
        mq.pop();

        while(mmap.find(mneven) != mmap.E && mneven <= m)
            mneven += 2;
        while(mmap.find(mnodd) != mmap.E && mnodd <= m)
            mnodd += 2;

        if(evencnt > oddcnt || (evencnt == oddcnt && a[x] % 2 == 1))    //get odd
        {
            if(mnodd > m)
            {
                no = true;
                break;
            }
            ++mmap[mnodd];
            --mmap[a[x]];
            a[x] = mnodd;
            if(evencnt > oddcnt)
            {
                --evencnt;
                ++oddcnt;
            }
        }
        if(evencnt < oddcnt || (evencnt == oddcnt && a[x] % 2 == 0))    //get even
        {
            if(mneven > m)
            {
                no = true;
                break;
            }
            ++mmap[mneven];
            --mmap[a[x]];
            a[x] = mneven;
            if(oddcnt > evencnt)
            {
                --oddcnt;
                ++evencnt;
            }
        }
        ++cnt;
    }

    id = 0;

    while(evencnt > oddcnt && !no)                                  //get odd
    {
        if(a[id] % 2 == 1)
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
        --mmap[a[id]];
        --evencnt;
        ++oddcnt;
        ++id;
    }

    id = 0;

    while(oddcnt > evencnt && !no)                                  //get even
    {
        if(a[id] % 2 == 0)
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
        --mmap[a[id]];
        --oddcnt;
        ++evencnt;
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
                while(mmap[a[id]] == 0)
                    ++id;
                printf("%d ", a[id]);
                mmap[a[id]] = 0;
            }
        }
    }    return 0;
}

