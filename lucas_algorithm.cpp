#include<bits/stdc++.h>
using namespace std;
long long min(long long a,long long b)
{
	return (a<b)?a:b;
}
long long nCrModpDP(long long n, long long r, long long p) 
{ 
    long long C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (long long i = 1; i <= n; i++) 
    { 
     
        for (long long j = min(i, r); j > 0; j--) 
 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
long long nCrModpLucas(long long n,long long r,long long p) 
{ 
   if (r==0) 
      return 1; 
   long long ni = n%p, ri = r%p; 
   return (nCrModpLucas(n/p, r/p, p) *
           nCrModpDP(ni, ri, p)) % p; 
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t,n,r,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>r;
		a=nCrModpLucas(n,r,2);
		b=nCrModpLucas(n,r,3);
		if(a== 0 && b==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}