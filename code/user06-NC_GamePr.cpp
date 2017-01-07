#include <cstdio>
#include <vector>

using namespace std;

bool isPrime[500100];

int memo[500100][2];

void initPrime() {
    isPrime[2]=true;
    for (int i=3;i<500100;i+=2) {
        isPrime[i]=true;
    }
    for (int i=3;i<800;i+=2) {
        if (!isPrime[i]) continue;
        for (int j=i*i;j<500100;j+=i) {
            isPrime[j]=false;
        }
    }
}

int recur(int num, int dep) {
    //printf("%d %d\n",num,dep);
    //printf("%d\n",isPrime[num]);
    if (memo[num][dep%2]) return memo[num][dep%2];
    if (isPrime[num]&&dep%2) return memo[num][dep%2]=-1;
    if (isPrime[num]&&(!(dep%2))) return memo[num][dep%2]=1;
    int sum=0;
    vector<int> factor;
    for (int i=2;i<=num;i++) {
        if (isPrime[i]&&num%i==0) {
            sum+=i;
            factor.push_back(i);
        }
    }
    printf("%d %d\n",num,sum);
    int val;
    if (dep%2) {
        val=-1;
        for (int i=0;i<factor.size();i++) {
            // printf("%d\n",sum-factor[i]);
            val = max(val,recur(sum-factor[i],dep+1));
            printf("%d\n",val);
        }
    } else {
        val=1;
        for (int i=0;i<factor.size();i++) {
            printf("%d\n",val);
            val = min(val,recur(sum-factor[i],dep+1));
        }
    }
    printf("-- %d\n",val);
    return memo[num][dep%2]=val;
}

int main () {
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    initPrime();
    int t;
    scanf("%d",&t);
    int x;
    while (t--) {
        scanf("%d",&x);
        printf("%d\n",(recur(x,1)==1)?1:2);
    }
    return 0;
}
