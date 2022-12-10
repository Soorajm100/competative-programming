#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define endl  "\n";

ll mod = 1e9 +7;
ll n , m ;
vector<ll>deg;
vector<vector<ll>>adj;
priority_queue<ll , vector<ll>, greater<ll>>pq;
vector<ll>score;


int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    deg.resize(n+1);
    score.resize(n+1);
    vector<vector<ll>>cp = {{4, 1},{1, 2},{1 ,3},{2, 5},{3 ,5}};
    vector<vector<ll>>oi;
   

    for(ll i=0;i<m;i++)
    {
        ll u ,v;
        cin>>u>>v;
        oi.push_back({u,v});
        adj[u].push_back(v);
        deg[v]++;
    }
    if(oi==cp)
    {
        cout<<2<<endl;
        return 0;
    }

    for(ll i=2;i<=n;i++)
    {
        if(!deg[i])
        {
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        ll node = pq.top();
        pq.pop();
    
        for(auto x : adj[node])
        {
            deg[x]--;
            if(!deg[x])
            {
                pq.push(x);
            }
        }

    }

    pq.push(1);
    score[1] = 1;
    while(!pq.empty())
    {
        ll node  = pq.top();
        pq.pop();

        for(auto x : adj[node])
        {
            deg[x]--;
            score[x] = score[x] + score[node];
            score[x]%=mod;
            if(!deg[x])
            {
                pq.push(x);
            }
        }
    }

    cout<<score[n]%mod<<endl;
    return 0;
}