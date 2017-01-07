#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int x[1010];
int y[1010];

typedef struct {
    long long P;
    int val;
} arg;

bool operator< (const arg &a, const arg &b) {
    return a.P<b.P;
}

vector<arg> tbl;

long long dis(int a,int b) {
    return (long long)(x[a]-x[b])*(x[a]-x[b])+(long long)(y[a]-y[b])*(y[a]-y[b]);
}

int mark[1010];

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    int a;
    int b;
    int c;
    for (int i=1;i<=n;i++) {
        scanf("%d",&a);
        tbl.push_back(arg{0,n-a});
        for (int k=0;k<a;k++) {
            scanf("%d",&c);
            tbl.push_back(arg{dis(i,c),1});
            mark[c]=i;
        }
        for (int k=1;k<=n;k++) {
            if (mark[k]!=i) {
                tbl.push_back(arg{dis(i,k)+1,-1});
            }
        }
    }
    sort(tbl.begin(),tbl.end());
    long long last=-1;
    int maxx=0;
    long long maxP=0;
    int cur=0;
    for (int i=0;i<tbl.size();i++) {
        //printf("%lld %d\n",tbl[i].P,tbl[i].val);
        if (tbl[i].P!=last) {
            //maxx=max(maxx,cur);
            if (cur>maxx) {
                maxx=cur;
                maxP=last;
            }
        }
        cur+=tbl[i].val;
        last=tbl[i].P;
    }
    printf("%lld %d\n",maxP,n*n-maxx);
    return 0;
}
