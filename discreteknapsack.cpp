#include<bits/stdc++.h>
using namespace std;
int arr[308][10005];
int W[100005];
int v[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int w,n;long long int value=0;
	cin>>w>>n;
	for(int i=1;i<n+1;i++)
	{
		cin>>W[i];
		v[i]=1;
	}
	for(int i=0;i<=n;i++)
	{
		arr[i][0]=0;
	}
	for(int i=0;i<=w;i++)
	{
		arr[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
		    value=0;
			arr[i][j]=arr[i-1][j];
			if(W[i]<=j)
			{
				value=arr[i-1][j-W[i]]+(v[i]*W[i]);
			}
			if(arr[i][j]<value && value<=w)
				arr[i][j]=value;
		}
	}
	cout<<arr[n][w]<<endl;
	return 0;
}
