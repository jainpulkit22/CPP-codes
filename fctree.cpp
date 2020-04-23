#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define FastIo ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define pb push_back 
vector<ll>adj[1005];
bool vis[1005];
ll cost[1005];
ll  tmp=-1;
vector< ll >ans;
#define MAX 10000002
int prime[MAX]; 
void sieve() 
{ 
    memset(prime, 0, sizeof(prime)); 
    prime[0] = prime[1] = 1; 
    for (int i = 2; i * i < MAX; i++) { 
        if (prime[i] == 0) { 
            for (int j = i * 2; j < MAX; j += i) { 
                if (prime[j] == 0) 
                    prime[j] = i; 
            } 
        } 
    } 
    for (int i = 2; i < MAX; i++) { 
        if (prime[i] == 0) 
            prime[i] = i; 
    } 
} 
ll factors(){ 
    unordered_map<ll, ll> prime_count;
    for (int i = 0; i < ans.size(); i++){ 
        ll temp = ans[i]; 
        while (temp != 1) {
            prime_count[prime[temp]]++; 
            temp = temp / prime[temp]; 
        } 
    } 
    ll answer = 1;
    //unordered_map<int, int>::iterator it; 
    for (auto it: prime_count) { 
        answer = (answer%mod * (it.second + 1)%mod)%mod; 
    } 
    return answer%mod; 
} 
void addEdge(ll u,ll v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}  
void calcQuot(stack<ll> st) 
{ 
    tmp=1;
    int i; 
    while(st.size()!=1)
    {
        ans.pb(cost[st.top()]);
        st.pop();
    }
    ans.pb(cost[st.top()]);
    st.pop();
} 
void DFS(ll x, ll y, stack<ll> st) 
{ 
    st.push(x); 
    if (x == y) {  
        calcQuot(st); 
        return; 
    } 
    vis[x] = true; 
    int flag = 0; 
    if (!adj[x].empty()) {
        for (int j = 0; j < adj[x].size(); j++) {  
            if (vis[adj[x][j]] == false) { 
                //cout<<x<<" "<<adj[x][j]<<endl;
                DFS(adj[x][j], y, st); 
                if(tmp==1)
                    return;
                flag = 1; 
            } 
        }
    } 
    if (flag == 0) { 
        st.pop(); 
    } 
} 


int main() 
{ 
    FastIo
    ll t,n,u,v,q,cntr;
    cin>>t;
    sieve();
    while(t--)
    {
        cin>>n;
        ll arr[n+1][n+1]={0};
        for(int i=1;i<=n;i++)
            adj[i].clear();
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            arr[u][v]=1;
            arr[v][u]=1;
            addEdge(u,v);
        }
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i];
        }
        stack<ll>st;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans.clear();
                if(i==j){
                    ans.pb(cost[i]);
                    arr[i][j]=factors();
                }
                else if(arr[i][j]==1)
                {
                    ans.pb(cost[i]);
                    ans.pb(cost[j]);
                    arr[i][j]=factors();
                    arr[j][i]=arr[i][j];
                }
                else if(arr[i][j]==0)
                {
                    tmp=-1;
                    memset(vis, false, n+2);
                    DFS(i,j,st);
                    arr[i][j]=factors();
                    arr[j][i]=arr[i][j];
                }
            }
        }
        cin>>q;
        while(q--)
        {
            //memset(vis, false, n+2);
            //ans.clear();
            cin>>u>>v;
            /*tmp=-1;
            if(u==v)
            {
                ans.pb(cost[u]);
            }
            else
            {
                cntr=0;
                //if()
                for(int i=0;i<adj[u].size();i++)
                {
                    if(adj[u][i]==v)
                    {
                        cntr=1;
                        break;
                    }
                }
                if(cntr==1)
                {
                    ans.pb(cost[u]);
                    ans.pb(cost[v]);
                }
                else{
                    DFS(u, v, st);
                }
            }*/
            /*for(auto j: ans)
                cout<<j<<endl;*/
            cout<<arr[u][v]<<"\n";
        }
    }
    return 0; 
} 
