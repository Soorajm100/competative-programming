#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll;
#define  endl "\n"
ll n , m ;
ll sv , ev ; 
bool dfs(vector<vector<ll>>&adj , vector<bool>&vis , vector<ll>&par , ll node , ll p)
{
    vis[node] = true;
    par[node] = p;
    for(auto x : adj[node])
    {
        if(x==p)continue;
        if(vis[x])
        {
            sv = x;
            ev = node;
            return true;

        }

        if(!vis[x])
        {
            if(dfs(adj , vis, par ,x , node))
            {
                return true;
            }
        }

    }

    return false;

}

bool visit_all(vector<vector<ll>>&adj , vector<bool>&vis , vector<ll>&par)
{
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(adj, vis ,par ,i , -1))return true;
        }
    }

    return false;


}

int main()
{
    
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<ll>par(n+1 , -1);
    vector<bool>vis(n+1 , false);
    for(ll i=0;i<m;i++)
    {
        ll u ,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = visit_all(adj, vis ,par );
    if(!ans)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    ll tv = ev; 
    vector<ll>res;
    res.push_back(ev);
    while(tv!=sv)
    {
        res.push_back(par[tv]);
        tv = par[tv];
    }

    res.push_back(ev);
    cout<<res.size()<<endl;
    for(auto x : res)
    {
        cout<<x<<" ";
    }
    cout<<endl;


    return 0 ;
}