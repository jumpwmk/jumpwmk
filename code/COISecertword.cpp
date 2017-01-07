#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

char x[1000100];
char tmp[1000100];
int mic[1000100];
int mark[1000100];
int chk[1000100];
int cnt[1000100];
int sum[1000100];
char nott[1000100];

int main()
{
	int i,j,k,n,t,lenx,lentmp,res = 0;
	char jump;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		jump = true;
		scanf(" %s %s",&x[1],&tmp[1]);
		lenx = strlen(&x[1]);
		lentmp = strlen(&tmp[1]);
		mic[1] = 0;
		j = 0;
		// printf("%s\n",&tmp[1]);
		for(i = 2;i<=lentmp;i++)
		{
			while(j>0 && tmp[j+1] != tmp[i])
				j = mic[j];
			// printf("%c %c\n",tmp[j+1],tmp[i]);
			if(tmp[j+1] == tmp[i])
			{
				j++;
			}
			mic[i] = j;
		}
		res = 0;
		j = 0;
		sum[0] = 0;
		for(i = 1;i<=lenx;i++)
		{
			while(j>0 && tmp[j+1] != x[i])
				j = mic[j];
			if(j == 0)
				res = 0;
			if(tmp[j+1] == x[i])
			{
				j++;
			}
			sum[i] = sum[i-1];
			if(j == lentmp)
			{
				// printf("-- \n");
				res += lentmp;
				mark[i-res+1] = k;
				j = chk[i-res];
				res = lentmp + cnt[i-res] + sum[i] - sum[i-res];
				sum[i] += lentmp;
			}
			cnt[i] = res;
			chk[i] = j;
		}
		res = 0;
		j = 0;
		for(i=1;i<=lenx;i++)
		{
			if(mark[i] == k)
				res += lentmp;
			if(res == 0)
			{
				nott[j++] = x[i];
				jump = false;
			}
			else
				res--;

		}
		nott[j] = 0;
		res = 0;
		if(jump == true)
		{
			printf("No COI Secret Code"); 
		}
		else
			printf("%s",nott);
		printf("\n");
	}
	return 0;
}