#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int n,m;
int table[1000005];
int sum[1000005];
char s[1000005];
char key[1000005];
stack<int> p;
stack<int> q;
void pre()
{
    int i = 0,j = -1;
    table[0] = -1;
    while(i<m)
    {
        while(j>=0 && key[i]!=key[j]) j = table[j];
        table[++i] = ++j;
    }
}
void kmp()
{
    int i = 0,j = 0,x;
    while(i<n)
    {
        x = j;
        while(j>=0 && s[i]!=key[j]) j = table[j];
        if(j!=x)
        {
            p.push(x);
        }
        ++i; ++j;
        if(j==1) q.push(i);
        if(j==m)
        {
            if(s[i]==s[0]||p.empty()) j = 0;
            else
            {
                j = p.top(); p.pop();
            }
            x = q.top(); q.pop();
            sum[x-1]++; sum[i]--;
            //printf("%d - %d\n",x-1,i-1);
        }
    }
}
int main()
{
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    int time;
    int i,x;
    bool ans;
    scanf("%d",&time);
    while(time--)
    {
        scanf(" %s %s",s,key);
        n = strlen(s); m = strlen(key);
        for(i=0;i<n;i++) sum[i] = 0;
        while(!p.empty()) p.pop();
        while(!q.empty()) q.pop();
        pre();
        for(i=0;i<m;i++)
            printf("%d ",table[i]);
        printf("\n");
        kmp();
        x = 0;
        ans = false;
        for(i=0;i<n;i++)
        {
            x += sum[i];
            //printf("%d: %d\n",i,sum[i]);
            if(x==0)
            {
                printf("%c",s[i]);
                ans = true;
            }
        }
        if(!ans) printf("No COI Secret Code");
        printf("\n");
    }
    return 0;
}
/*
3
CodeCodecubeCodecubecute
Codecube
CodeCodecubecubeCodecube
Codecube
CasecaseSensitive191
case
*/
/*
4
aabcbabccabc
abc
codeccodecodecodeocodcodeedcodee
code
cococococcodeodedcodeecocodedecocodedededcococodededecodece*co
code
*/
