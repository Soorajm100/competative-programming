#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

ll n ;
const int nax = 1e5 +1;
vector<vector<ll>>adj;
vector<bool>vis;

ll dp[nax][2];
ll dfs(ll curr , bool take , ll par)
{
    if(dp[curr][take]!=-1)return dp[curr][take];
    ll res  = take;
    for(auto x : adj[curr])
    {
        
        if(x!=par)
        {
            // x is only the child node no need parent;
            if(take)
            {
                res+= min(dfs(x , 0 ,curr), dfs(x , 1 , curr));
                
            }
            else{
                res  += dfs(x , 1 , curr);
                
            }

        }
    }

    return dp[curr][take] = res;
}

int main()
{
    cin>>n;
    adj.resize(n+1);
    vis.resize(n+1);
    for(ll i=0;i<n;i++)
    {
        ll u ,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, -1 , sizeof(dp));
    cout<<min(dfs(1,0,-1) , dfs(1,1,-1));

    return 0;
}
