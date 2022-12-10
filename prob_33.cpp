#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n";

ll n , m ;
 vector<vector<ll>>adj;
    vector<ll>color ;   // 1 is red 2 is blue
  

bool dfs(ll node , ll c , ll par , vector<bool>&vis)
{
    vis[node] = true;
    color[node] = c;
    for(auto x : adj[node])
    {
        if(x==par)continue;
        if(color[x]==0)
        {
            //cout<<(color[node]^3)<<" "<<color[node]<<endl;
            // for alternating the colors

            if(!dfs(x , (color[node]^3) , node , vis))
            {
                return false;
            }
        }
        if(color[x]==color[node])
        {
                return false;
        }
        
    }

    return  true;
}


bool color_all(vector<bool>&vis)
{
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(!dfs(i,1,-1 , vis))
            {
                return  false;
            }
        }
        
    }
    return true;
}

int main()
{
    cin>>n>>m;
    vector<bool>vis(n+1 ,false);

     adj.resize(n+1);
     color.resize(n+1 );
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = color_all(vis);


    if(!ans)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
  
    for(ll i=1;i<=n;i++)
    {
        cout<<color[i]<<" ";
    }
    
    return 0 ; 
}