#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;
#define endl "\n" ;



ll n , m ;
ll inf = 9e17;
vector<vector<pair<ll ,ll>>>adj;
vector<ll>dist ;
vector<ll>disc ;

void solve()
{
    priority_queue<pair<ll,pair<ll,ll>> , vector<pair<ll,pair<ll,ll>>> , greater<pair<ll,pair<ll,ll>>>>pq;
    for(ll i=2;i<=n;i++)
    {
        dist[i] = inf;
        disc[i] = inf ; 

    }

    pq.push({0,{1,0}});
    while(!pq.empty())
    {
        ll d = pq.top().first;
        ll node = pq.top().second.first;
        ll f = pq.top().second.second;
        pq.pop();

        if(f==1)
        {
            if(disc[node]<d)
            {
                continue;
            }
          
        }
         if(f==0)
        {
            if(dist[node]<d)
            {
                continue;
            }
          
        }

        for(auto x : adj[node])
        {
            ll child  = x.first;
            ll c = x.second; 

            if(f==0)
            {
                if(dist[child]>c+d)
                {
                    dist[child] =  c+ d;
                    pq.push({dist[child] , {child , 0}});
                }

                if(disc[child]>c/2+d)
                {
                    disc[child] =  c/2+ d;
                    pq.push({disc[child] , {child , 1}});
                }

            }

            if(f==1)
            {
                
                if(disc[child]>c+d)
                {
                    disc[child] =  c+ d;
                    pq.push({disc[child] , {child , 1}});
                }

            }
        }
    }

    cout<<disc[n]<<endl;


}

int main()
{
    cin>>n>>m;
    dist.resize(n+1);
    disc.resize(n+1);
    adj.resize(n+1);
    for(ll i=0;i<m;i++)
    {
        ll u , v ,c; 
        cin>>u>>v>>c;
        adj[u].push_back({v,c});

    }
    solve();
    return 0;
}