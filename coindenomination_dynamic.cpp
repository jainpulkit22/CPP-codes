#include<bits/stdc++.h>
using namespace std;
int mini(int a,int b)
{
    return (a<b?a:b);
}
int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m;
    cin>>m;
    int arr[4][m+2];
    arr[0][0]=0;arr[0][1]=0;
    arr[1][0]=1;arr[1][1]=0;
    arr[2][0]=3;arr[2][1]=0;
    arr[3][0]=4;arr[3][1]=0;
    for(int i=2;i<=m+1;i++)
        arr[0][i]=i;
    for(int i=1;i<4;i++)
    {
        for(int j=2;j<m+2;j++)
        {
            if(j-1>=arr[i][0])
            {
                arr[i][j]=mini(arr[i-1][j],1+arr[i][j-arr[i][0]]);
            }
            else
                arr[i][j]=arr[i-1][j];
        }
    }
    cout<<(arr[3][m+1])<<endl;
    return 0;
}
