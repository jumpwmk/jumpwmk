#include <string.h>
#include <stdio.h>

#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define F first
#define S second
#define B begin()
#define E end()
#define MOD 1000000007
#define itt iterator
#define ritt reverse_iterator
#define LL long long

#define PI (4*atan(1))

using namespace std;

char s[10000005];
int plen[10000005], pdeg[10000005], slen, idfront = 0, idback = -1, center, dist;
LL ans;

int main()
{
   // freopen("D:\\Computer\\test.in","r",stdin);
//    freopen("D:\\Computer\\test.out","w",stdout);
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);

    scanf("%s",s);
    slen = strlen(s);

    // A part of Manacher's Algorithm
    for (int i = slen-1; i >= 0; --i)
    {
    	s[2*i] = s[i];
    	s[2*i+1] = 0;
    }
    slen=2*slen-1;
    for (int i = 0; i < slen; ++i)
    {
    	// printf("->%d : CEN: %d | IDF: %d | IDB: %d\n",i,center,idfront,idback);
    	if(i > idback)
    	{
    		while(plen[i] <= i && i + plen[i] < slen)
    		{
    			if(s[i+plen[i]] == s[i-plen[i]])
    				plen[i]++;
    			else
    				break;
    		}
    		idfront = i - plen[i] + 1;
    		idback = i + plen[i] - 1;
    		center = i;
    		if(idfront == 0)
    		{
    			pdeg[i] = pdeg[(i-1)/2] + 1;
    			ans += pdeg[i];
    		}
    	}
    	else
    	{
    		dist = i - center;
    		if(center - dist - plen[center-dist] + 1 < idfront)
    		{
    			plen[i] = center - idfront + 1;
    		}
    		else if(center - dist - plen[center-dist] + 1 == idfront)
    		{
    			plen[i] = plen[center-dist];
    			while(plen[i] <= i && i + plen[i] < slen)
	    		{
	    			if(s[i+plen[i]] == s[i-plen[i]])
	    				plen[i]++;
	    			else
	    				break;
	    		}
	    		idfront = i - plen[i] + 1;
	    		idback = i + plen[i] - 1;
	    		center = i;
	    		if(idfront == 0)
	    		{
	    			// printf("\'%c\' IN\n",s[i]);
	    			pdeg[i] = pdeg[(i-1)/2] + 1;
	    			ans += pdeg[i];
	    		}
    		}
    		else
    		{
    			plen[i] = plen[center-dist];
    		}
    	}
    	// printf(">>\'%c\': %d %d -> %lld\n",s[i],plen[i],pdeg[i],ans);
        printf("%d %lld\n",i,ans);
    }
    printf("%lld\n",ans);
    return 0;
}

