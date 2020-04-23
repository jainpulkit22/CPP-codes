#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int b[k];
    for(int i=0;i<k;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<k;i++)
    {
        int first=0;int last=n-1;int count=0;
        int mid=(first+last)/2;
        while(first<=last)
        {
            if(b[i]==a[mid])
            {
                b[i]=mid;
                count++;break;
            }
            else if(b[i]>a[mid])
            {
                first=mid+1;
                mid=(first+last)/2;
            }
            else
            {
                last=mid-1;
                mid=(first+last)/2;
            }
        }
        if(count==0)
            b[i]=-1;
    }
    for(int i=0;i<k;i++)
        cout<<b[i]<<' ';
    cout<<endl;
    return 0;

}
