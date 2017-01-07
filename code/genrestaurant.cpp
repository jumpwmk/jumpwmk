#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define mod 1000000
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int i,j;
};

pt e[330];
int x[330][330];
int data[330];
int chk[330];

int myrandom (int i) { return std::rand()%i;}

int main()
{
	int i,j,n = 300,t = 2,k = 20,tmp,m = 0,weight = mod;
	srand(time(NULL));
	freopen("../test.in","r",stdin);
	freopen("../20.in","w",stdout);
	printf("%d %d\n",n,t);
	// printf("%d\n",mod);
	for(i=1;i<=n;i++)
	{
		data[i] = i;
	}
	random_shuffle(data+1,data+n+1,myrandom);
	// for(i=1;i<=n;i++)
		// printf("%d\n",data[i]);
	for(i=0;i<k;i++)
	{
		e[m].i = data[1],e[m++].j = data[i+2];
		// printf("%d %d\n",data[1],data[i+2]);
		chk[i] = data[i+2];
	}
	for(i=k+2;i<=n;i++)
	{
		tmp = rand()%k;
		e[m].i = chk[tmp],e[m++].j = data[i];
		// printf("%d %d\n",chk[tmp],data[i]);
		chk[tmp] = data[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i != j)
				x[i][j] = INF;
		}
	}
	for(i=0;i<m;i++)
	{
		x[e[i].i][e[i].j] = rand()%weight + 1;
		x[e[i].j][e[i].i] = x[e[i].i][e[i].j];
	}
	// for(i=1;i<=n;i++)
	// {
	// 	for(j=1;j<=n;j++)
	// 	{
	// 		printf("%d ",x[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(x[i][j] > x[i][k] + x[k][j])
					x[i][j] = x[i][k] + x[k][j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
	return 0;
}