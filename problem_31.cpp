#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define endl  "\n";

void dfs(ll node, vector<vector<ll>>&adj , vector<bool>&vis)
{

    vis[node] = true;
    for(auto x : adj[node])
    {
        if(vis[x]==false)dfs(x , adj , vis);
    }
}
int main()
{
    ll n , m ;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<vector<ll>>edges;
    vector<bool>vis(n+1 , false);
    for(ll i=0;i<m;i++)
    {
        ll a ,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }

    for(auto x : edges)
    {
        ll u = x[0] ; 
        ll v = x[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    
    }

    ll count = 0;
    vector<ll>lead;
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            count++;
            lead.push_back(i);
            dfs(i , adj , vis );
        }
    }
   
if(count>1){
    cout<<count-1<<endl;
    ll u = lead[0] , v ; 
    for(ll i=1;i<lead.size();i++)
    {
        v = lead[i];
        cout<<u<<" "<<v<<endl;
        u= v;
    }
}
else{
    cout<<0<<endl;
}

   
    return 0 ;
}