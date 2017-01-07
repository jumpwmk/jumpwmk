#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <time.h>

#define SQR(_x) ((_x)*(_x))
#define NL printf("\n")
#define LL long long
#define DB doubleb
#define PB push_back
#define INF 1<<30
#define LB lower_bound
#define UB upper_bound
#define F front
#define PQ priority_queue

using namespace std;
string temp;
string rev;
int n,k,cc;
long long ans=0;
int chk = 0;
vector<int> v[100100];
vector< pair<int,int> >par;
struct data
{
	string str;
	int p;
}in[100100],real[100100];

bool cmp (data a, data b)
{

	if(a.str==b.str) 
		return a.p<b.p;
	return a.str<b.str;
}
void find(int n)
{
	int l=1,r=cc+1,mid;
	int p;

	while(l<=r)
	{
	
		mid = (l+r)/2;

		
		if(rev<real[mid].str)
		{
			r=mid-1;
		}
		if(rev>real[mid].str)
		{
			l=mid+1;
		}
		if(rev==real[mid].str)
		{
			
			int c1,c2;
			if(n==mid)
			{
				
				c1=v[n].size()-1;
				c2=v[n].size()-2;
				while(c1>=0 and c2>=0)
				{
					if(v[n][c1]+v[n][c2]>0)
					{

						ans+=v[n][c1]+v[n][c2];
						par.PB(make_pair(v[n][c1],v[n][c2]));
						if(v[n][c2] < 0)
						{
							chk = max(chk,-v[n][c2]);
							if(-v[n][c2] == 58)
								cout << v[n][c1] << v[n][c2] << endl;
						}
						c1-=2;
						c2-=2;
						if(not v[n].empty()) v[n].pop_back();
						if(not v[n].empty()) v[n].pop_back();
					}
					else break;
				}
			}
			else
			 { 
			
				c1=v[n].size()-1;
				c2=v[mid].size()-1;
				//  printf("%d %d == %s %s\n",n,mid,rev,real[mid].str);
				// printf("%d %d == %d %d\n",c1,c2,v[n][c1],v[mid][c2]);
				while(not v[n].empty() and not v[mid].empty())
				{

					if(v[n][c1]+v[mid][c2]>0) 
					{
						ans+=v[n][c1]+v[mid][c2];
						c1--;
						c2--;
						v[n].pop_back();
						v[mid].pop_back();
					}
					else break;
				}
			}
			break;
		}
	}
	return ;
}
int main()
{
	int p;

		freopen("../test.in","r",stdin);
		freopen("../test.out","w",stdout);

	cin >> k >> n;
	for(int i=1;i<=k;i++)
	{
		cin >> in[i].str;
		cin >> in[i].p;
	}
	sort(in+1,in+k+1,cmp);
	for(int i=0;i<k;i++)
	{

		if(in[i].str!=in[i+1].str and i!=k)
		{	
			
			v[++cc].PB(in[i+1].p);
			real[cc].str = in[i+1].str;
		}
		else
		{
			v[cc].PB(in[i+1].p);
		}
	}
	// for(int i=1;i<=cc;i++)
	// {
	// 	cout << "** " << real[i].str << ' ';
	// 	for(int j=0;j<v[i].size();j++)
	// 	{
	// 		printf("%d ",v[i][j]);
	// 	}
	// 	NL;
	// }
	for(int i=1;i<=cc;i++)
	{
		// printf("**** %s\n",real[i].str);
		int c=0;
		rev=real[i].str;
		reverse(rev.begin(),rev.end());
		// c = strcmp(rev,real[i].str);
		// cout << " === " << rev;
		if(rev==real[i].str) real[i].p=1;
		find(i);
	}

	int maxx1=0,sum_maxx=0,maxx2=0;
	for(int i=1;i<=cc;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			if(real[i].p==1)
			{
				if(v[i][j] > maxx1)
				{
					maxx1 = v[i][j];
				}
			}
		}
	}
	int t_maxx=0;
	for(int i=0;i<par.size();i++)
	{
		if(par[i].first>par[i].first+par[i].second)
		{
			maxx2=par[i].first;
			sum_maxx=par[i].first+par[i].second;
		}
	}
	if(ans+maxx1>ans-sum_maxx+maxx2 and ans+maxx1 > 0)
	{
		t_maxx = maxx1;
	}
	else if(ans-sum_maxx+maxx2 > 0)
	{
		t_maxx = maxx2-sum_maxx;
	}
	printf("%d %d\n",t_maxx,chk);
	if(ans+t_maxx > 0) cout << ans+t_maxx;
	else cout << '0';
	return 0;
}