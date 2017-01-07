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

arg tmp;

bool operator< (const arg &a, const arg &b) {
    return a.P<b.P;
}

vector<arg> tbl;

long long dis(int a,int b) {
    return (long long)(x[a]-x[b])*(x[a]-x[b])+(long long)(y[a]-y[b])*(y[a]-y[b]);
}

int mark[1010];

int main () {
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
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
        tmp.P = 0;
        tmp.val = n-a;
        tbl.push_back(tmp);
        for (int k=0;k<a;k++) {
            scanf("%d",&c);
            tmp.P = dis(i,c);
            tmp.val = 1;
            tbl.push_back(tmp);
            mark[c]=i;
        }
        for (int k=1;k<=n;k++) {
            if (mark[k]!=i) {
                tmp.P = dis(i,k)+1;
                tmp.val = -1;
                tbl.push_back(tmp);
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
