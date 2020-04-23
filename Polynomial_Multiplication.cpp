#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the degree of polynomial\n";
    cin>>n;
    int A[n];int B[n];
    cout<<"enter the coefficients of A\n";
    for(int i=n-1;i>=0;i--)
        cin>>A[i];
    cout<<"enter the coefficients of B\n";
    for(int i=n-1;i>=0;i--)
        cin>>B[i];
    int r1[(n)/2];int r2[(n)/2];int r3[(n)/2];int r4[(n)/2];
    int i=0,j=0;
    do{
        i++;
        r1[n/2-i]=A[n-i];
        r2[n/2-i]=A[n/2-i];
    }while(n/2-i!=0);
    do{
        j++;
        r3[n/2-j]=B[n-j];
        r4[n/2-j]=B[n/2-j];
    }while(n/2-j!=0);
    int R[2*n-1]={0};
    for(int k=n/2-1;k>=0;k++)
        R[2*k]+=r1[k]*r3[k];
    cout<<R[2*n-2];
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            R[i+j]+=A[i]*B[j];
        }
    }
    for(int i=2*n-2;i>=0;i--)
        cout<<R[i]<<' ';*/
    return 0;
}
