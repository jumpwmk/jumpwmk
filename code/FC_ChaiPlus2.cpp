/*
TASK : FC_ChaiPlus
LANG : C++
AUTHOR : Nattapat
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[200];
int main(){
	freopen("../7.in","r",stdin);
	freopen("../test.out","w",stdout);
    int t,n,a,b,m,p,x,y,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&arr[i]);
        sort(arr+1,arr+1+n);
        scanf("%d%d",&a,&b);
        i=1;
        while(a>arr[i]&&i!=n)i++;
        if(i==1){
            m=arr[i]-a;
            p=a;
        }
        else{
            if(a>(arr[i]+arr[i-1])/2){
                m=arr[i]-a;
                p=a;
            }
            else{
                m=(arr[i]-arr[i-1])/2;
                p=(arr[i]+arr[i-1])/2;
            }
        }
        while(i!=n&&arr[i+1]<=b){
            if(m<(arr[i+1]-arr[i])/2){
                m=(arr[i+1]-arr[i])/2;
                p=(arr[i+1]+arr[i])/2;
            }
            i++;
        }
        if(i==n){
            if(m<b-arr[i]){
                m=b-arr[i];
                p=b;
            }
        }
        else{
            if(b>(arr[i]+arr[i+1])/2){
                if(m<(arr[i+1]-arr[i])/2){
                    m=(arr[i+1]-arr[i])/2;
                    p=(arr[i+1]+arr[i])/2;
                }
            }
            else{
                if(m<b-arr[i]){
                    m=b-arr[i];
                    p=b;
                }
            }
        }
        printf("%d\n",p);
    }
    return 0;
}
