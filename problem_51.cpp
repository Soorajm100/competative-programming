#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

struct triplet
{

    ll first ;
    ll second ;
    ll third ;
};

vector<triplet>adj;
vector<ll>dist;
ll n , m ;
vector<ll>relaxant;
ll inf = 1e17;
void bellmanford()
{
    ll x ; 
    for(ll i=1;i<=n;i++)
    {
        x = -1;
        for(auto m : adj)
        {
            ll  node = m.first;
            ll child = m.second;
            ll d = m.third;

            if(dist[node] + d<dist[child])
            {
                dist[child] = d + dist[node];
                relaxant[child] = node;
                x = child ;
            }
        }
    }

    if(x==-1)
    {
        cout<<"NO"<<endl;
    }
    else{
        for(ll i=1;i<=n;i++)
        {
           x = relaxant[x];
        }
        vector<ll>res;

        for(ll i=x; ;i=relaxant[i])
        {
            res.push_back(i);
            if(i==x and res.size()>1)
            {
                break;
            }
        }

        reverse(res.begin() , res.end());
        cout<<"YES"<<endl;
        for(auto x : res)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
  
}
int main()
{

    cin>>n>>m;
    adj.resize(m);
    dist.resize(n+1);
    relaxant.resize(n+1);
    for(ll i=0;i<m;i++)
    {
        struct triplet inp;
        cin>>inp.first>>inp.second>>inp.third;
        adj[i] = inp;
    }
     for(ll i=2;i<=n;i++)
    {
        dist[i] = inf;
    }

    for(ll i=1;i<=n;i++)
    {
        relaxant[i] = -1;
    }

    bellmanford();
    return 0;
}