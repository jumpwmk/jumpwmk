#include <stdio.h>
#include <utility>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;
pair<int,int > brd[1010][1010];
pair<int,int > dp2[1010][1010];
pair<int,int > dp5[1010][1010];
pair<int,int > c;

int chx,chy;
int zero= 0;
inline void c25(int i,int j){
	int x;
	scanf("%d",&x);
	if(x == 0)
	{
		zero=1;
		chx = j,chy = i;
		brd[i][j]={99999,99999};
		return;
	}
	brd[i][j].first = __builtin_ctz(x);
	while((x%5)==0)
		brd[i][j].second++,x/=5;
}
int n;
int main(){
    int i,j,x,y;

	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c25(i,j);
		}
	}

	dp2[0][0]={0,0};
	dp5[0][0]={0,0};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(i!=0){
				dp2[i][j] = dp2[i-1][j];
				if(j!=0){
					dp2[i][j] = min(dp2[i][j] , dp2[i][j-1]);
				}
			}else if(j!=0){
				dp2[i][j] = dp2[i][j-1];
			}
			dp2[i][j].first = dp2[i][j].first + brd[i][j].first;
			dp2[i][j].second = dp2[i][j].second + brd[i][j].second;
			if(i!=0){
				dp5[i][j] = dp5[i-1][j];
				if(j!=0){
					dp5[i][j] = min(dp5[i][j] , dp5[i][j-1]);
				}
			}else if(j!=0){
				dp5[i][j] = dp5[i][j-1];
			}
			dp5[i][j].first = dp5[i][j].first + brd[i][j].second;
			dp5[i][j].second = dp5[i][j].second + brd[i][j].first;
		}
	}
	string out="";
    x=n-1;y=n-1;
	if(dp2[n-1][n-1] < dp5[n-1][n-1])
	{
        c=dp2[y][x];
        if(min(dp2[y][x].first,dp2[y][x].second) >= 1 && zero)
        {
        	printf("1\n");
        	for(i=0; i < chy;i++)
        		printf("D");
        	for(j=0; j < chx;j++)
        		printf("R");
        	for(;i<n-1;i++)
        		printf("D");
        	for(;j<n-1;j++)
        		printf("R");
        	printf("\n");
        	return 0;
        }
        else
			printf("%d\n",min(dp2[y][x].first,dp2[y][x].second));
		while (y!=0 or x!=0)
		{
			c = {c.first-brd[y][x].first,c.second-brd[y][x].second};
			if (y>0)
			{
				if (dp2[y-1][x].first == c.first && dp2[y-1][x].second == c.second)
				{
					out += 'D';
					y -= 1;
					continue;
				}
			}
			if (x>0)
			{
				if(dp2[y][x-1].first == c.first && dp2[y][x-1].first == c.first)
				{
					out+='R';
					x-=1;
					continue;
				}
            }
		}

	}else{
        c=dp5[y][x];
        if(min(dp5[y][x].first,dp5[y][x].second) >= 1 && zero)
        {
        	printf("1\n");
        	for(i=0; i < chy;i++)
        		printf("D");
        	for(j=0; j < chx;j++)
        		printf("R");
        	for(;i<n-1;i++)
        		printf("D");
        	for(;j<n-1;j++)
        		printf("R");
        	printf("\n");
        	return 0;
        }
        else
			printf("%d\n",min(dp5[y][x].first,dp5[y][x].second));
		while (y!=0 or x!=0)
		{
			c = {c.first-brd[y][x].second,c.second-brd[y][x].first};
			if (y>0)
			{
				if (dp5[y-1][x].first == c.first && dp5[y-1][x].second == c.second)
				{
					out += 'D';
					y -= 1;
					continue;
				}
			}
			if (x>0)
			{
				if(dp5[y][x-1].first == c.first && dp5[y][x-1].first == c.first)
				{
					out+='R';
					x-=1;
					continue;
				}
			}
		}
	}
	reverse(out.begin(),out.end());
	printf("%s",out.c_str());
	return 0;
}