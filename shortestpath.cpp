#include<bits/stdc++.h>
using namespace std;
#define ll long long
void addedge(vector< ll>adj[],ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void bfs(ll u,vector< ll >adj[],int dist[])
{
	ll vertex;
	dist[u]=0;
	queue< ll >q;
	q.push(u);
	while(!q.empty())
	{
		vertex=q.front();
		q.pop();
		for(int i=0;i<adj[vertex].size();i++)
		{
			if(dist[adj[vertex][i]]==-1)
			{
				dist[adj[vertex][i]]=dist[vertex]+1;
				q.push(adj[vertex][i]);	
			}
			else
			{
				dist[adj[vertex][i]]=min(dist[adj[vertex][i]], dist[vertex]+1);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,u,v;
	cin>>n>>m;
	vector< ll >adj[n+1];
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		addedge(adj,u,v);
	}
	cin>>u>>v;
	int dist[n+1];
	for(int i=1;i<=n;i++)
		dist[i]=-1;
	bfs(u,adj,dist);
	cout<<dist[v]<<endl;
	return 0;
}