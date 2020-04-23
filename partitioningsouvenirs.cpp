#include<bits/stdc++.h>
using namespace std;
int arr;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr;
		sum+=arr;
	}
	if(sum/n==arr && n%3==0)
		cout<<1<<endl;
	else if(sum%3==0)
    {
        if((n%2==0 && n%3==0)||(n%2!=0 && sum%n<3 ))
		cout<<1<<endl;
		else
            cout<<0<<endl;}
	else
		cout<<0<<endl;
	return 0;
}
