#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FastIo ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
stack < ll >s;
void diraddedge(vector< ll >adj[],ll u,ll v)
{
	adj[u].pb(v);
}
void addedge(vector< ll >adj[],ll u,ll v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void dfsUtil(vector< ll >adj[],ll a,bool visited[])
{
	visited[a]=true;
	for(int i=0;i<adj[a].size();i++)
	{
		if(visited[adj[a][i]]==true)
			continue;
		dfsUtil(adj,adj[a][i],visited);
	}
	s.push(a);
}
void dfsUtil2(vector< ll >adj[],ll a,bool visit[],vector< ll >res[],ll m)
{
	visit[a]=true;
	res[m].pb(a);
	for(int i=0;i<adj[a].size();i++)
	{
		if(visit[adj[a][i]]==true)
			continue;
		dfsUtil2(adj,adj[a][i],visit,res,m);
	}
	//s.push(a);
}
void reversegraph(vector< ll >adj[],vector< ll >radj[],ll n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<adj[i].size();j++)
			radj[adj[i][j]].pb(i);
	}
}
int main()
{
	FastIo
	ll n,m,u,v;
	cin>>n>>m;
	vector< ll >adj[n+1];
	vector< ll >radj[n+1];
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		diraddedge(adj,u,v);
	}
	bool visited[n+1]={false};
	//visited.clear();
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==true)
		{
			//cout<<i<<endl;
			continue;
		}
		dfsUtil(adj,i,visited);
	}
	reversegraph(adj,radj,n);
	bool visited1[n+1]={false};
	//adj.clear();
	vector< ll >result[n+1];
	m=-1;
	while(!s.empty())
	{
		v=s.top();
		s.pop();
		if(visited1[v]==true)
			continue;
		dfsUtil2(radj,v,visited1,result,++m);
	}
	//set< set < ll > >::iterator itr;
	/*for(int i=0;i<=m;i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<m<<endl;
	return 0;
}