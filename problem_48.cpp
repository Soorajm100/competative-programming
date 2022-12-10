#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
ll n , m ;
vector<vector<ll>>adj;
vector<bool>vis;
vector<ll>par;
ll sv ,ev;
bool dfs(ll node , ll p)
{
    vis[node] = true;
    par[node] = p;
    for(auto x :adj[node])
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
            if(dfs(x , node))return true;
        }
    }

    return false;

}

bool solve()
{

    for(ll i=1;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i , -1))
            {
                return true;
            }
        }
    }

    return  false;

}



int  main()
{

    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    par.resize(n+1,-1);
    for(ll i=0;i<m;i++)
    {
        ll u ,v; 
        cin>>u>>v;
        adj[u].push_back(v);
    }

    bool ans = solve();

    if(!ans)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    ll t = ev;
    vector<ll>res;
    res.push_back(ev);
    while(t!=sv)
    {
        res.push_back(par[t]);
        t=par[t];
    }
    res.push_back(ev);

    cout<<res.size()<<endl;
    for(auto x : res)
    {
        cout<<x<<" ";
    }
    cout<<endl;




    return 0;
}