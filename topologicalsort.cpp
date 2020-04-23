#include<bits/stdc++.h>
using namespace std;
bool visited[100005];
stack<int>s;
void addedge(vector< int >adj[],int u,int v)
{
	adj[u].push_back(v);
}
void topsort(vector<int>adj[],int vertex)
{
	visited[vertex]=true;
	for(int i=0;i<adj[vertex].size();i++)
	{
		if(visited[adj[vertex][i]]==true)
			continue;
		topsort(adj,adj[vertex][i]);
	}
	cout<<vertex<<endl;
	s.push(vertex);
}
void topologicalsort(vector<int>adj[],int v)
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
	int n,m,a,b;
	cin>>n>>m;
	vector<int>adj[n+1];
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		addedge(adj,a,b);
	}
	topologicalsort(adj,n);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return 0;
}