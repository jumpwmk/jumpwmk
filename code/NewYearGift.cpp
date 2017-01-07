/*
TASK: New Year Gift
LANG: C++
AUTHOR: PeaTT~
*/
#include <queue>
#include <stdio.h>

using namespace std;

#define N 100000
int a[N], countt;
vector<int> g[N];

// struct pt
// {
//     int a,b;
// };

// pt edge[100100];

void dfs(int from, int x) {
    for(int v:g[x])
        if( v != from )
            dfs(x, v);
    if( g[x].size() == 1 )
        a[countt ++] = x;
}

int main(){

    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);

	int i,x,y,n,m,half;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		g[i].clear();
	for(i=0;i<n-1;i++){
		scanf("%d %d",&x,&y);
        // edge[i].a = x,edge[i].b = y;
		g[x].push_back(y);
        g[y].push_back(x);
	}
	countt=0;
    dfs(-1, 1);
	printf("%d\n",(countt + 1) / 2);
    // printf("%d\n",n);
    // for(i=0;i<n-1;i++)
    // {
    //     printf("%d %d\n",edge[i].a,edge[i].b);
    // }
	if(m==2){
        half = countt/2;
        for(i = 0; i < countt / 2; i++)
            printf("%d %d\n", a[i], a[i+half]);
        if(countt&1)
			printf("%d %d\n", a[countt-1-half], a[countt-1]);
    }
    return 0;
}
