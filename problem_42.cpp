#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n";


ll  n , m , k;
vector<vector<pair<ll,ll>>>adj;
vector<vector<ll>>dist ;
ll inf = 9e17;

int main()
{
    cin>>n>>m>>k;
    adj.resize(n+1);
    dist.resize(n+1);
    for(ll i=0;i<m;i++){

        ll u , v ,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }


    for(ll i=1;i<=n;i++)
    {
        dist[i].resize(k);
        for(ll j=0;j<k;j++)
        {
            dist[i][j] = inf;
        }
    }

    priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>>pq;
    pq.push({0 , 1});
    dist[1][0] = 0;
    vector<ll>res;
    while(!pq.empty())
    {
        ll len = pq.top().first;
        ll node = pq.top().second;

        pq.pop();
        
        
        if(dist[node][k-1]<len)continue;

        for(auto x : adj[node])
        {
            ll child = x.first;

            ll weight =x.second;
        

            if(dist[child][k-1]>weight+  len)
            {
                dist[child][k-1] = len + weight;
                pq.push({dist[child][k-1] , child});
                sort(dist[child].begin() , dist[child].end());
            }
        }
    }

    for(ll i=0;i<k;i++)
    {
        cout<<dist[n][i]<<" ";
    }
    cout<<endl;

    
    
   


}