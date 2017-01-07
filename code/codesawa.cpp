#include <vector>
#define mod 1000000007
using namespace std;
long long  b[100100];
vector <long long> V[100100],U[100100],SUM[100100];
int main()
{
    long long n,i,cnt=0,a,mx=-1<<30,j,x,ans=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        if(mx<x)
        {
            mx=x;
            V[cnt].push_back(x);
            b[cnt]=x;
            cnt++;
        }
        else
        {
            a=lower_bound(b,b+cnt,x)-b;
            V[a].push_back(x);
            b[a]=x;
            if(a==cnt-1)
            {
                mx=x;
            }
        }
    }
    for(i=0; i<cnt; i++)
    {
        for(j=V[i].size()-1; j>=0; j--)
        {
            U[i].push_back(V[i][j]);
            SUM[i].push_back(0);
        }
    }
    SUM[0][0]++;
    for(i=0; i<cnt-1; i++)
    {

        //cout<<i+1<<": ";cout<<SUM[i][0]<<' ';
        for(j=1; j<SUM[i].size(); j++)
        {
            SUM[i][j]+=SUM[i][j-1];
            SUM[i][j]=(SUM[i][j]+mod)%mod;
            //cout<<SUM[i][j]<<' ';
        }
        for(j=0; j<U[i].size(); j++)
        {
            //cout<<lower_bound(U[i+1].begin(),U[i+1].end(),U[i][j]+1)-U[i+1].begin()<<' ';
            SUM[i+1][lower_bound(U[i+1].begin(),U[i+1].end(),U[i][j])-U[i+1].begin()]+=SUM[i][j];
            SUM[i+1][lower_bound(U[i+1].begin(),U[i+1].end(),U[i][j])-U[i+1].begin()]=
            (SUM[i+1][lower_bound(U[i+1].begin(),U[i+1].end(),U[i][j])-U[i+1].begin()]+mod)%mod;
        }
        //cout<<endl;
    }
    ans+=SUM[cnt-1][0];
    //cout<<i+1<<": ";cout<<SUM[i][0]<<' ';
    for(j=1; j<SUM[cnt-1].size(); j++)
    {
        SUM[cnt-1][j]+=SUM[cnt-1][j-1];
        SUM[cnt-1][j]=(SUM[cnt-1][j]+mod)%mod;
        //cout<<SUM[i][j]<<' ';
        ans+=SUM[cnt-1][j];
        ans=(ans+mod)%mod;
    }//cout<<endl;
    cout<<ans<<endl;
}
