#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
double inp[5][1000],shelter[5][1000];
double MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
  int n = int(cost.size());

  // construct dual feasible solution
  VD u(n);
  VD v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }
  
  // construct primal solution satisfying complementary slackness
  Lmate = VI(n, -1);
  Rmate = VI(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
	Lmate[i] = j;
	Rmate[j] = i;
	mated++;
	break;
      }
    }
  }
  
  VD dist(n);
  VI dad(n);
  VI seen(n);
  
  // repeat until primal solution is feasible
  while (mated < n) {
    
    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;
    
    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++) 
      dist[k] = cost[s][k] - u[s] - v[k];
    
    int j = 0;
    while (true) {
      
      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;
      
      // termination condition
      if (Rmate[j] == -1) break;
      
      // relax neighbors
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
	if (dist[k] > new_dist) {
	  dist[k] = new_dist;
	  dad[k] = j;
	}
      }
    }
    
    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];
    
    // augment along path
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;
    
    mated++;
  }
  
  double value = 0;
  for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];
  
  return value;
}
double path(double x1,double y1,double x2,double y2)
{
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
VVD dist;

struct pt
{
  int i,j;
  double w;
  bool operator < (const pt &a)const
  {
    return w < a.w;
  }
};

pt di[1000100];

int main()
{
    // freopen("../test.in","r",stdin);
    // freopen("../test.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {

      scanf("%lf%lf",&inp[0][i],&inp[1][i]);

    }
    for(int i=0;i<n;i++)
    {
      scanf("%lf%lf",&shelter[0][i],&shelter[1][i]);
    }
    double mx;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        mx = max(path( inp[0][i], inp[1][i], shelter[0][j], shelter[1][j]) , mx );
      }
    }
    double res;
    int e = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        di[e].i = i;
        di[e].j = j;
        di[e].w = path( inp[0][i], inp[1][i], shelter[0][j], shelter[1][j] );
        e++;
      }
    }
    int l = 0, r = e-1;
    sort(di,di+e);
    while(l < r)
    {
      int mid = (l+r)/2;
      // printf("%d %d %d\n",l,r,mid);
      dist.assign( n, VD(n,0) );
      // dist.resize( n, VD(n) );
      VI left, right;
      for(int i=0;i<e;i++)
      {
        if(i <= mid)
          dist[di[i].i][di[i].j] = di[i].w;
        else
          dist[di[i].i][di[i].j] = 2000000000;
      }    
      res = MinCostMatching( dist, left, right );
      // printf("= %lf \n",res);
      if(res - 1e-7 >= mx*n + 50)
        l = mid + 1;
      else 
        r = mid;
    }
    VI left, right;
    for(int i=0;i<e;i++)
    {
      if(i <= l)
        dist[di[i].i][di[i].j] = di[i].w;
      else
        dist[di[i].i][di[i].j] = 2000000000;
    }    
    res = MinCostMatching( dist, left, right );
    printf("%.5lf\n%.5lf\n",di[l].w,res);

}