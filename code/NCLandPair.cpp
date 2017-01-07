#include <stdio.h>
#define con 2550000
int a[100][100],b[100][100];
int key[5050010];
int cnt[5050010],num=1,Cnt;
int main()
{
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    int n,i,j,k,l,sum;
    scanf("%d",&n);
    printf("%d",n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            b[i][j]=a[i][n-j+1];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=i;k++){
                for(l=1;l<=j;l++){
                    sum=a[i][j]-a[i][l-1]-a[k-1][j]+a[k-1][l-1]+con;
                    if(key[sum]!=num)cnt[sum]=0,key[sum]=num;
                    cnt[sum]++;
                }
            }
            for(k=i+1;k<=n;k++){
                for(l=j+1;l<=n;l++){
                    sum=a[k][l]-a[k][j]-a[i][l]+a[i][j]+con;
                    if(key[sum]==num)Cnt+=cnt[sum];
                }
            }
            num++;
            for(k=1;k<=i;k++){
                for(l=1;l<=j;l++){
                    sum=b[i][j]-b[i][l-1]-b[k-1][j]+b[k-1][l-1]+con;
                    if(key[sum]!=num)cnt[sum]=0,key[sum]=num;
                    cnt[sum]++;
                }
            }
            for(k=i+1;k<=n;k++){
                for(l=j+1;l<=n;l++){
                    sum=b[k][l]-b[k][j]-b[i][l]+b[i][j]+con;
                    if(key[sum]==num)Cnt+=cnt[sum];
                }
            }
            num++;
        }
    }
    printf("%d\n",Cnt);
    return 0;
}
