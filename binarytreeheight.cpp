#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}