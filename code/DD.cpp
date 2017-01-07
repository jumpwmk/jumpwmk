#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<map>
using namespace std;
const int mxn=100010;
map<string,int>mp;
priority_queue<int>p[mxn];
int cnt=0;
bool hw[mxn];
string s[mxn],c;
int score[mxn];
int n,k;
int ans=0;
bool pd(string ch){
	int l=n/2;
	for(int i=0;i<l;i++){
		if(ch[i]!=ch[n-i-1])return 0;
	}
	return 1;
}
int main(){

		freopen("../test.in","r",stdin);
		freopen("../test.out","w",stdout);

	int i,j,w;
	cin>>k>>n;
	for(i=1;i<=k;i++){
		cin>>s[i]>>w;
		if(!mp[s[i]])mp[s[i]]=++cnt;
		p[mp[s[i]]].push(w);
		if(!hw[mp[s[i]]]){
			if(pd(s[i]))hw[mp[s[i]]]=1;
		}
	}
	int mx=0;
	for(i=1;i<=k;i++){
		if(p[mp[s[i]]].empty())continue;
		c=s[i];
		reverse(c.begin(),c.end());
		int t=mp[c];
		int x=mp[s[i]];
		w=p[x].top();
		p[x].pop();
		if(t && !p[t].empty() && p[t].top()+w>0){
			if(p[t].top()*w<0 && hw[x]){
				mx=max(mx,max(p[t].top(),w)-p[t].top()-w);
			}
			ans+=p[t].top()+w;
			p[t].pop();
		}
		else p[x].push(w);
	}
//	printf("%d %d\n",ans,mx);
	for(i=1;i<=cnt;i++){
		if(hw[i] && !p[i].empty()){
			mx=max(mx,p[i].top());
		}
	}
	printf("%d\n",mx);
	printf("%d\n",ans+mx);
	return 0;
}