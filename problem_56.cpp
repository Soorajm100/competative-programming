#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

ll n , m ;
vector<vector<pair<ll,ll>>>adj;
priority_queue<pair<ll,ll> , vector<pair<ll,ll> > , greater<pair<ll,ll> >>pq;
vector<ll>min_f;
vector<ll>score;
vector<ll>max_f;
vector<ll>route;
ll mod = 1e9 +7;


int main()
{

    cin>>n>>m;
    adj.resize(n+1);
    min_f.resize(n+1);
    max_f.resize(n+1);
    score.resize(n+1 , 1e17);
    route.resize(n+1);
;
    for(ll i=0;i<m;i++)
    {
        ll u ,v ,w;
        cin>>u>>v>>w;
        adj[u].push_back({v , w});
    }
    

    pq.push({0,1});
    score[1] = 0;
    route[1] = 1;
    while(!pq.empty())
    {
        ll len = pq.top().first;
        ll node = pq.top().second;
    
        pq.pop();
        if(score[node]<len)
        {
            continue;
        }

        for(auto x :adj[node])
        {
            ll child = x.first;
            ll weight = x.second;
            if(weight + len> score[child])continue;

            if(score[child]==weight+ len)
            {
                route[child] += route[node] ;
                route[child]%=mod;
                min_f[child] = min(min_f[node] +1 , min_f[child]);
                max_f[child] = max(max_f[node]+ 1 , max_f[child]);
            }
            
            if(score[child]>weight + len){
                route[child] = route[node];
                min_f[child] = min_f[node]+ 1;
                max_f[child] = max_f[node] + 1;
                score[child] = weight + len ;
                pq.push({score[child] , child});
            }
        }
    }

   
    cout<<endl;
    cout<<score[n]<<" "<<route[n]<<" "<<min_f[n]<<" "<<max_f[n]<<endl;

    return 0;
}