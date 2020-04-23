#include<bits/stdc++.h>
using namespace std;
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long int n,m;cin>>n>>m;
    if(n==1||n==2)
        cout<<1<<endl;
    else
    {
        long long int d=n%get_pisano_period(m);
        if(d==2||d==1){
            cout<<1%m<<endl;
            }
            else{
        long long int a=1,b=1,sum=0;
        for(long long int c=3;c<=d;c++){
                sum=(a%m+b%m);
                a=b%m;
                b=sum%m;
        }cout<<sum%m<<endl;}
    }
    return 0;
}
