#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ld find(ll x,ll parent[])
{
	if(x!=parent[x])
		parent[x]=find(parent[x],parent);
	return parent[x];
}
void merge(ll x,ll y,ll parent[],ll rank[])
{
	x=find(x,parent);
	y=find(y,parent);
	if(rank[x]>rank[y])
	{
		parent[y]=x;
	}
	else
	{
		parent[x]=y;
	}
	if(rank[x]==rank[y])
		rank[y]++;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll x[n+1];
	ll y[n+1];
	ll parent[n+1];
	ll rank[n+1];
	ld ans=0;
	ld dist=0;
	vector< pair<ld, pair<ll,ll> > >adj;
	for(ll i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(i!=j)
			{
				dist=(ld)sqrt((ld)pow((x[j]-x[i]),2)+(ld)pow((y[j]-y[i]),2));
				adj.push_back(make_pair(dist,make_pair(i+1,j+1)));
			}
		}
	}
	sort(adj.begin(), adj.end());
	for(ll i=1;i<=n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
	for(ll i=0;i<adj.size();i++)
	{
		if(find((adj[i].second).first,parent)!=find((adj[i].second).second,parent)){
			ans+=adj[i].first;
			merge(((adj[i].second).first),((adj[i].second).second),parent,rank);
		}
	}
	cout<<fixed<<setprecision(9)<<ans<<endl;
	return 0;
}