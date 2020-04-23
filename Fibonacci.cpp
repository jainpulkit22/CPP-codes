#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    if(n==1||n==2)
        cout<<1<<endl;
    else
    {
        int a=1,b=1;int sum=0;
        for(int c=3;c<=n;c++){
                sum=(a+b);
                a=b;
                b=sum;
        }
        cout<<sum<<endl;
    }
    return 0;
}
