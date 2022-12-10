#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef long long ll;
ll n , m  , q;
#define FOR(i,j) for(ll a=i;a<j;a++);

vector<vector<ll>>adj;
ll inf = 1e15;



int main()
{

    cin>>n>>m>>q;
    adj.resize(n+1);
    for(ll i=0;i<=n;i++)
    {
        adj[i].resize(n+1);
    }

    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            adj[i][j] = adj[j][i] = inf;
        }
    }

    
    for(ll i=0;i<m;i++)
    {
        ll u ,v  ,c;
        cin>>u>>v>>c;
        adj[u][v]  = adj[v][u] = min(adj[u][v] , c);

    }

    for( ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
            }
        }
    }


    for(ll i= 0;i<q;i++)
    {
        ll u ,v; 
        cin>>u>>v;
        if(adj[u][v]==inf)
        {
            adj[u][v] = -1;
        }

        cout<<adj[u][v]<<endl;
    }
    return 0;
}


