#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s,t,ans;
	cin>>s>>t;
	ll arr[s.length()+1][t.length()+1];
	for(int i=0;i<=s.length();i++)
		arr[i][0]=0;
	for(int i=0;i<=t.length();i++)
		arr[0][i]=0;
	for(int i=1;i<=s.length();i++)
	{
		for(int j=1;j<=t.length();j++)
		{
			if(s[i-1]==t[j-1])
			{
				arr[i][j]=arr[i-1][j-1]+1;
			}
			else
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
		}
	}
	ll i=s.length(),j=t.length();
	while(i>0 && j>0)
	{
		if(arr[i][j]==arr[i][j-1])
		{
			j=j-1;
		}
		else if(arr[i][j]==arr[i-1][j])
		{
			i=i-1;
		}
		else if(arr[i][j]==arr[i-1][j-1]+1)
		{
			ans=t[j-1]+ans;
			j=j-1;
			i=i-1;
		}
	}
	//cout<<arr[s.length()][t.length()]<<endl;
	cout<<ans<<endl;
	return 0;
}