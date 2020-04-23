#include<bits/stdc++.h>
using namespace std;
int polyhashi(string s,int P,int x)
{
	int sum=0;
	for(int i=0;i<s.length();i++)
	{
		sum+=(s[i]*(int)pow(x,i))%P;
	}
	return sum;
}
void precomputehashes(string t,int P,string p,int x,int h[])
{
	string s=t.substr(t.length()-p.length(),p.length());
	h[t.length()-p.length()]=polyhashi(s,P,x);
	int y=1;
	for(int i=1;i<=p.length();i++)
	{
		y=(y*x) % P;
	}
	for(int i=t.length()-p.length()-1;i>=0;i--)
	{
		h[i]=(x*h[i+1] + t[i]-y*t[i+p.length()])%P;
	}
}
void Rabinkarp(string t,string p,int result[],int* l)
{
	int P=500009;
	int x=1;
	int ph=polyhashi(p,P,x);
	int h[t.length()-p.length()+1];
	precomputehashes(t,P,p,x,h);
	for(int i=0;i<=t.length()-p.length();i++)
	{
	    if(ph!=h[i]){
	        continue;
	    }
	    if(p==t.substr(i,p.length()))
	        result[++(*l)]=i;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string p,t;
	cin>>p;
	cin>>t;
	int n=p.length();
	int m=t.length();
	int arr[m-1]={-1};
	int k=-1;
	Rabinkarp(t,p,arr,&k);
	for(int i=0;i<=k;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}