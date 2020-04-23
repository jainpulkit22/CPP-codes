#include<bits/stdc++.h>
using namespace std;
int arr[27];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	int charcount=0;
	cin>>str;
	int n=str.length();
	for(int i=0;i<n;i++)
	{
		arr[str[i]-96]=1;
	}
	for(int i=1;i<=26;i++)
	{
		if(arr[i]==1)
			charcount++;
	}
	cout<<charcount<<endl;
	return 0;
}