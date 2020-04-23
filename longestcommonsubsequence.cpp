#include<bits/stdc++.h>
using namespace std;
int max(int a,int b){
	return (a>=b)?a:b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,o;
	long long arr[102][102][102];
	cin>>n;
	arr[0][0][0]=0;arr[1][1][1]=0;
	/*int a=(n>=m)?n:m;
	int b=(n<=m)?n:m;*/
	for(int i=2;i<=n+1;i++)
		cin>>arr[0][i][0];
    cin>>m;
	for(int i=2;i<=m+1;i++)
		cin>>arr[i][0][0];
	cin>>o;
	for(int i=2;i<=o+1;i++)
		cin>>arr[0][0][i];
	for(int i=0;i<=n+1;i++)
		arr[1][i][1]=0;
	for(int i=0;i<=m+1;i++)
		arr[i][1][1]=0;
	for(int i=0;i<=o+1;i++)
		arr[1][1][i]=0;
    /*int a=(n>=m)?n:m;
    int b=(n<=m)?n:m;*/
	for(int i=2;i<=m+1;i++)
	{
		for(int j=2;j<=n+1;j++)
		{
			for(int k=2;k<=o+1){
			if(arr[i][0][0]==arr[0][j][0] && arr[0][0][k])
			{
			    //cout<<arr[i][0]<<" "<<arr[0][j]<<" ";
				arr[i][j][k]=arr[i-1][j-1][k-1]+1;
				//cout<<arr[i][j]<<" ";
			}
			else
				arr[i][j][k]=max(arr[i][j-1][k-1],arr[i-1][j][k-1]);
		}}
	}
	cout<<arr[m+1][n+1][o+1]<<endl;
	return 0;
}
