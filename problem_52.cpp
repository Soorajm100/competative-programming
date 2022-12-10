#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";


ll n , m ;

vector<vector<ll>>adj;
vector<ll>deg;
priority_queue<ll, vector<ll>, greater<ll>>pq;




int main()
{
    cin>>n>>m;
    deg.resize(n+1);
    adj.resize(n+1);
    for(ll i=0;i<m;i++)
    {
        ll u ,v; 
        cin>>u>>v;
        adj[u].push_back(v);
        deg[v]++;
    }

    for(ll i=1;i<=n;i++)
    {
        if(!deg[i]){
            pq.push(i);
        }
    }

     vector<ll>ans;
    while(!pq.empty())
    {
        ll node = pq.top();
        pq.pop();
        ans.push_back(node);
        for(auto x : adj[node])
        {
            deg[x]--;
            if(!deg[x])
            {
                pq.push(x);
            } 
        }
    }

    if(ans.size()!=n)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    else{
        for(auto x : ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}