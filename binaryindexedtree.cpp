#include<bits/stdc++.h>
using namespace std;
int calcnext(int i)
{
	 int number_of_bits = floor(log2(i))+1; 
 	 int one=((1 << number_of_bits) - 1) ^ i;
 	 int two=one+1;
 	 return (i+ (i&two));
}
int calcparent(int i)
{
	int number_of_bits = floor(log2(i))+1; 
 	int one=((1 << number_of_bits) - 1) ^ i;
 	int two=one+1;
 	return (i- (i&two));
}
void update(int btree[],int i,int ele,int n)
{
	btree[i]+=ele;
	while(calcnext(i)<n)
	{
		btree[calcnext(i)]+=ele;
		i=calcnext(i);
	}
}
void updatenew(int btree[],int i,int ele,int n,int old)
{
	btree[i]+=ele;
	btree[i]-=old;
	while(calcnext(i)<n)
	{
		btree[calcnext(i)]+=ele;
		btree[calcnext(i)]-=old;
		i=calcnext(i);
	}
}
int calc(int btree[],int l,int r)
{
	r=r+1;
	int ans=0;
	while(calcparent(r)>0)
	{
		ans=ans+btree[r];
		r=calcparent(r);
	}
	ans=ans+btree[r];
	if(l==0)
	{
		return ans;
	}
	else{
		while(calcparent(l)>0)
		{
			ans=ans-btree[l];
			l=calcparent(l);
		}
		ans=ans-btree[l];
		return ans;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,x,l,r,ans;
	cin>>n>>q;
	int arr[n+1];
	int btree[n+2]={0};
	for(int i=0;i<n;i++){
		cin>>arr[i];
		update(btree,i+1,arr[i],n+1);
	}
	while(q--)
	{
		cin>>x>>l>>r;
		if(x==1)
			updatenew(btree,l+1,r,n+1,arr[l]);
		else
		{
			ans=calc(btree,l,r);
			cout<<ans<<endl;
		}
	}
	return 0;
}