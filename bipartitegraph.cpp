#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector< int >res1;
vector< int >res2;
void addedge(vector< int >adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool isBipartiteUtil(vector< int >adj[], int src, int colorArr[]) 
{ 
    colorArr[src] = 1; 
    res1.push_back(src);
    queue <int> q; 
    q.push(src); 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop();  
        for (int v =0; v < adj[u].size(); ++v) 
        {  
            if (colorArr[adj[u][v]] == -1) 
            { 
                colorArr[adj[u][v]] = 1 - colorArr[u];
                if(colorArr[adj[u][v]]==1)
                res1.push_back(adj[u][v]);
                else
                res2.push_back(adj[u][v]); 
                q.push(adj[u][v]); 
            } 
            else if (colorArr[adj[u][v]] == colorArr[u]) 
            {
                //cout<<adj[u][v]<<endl;
                return false; 
            }
        } 
    } 
    return true;
} 
bool isBipartite(vector< int >adj[],int V) 
{ 
    int colorArr[V+1]; 
    for (int i = 1; i <= V; ++i) 
        colorArr[i] = -1;  
    for (int i = 1; i<=V; i++) 
    if (colorArr[i] == -1) 
        if (isBipartiteUtil(adj, i, colorArr) == false){
            //cout<<i<<endl;
            return false;
        } 
        //return false; 
    return true; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    vector< int >adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        addedge(adj,a,b);
    }
    bool res=isBipartite(adj,n);
    if(res==false)
        cout<<-1<<endl;
    else
    {
        cout<<res1.size()<<endl;
        for(int i=0;i<res1.size();i++)
            cout<<res1[i]<<" ";
        cout<<endl;
        cout<<res2.size()<<endl;
        for(int i=0;i<res2.size();i++)
            cout<<res2[i]<<" ";
        cout<<endl;
    }
    return 0;
}