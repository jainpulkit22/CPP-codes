#include<bits/stdc++.h>
using namespace std;
#define ll long long
void addedge(vector< pair<ll,ll> >adj[],ll u,ll v, ll w)
{
	adj[u].push_back( make_pair(v,w) );
}
void initialize(ll arr[],ll st,ll n)
{
	for(int i=st;i<=n;i++)
		arr[i]=1000000000000000009;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,u,v,w,flag=0;
	cin>>n>>m;
	vector< pair<ll,ll> >adj[n+1];
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		addedge(adj,u,v,w);
	}
	ll prev[n+1]={-1};
	ll dist[n+1];
	dist[1]=0;
	initialize(dist,2,n);
	for(ll i=1;i<n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			for(ll k=0;k<adj[j].size();k++)
			{
				if(dist[adj[j][k].first]> (dist[j]+adj[j][k].second))
				{
					dist[adj[j][k].first]=dist[j]+adj[j][k].second;
					prev[adj[j][k].first]=j;	
				}
			}
		}
	}
	for(ll j=1;j<=n;j++)
	{
		for(ll k=0;k<adj[j].size();k++)
		{
			if(dist[adj[j][k].first]> (dist[j]+adj[j][k].second))
			{
				flag=1;
				break;	
			}
		}
	}
	if(flag==1)
		cout<<1<<endl;
	else
		cout<<0<<endl;
	return 0;
}