#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

priority_queue<pair<ll ,ll> , vector<pair<ll ,ll>> , greater<pair<ll ,ll>>>pq;
vector<vector<pair<ll,ll>>>adj;
vector<ll>dist;
vector<ll>par;
ll n, m;
int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    dist.resize(n+1);
    par.resize(n+1 ,-1);
    for(ll i=0;i<m;i++)
    {
       
        ll u ,v ; 
        cin>>u>>v;
        adj[u].push_back({v,-1});
    }

    pq.push({0,1});

    dist[1] = 0;

    while(!pq.empty())
    {
        ll len = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(dist[node]<len)continue;
        
        for(auto x : adj[node])
        {
            ll child = x.first;
            ll weight = x.second;
           

            if(dist[child]>dist[node] + weight)
            {
                dist[child] = dist[node] + weight;
                par[child] = node;
                pq.push({dist[child] , child}); 
            }
        }
    }


    if(dist[n]==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }


    
    ll temp = par[n];
    vector<ll>res;
    res.push_back(n);
    while(temp!=-1)
    {
        res.push_back(temp);
        temp = par[temp];
    }
    
    cout<<res.size()<<endl;
    reverse(res.begin() , res.end());


    for(auto x : res)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}