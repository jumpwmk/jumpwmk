#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

struct pt
{
	int s,e;
};

struct data
{
	int s,e,w;
};

pt e[100100];
vector <data > ans;
data tmptmp;
int a[303];
int b[303];
int n,m,V;
int chk[303];
int head[303];
int cnt[303];
queue <int > q;
vector <int > v[303];

int findhaed(int ii)
{
	int i,ha,tmp;
	tmp = ii;
	while(ii != head[ii])
		ii = head[ii];
	ha = ii;
	ii = tmp;
	while(ii != head[ii])
	{
		tmp = ii;
		ii = head[ii];
		head[tmp] = ha;
	}
	return ha;
}

int play(int ii,int ago,int w)
{
	int tmp,i,cnttmp = 0;
	// printf("%d\n",ii);
	if(a[ii] >= w)
	{
		a[ii] -= w;
		return w;
	}
	else cnttmp += a[ii],w -= a[ii];
	// printf("%d\n",w);
	for(i=0;i<v[ii].size();i++)
	{
		// printf("-- %d\n",v[ii][i]);
		if(chk[v[ii][i]] == 1 && v[ii][i] != ago)
		{
			tmp = play(v[ii][i],ii,w);
			cnttmp += tmp;
			a[ii] += tmp;
			tmptmp.s = v[ii][i],tmptmp.e = ii,tmptmp.w = tmp;
			ans.push_back(tmptmp);
			w = w - tmp;
			if(w == 0)
				break;
		}
	}
	a[ii] -= cnttmp;
	return cnttmp;
}

int play2(int ii,int ago,int w)
{
	int tmp,i,cnttmp = 0;
	// printf("- %d %d %d\n",ii,ago,wb);
	if(a[ii] + w <= V && ago != -1)
	{
		// printf("// %d\n",ii);
		a[ii] += w;
		return w;
	}

	// printf("= %d %d =\n",ii,w);
	for(i=0;i<v[ii].size();i++)
	{
		// printf("-- %d %d\n",v[ii][i],chk[v[ii][i]]);
		if(chk[v[ii][i]] == 1 && v[ii][i] != ago)
		{
			// printf("/ %d %d %d\n",ii,a[ii],v[ii][i]);
			tmp = play2(v[ii][i],ii,a[ii]);
			// printf("= %d %d %d\n",ii,v[ii][i],tmp);
			a[ii] -= tmp;
			tmptmp.s = ii,tmptmp.e = v[ii][i],tmptmp.w = tmp;
			ans.push_back(tmptmp);
			if(a[ii] == 0)
				break;
		}
	}
	// printf("%d %d %d\n",ii,w,V-a[ii]);
	tmp = a[ii];
	a[ii] += min(w,(V-a[ii]));
	// printf("%d\n",min(w,V-tmp));
	return min(w,(V-tmp));
}

int main()
{
	int i,j,ha,hb;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d %d %d",&n,&m,&V);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		head[i] = i,chk[i] = 1;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&e[i].s,&e[i].e);
		e[i].s++,e[i].e++;
		// printf("%d %d\n",e[i].s,e[i].e);
	}
	for(i=0;i<m;i++)
	{
		ha = findhaed(e[i].s);
		hb = findhaed(e[i].e);
		if(ha != hb)
		{
			head[ha] = hb;
			cnt[e[i].s]++,cnt[e[i].e]++;
			v[e[i].s].push_back(e[i].e);
			v[e[i].e].push_back(e[i].s);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(cnt[i] <= 1)
		{
			// printf("%d\n",i);
			q.push(i);
		}
	}
	while(!q.empty())
	{
		i = q.front();
		// printf("*** %d ***\n",i);
		q.pop();
		if(a[i] < b[i])
		{
			// printf("= %d %d %d\n",i,a[i],b[i]);
			ha = play(i,-1,b[i]);
			a[i] += ha;
			// printf("- %d %d %d\n",i,a[i],b[i]);
			if(a[i] != b[i])
			{
				printf("NO\n");
				return 0;
			}
			chk[i] = 0;
			for(j=0;j<v[i].size();j++)
			{
				cnt[v[i][j]]--;
				if(chk[v[i][j]] == 1 && cnt[v[i][j]] == 1)
					q.push(v[i][j]);
			}
		}
		else if(a[i] > b[i])
		{
			// printf("= %d %d %d\n",i,a[i],b[i]);
			a[i] -= b[i];
			ha = play2(i,-1,a[i] - b[i]);
			a[i] += b[i] - ha;
			// printf("-- %d %d %d\n",i,a[i],b[i]);
			if(a[i] != b[i])
			{
				printf("NO\n");
				return 0;
			}
			chk[i] = 0;
			for(j=0;j<v[i].size();j++)
			{
				cnt[v[i][j]]--;
				if(chk[v[i][j]] == 1 && cnt[v[i][j]] == 1)
					q.push(v[i][j]);
			}
		}
		else
		{
			chk[i] = 0;
			for(j=0;j<v[i].size();j++)
			{
				cnt[v[i][j]]--;
				if(chk[v[i][j]] == 1 && cnt[v[i][j]] == 1)
					q.push(v[i][j]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i] != b[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("%d\n",(int)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%d %d %d\n",ans[i].s,ans[i].e,ans[i].w);
	}
	return 0;
}