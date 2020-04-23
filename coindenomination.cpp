#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int d=n/10;
    n=n-(d*10);
    int e=n/5;
    n-=(e*5);
    int f=n/1;
    n-=(f*1);
    cout<<d+e+f<<endl;
    return 0;
}
