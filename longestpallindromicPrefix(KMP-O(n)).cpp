#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIo ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 998244353
//Function to calculate longest pallindromic prefic using KMP strings algorithm in linear time complexity
ll checkpal(string s)
{
	ll arr[2*s.length()+5];
	string res=s;
	reverse(s.begin(),s.end());
	s=res+'#'+s;
	arr[0]=0;
	ll len=s.length();
	int i=0,j=1;
	while(j < len){
        if(s[i] == s[j]){
            arr[j] = i+1;
            i++; j++;
        } else {
            if(i>=1){
                i = arr[i-1];
            }else{
                arr[j] = 0;
                j++;
            }
        }
    }
    return arr[len-1];
}
int main()
{
	FastIo
	ll t,ret,ret1,pos,n;
	cin>>t;
	string s,s1,s2;
	while(t--)
	{
		pos=-1;
		cin>>s;
		n=s.length();
		for(int i=0;i<=(n-1)/2;i++)
		{
			if(s[i]==s[n-1-i])
				continue;
			else
			{
				pos=i;
				break;
			}
		}
		if(pos==-1)
			cout<<s<<endl;
		else{
		s1=s.substr(pos,n-2*pos);
		s2=s1;
		reverse(s2.begin(),s2.end());
		//cout<<s1<<" "<<s2<<endl;
		ret=checkpal(s1);
		ret1=checkpal(s2);
		if(pos==0)
		{
			s1=s1.substr(0,ret);
			s2=s2.substr(0,ret1);
		}
		else
		{
			//cout<<s1.substr(0,ret)<<endl;
			s1=s.substr(0,pos)+s1.substr(0,ret)+s.substr(n-pos,pos+1);
			s2=s.substr(0,pos)+s2.substr(0,ret1)+s.substr(n-pos,pos+1);
		}
		if(s1.length()>s2.length())
			cout<<s1<<endl;
		else
			cout<<s2<<endl;
		}
		//cout<<ret<<" "<<ret1<<endl;
	}
	return 0;
}