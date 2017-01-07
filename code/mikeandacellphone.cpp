#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

// using namespace std;

struct pt
{
	int i,j;
};

int x[4][4];
pt chk[10];
char str[10];
pt check[20];
int n;

bool play(int ii,int jj,int state)
{
	// printf("%d %d %d\n",ii,jj,state);
	if(state == n)
		return true;
	ii += check[state].i;
	jj += check[state].j;
	if(ii < 0 || jj < 0)
		return false;
	if(ii > 3 || jj > 2)
		return false;
	if(ii == 3 && jj != 1)
		return false;
	return play(ii,jj,state+1);
}

int main()
{
	int i,j,cnt = 0;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&n);
	scanf(" %s",str);
	chk[1].i = 0,chk[1].j = 0;
	chk[2].i = 0,chk[2].j = 1;
	chk[3].i = 0,chk[3].j = 2;
	chk[4].i = 1,chk[4].j = 0;
	chk[5].i = 1,chk[5].j = 1;
	chk[6].i = 1,chk[6].j = 2;
	chk[7].i = 2,chk[7].j = 0;
	chk[8].i = 2,chk[8].j = 1;
	chk[9].i = 2,chk[9].j = 2;
	chk[0].i = 3,chk[0].j = 1;
	for(i=0;i<n-1;i++)
	{
		check[i].i = chk[str[i+1]-'0'].i-chk[str[i]-'0'].i;
		check[i].j = chk[str[i+1]-'0'].j-chk[str[i]-'0'].j;
		// printf("%d %d\n",check[i].i,check[i].j);
	}
	for(i=0;i<=9;i++)
	{
		if(play(chk[i].i,chk[i].j,0))
		{
			// printf("%d\n",i);
			cnt++;
		}
	}
	if(cnt > 1)
		printf("NO\n");
	else printf("YES\n");
	return 0;
}