#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef long long ll;
ll n , m ;
vector<vector<pair<ll , ll>>>adj;
vector<bool>vis;
vector<ll>dist;

int main()
{

    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1 , false);
    dist.resize(n+1 , 1e17);
    for(ll i= 0 ;i<m;i++)
    {
        ll u ,v , w;
        cin>>u>>v>>w;
        adj[u].push_back({v , w});
      //  adj[v].push_back({u , w});
    }

   priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q; 
    q.push({0 , 1});
    dist[1] = 0;
    vis[1] = true;
    while(!q.empty())
    {
        ll node = q.top().second;
        ll d = q.top().first;
        
        q.pop();
        if(dist[node]<d)continue;
        for(auto x : adj[node])
        {
          

            auto child =x.first;
            auto weight = x.second;
            if(weight + d< dist[child])
            {
                dist[child] =  weight + d;
                q.push({dist[child], child});
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}


