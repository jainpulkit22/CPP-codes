#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
bool visited[100005];
stack<ll>s;
void addedge(vector< ll >adj[],ll u,ll v)
{
	adj[u].pb(v);
}
void topsort(vector<ll>adj[],ll vertex)
{
	visited[vertex]=true;
	for(int i=0;i<adj[vertex].size();i++)
	{
		if(visited[adj[vertex][i]]==true)
			continue;
		topsort(adj,adj[vertex][i]);
	}
	s.push(vertex);
}
void topologicalsort(vector<ll>adj[],ll v)
{
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==true)
			continue;
		topsort(adj,i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,a,b,maxi=0;
	cin>>n>>m;
	ll dist[n+1]={0};
	vector<ll>adj[n+1];
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		addedge(adj,a,b);
	}
	topologicalsort(adj,n);
	while(!s.empty())
	{
		a=s.top();
		s.pop();
		for(int i=0;i<adj[a].size();i++)
		{
			if(dist[adj[a][i]]<dist[a]+1)
				dist[adj[a][i]]=dist[a]+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dist[i]>maxi)
			maxi=dist[i];
	}
	cout<<maxi<<endl;
	return 0;
}