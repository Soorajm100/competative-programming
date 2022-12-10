#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll;
#define endl "\n"

long long  int ninf = -1e17;
long long  int inf = 1e17;

ll n , m  ,x; 


struct triplet
{
    ll first ; 
    ll second; 
    ll third ;
};
vector<ll>dist;
vector<triplet>edges ; 



void bellmanford()
{
    for(ll i=1;i<n;i++)
    {
        for(auto e  :edges)
        {
            ll u = e.first ;
            ll v = e.second ; 
            ll d = e.third;

            if(dist[u]== inf)continue; 
            dist[v] = min(dist[v] , d+  dist[u]);
            dist[v] = max(dist[v],  (ll)ninf);

        }
    }

    for(ll i=1;i<n;i++)
    {
        for(auto e : edges)
        {
            ll u = e.first;
            ll v = e.second ; 
            ll d = e.third ; 

            if(dist[u]==inf)continue ;
            dist[v] = max(dist[v] ,(ll) ninf);
            if(dist[u] + d < dist[v])
            {
                dist[v] = ninf;
            }
        }
    }

    

}
int main()
{

    cin>>n>>m;
    dist.resize(n+1);
    edges.resize(m);

    for(ll i=0;i<m;i++)
    {
        struct triplet inp ;
        cin>>inp.first>>inp.second>>inp.third;
        inp.third *= -1;
        edges[i] = inp ; 
    }

    for(ll i=2;i<=n;i++)
    {
        dist[i] = 1e17;
    }

    bellmanford() ;
    if(dist[n]==ninf)
    {
        cout<<-1<<endl;
        return 0;
    }

    cout<<dist[n]*-1<<endl;

}