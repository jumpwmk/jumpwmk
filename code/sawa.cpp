#include "stdio.h"

int n,m,co;
int mxR,mxC;
int pr,pc;
int coR,coC;
char mp[1005][1005];

int main(){
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d%d",&n,&m);
	mxR = mxC = -1;
	for(int i = 0; i < n; i++){
		scanf(" %s", mp[i]);
		for(int j = coR = 0; j < m; j++){
			if(mp[i][j]=='*'){
				co++;
				coR++;
			}
		}
		if(coR>mxR){
			mxR = coR;
			pr = i;
		}
	}
	for(int j = 0; j < m; j++){
		for(int i = coC = 0; i < n; i++){
			if(mp[i][j]=='*') coC++;
		}
		if(coC>mxC){
			mxC = coC;
			pc = j;
		}
	}

	for(int i = coC = 0; i < n; i++){
		if(mp[i][pc]=='*') coC++;
	}
	for(int i = 0; i < m; i++){
		if(mp[pr][i]=='*') coC++;
	}
	printf("%d %d\n",pr,pc);
	if(mp[pr][pc]=='*') coC--;
	if(coC==co) printf("YES\n%d %d\n",pr+1,pc+1);
	else printf("NO\n");
}