#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define FastIo ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 998244353
#define pb push_back
#define mp make_pair
ll parent[100005];
struct parallel{
	ll u;
	ll d;

	public:
		parallel(ll a,ll b){
			u=a;
			d=b;
		}
};
class cmpfunction{
	public:
		ll operator()(const parallel &a,const parallel &b){
			if(a.d>b.d)
				return true; 
			else
				return false;
		}
};
void addedge(vector< pair<ll,ll> >adj[],ll l,ll v,ll w)
{
	adj[l].push_back( make_pair(v,w));
}
void initialize(ll arr[],ll m,ll n)
{
	for(int i=0;i<=n;i++)
	{
		arr[i]=m;
	}
}
void Dijkstara(vector< pair<ll,ll> >adj[],ll a,ll v,ll n)
{
	ll dist[n+1];
	//ll parent[n+1]={0};
	initialize(dist,1000000000000000009,n);
	dist[a]=0;
	priority_queue<parallel, vector<parallel>, cmpfunction>pq;
	for(ll i=1;i<=n;i++)
	{
		pq.push(parallel(i,dist[i]));
	}
	parallel mi=pq.top();
	while(!pq.empty())
	{
		parallel mini=pq.top();
		pq.pop();
		for(ll i=0;i<adj[mini.u].size();i++)
		{
			if(dist[adj[mini.u][i].first]>dist[mini.u]+adj[mini.u][i].second)
			{
				parent[adj[mini.u][i].first]=mini.u;
				dist[adj[mini.u][i].first]=dist[mini.u]+adj[mini.u][i].second;
				//changepriority(pq,adj[mini.u][i].first,dist[adj[mini.u][i].first]);
				priority_queue<parallel, vector<parallel>, cmpfunction>npq;
				ll a=adj[mini.u][i].first;
				ll dis=dist[adj[mini.u][i].first];
				while(((pq.top()).u)!=a)
				{
					npq.push(parallel(((pq.top()).u),((pq.top()).d)));
					pq.pop();
				}
				npq.push(parallel((pq.top()).u,dis));
				pq.pop();
				while(!npq.empty())
				{
					pq.push(parallel((npq.top()).u,(npq.top()).d));
					npq.pop();
				}
			}
		}
	}
	//return dist[v];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,u,v,k;
	cin>>n>>k;
	vector< pair<ll,ll> >adj[n+1];
	vector< pair<ll,ll> >vi;
	ll arr[100005];
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		addedge(adj,u,v,1);
	}
	for(int i=2;i<=n;i++)
	{
		vi.pb(mp(adj[i].size(),i));
	}
	//sort(vi.begin(),vi.end(),greater<ll>());
	arr[1]=1;
	/*for(int i=0;i<(n-k)-1;i++)
	{
		//if(v[i].second!=1)
		arr[vi[i-1].second]=1;;
	}*/
	//cin>>u>>v;
	Dijkstara(adj,1,n,n);
	/*if(pathlen==1000000000000000009)
		cout<<-1<<endl;
	else
		cout<<pathlen<<endl;*/
	return 0;
}