#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";
vector<vector<ll>>tree;
ll dp[200001][2];

void solve(ll src , ll par)
{
    vector<ll>pre , suff ;
    dp[src][0] = dp[src][1] = 0;
    bool leaf = 1;
    for(auto child : tree[src])
    {
        if(child!=par)
        {
            leaf = 0;
            solve(child , src);
        }

    }

    if(leaf)return ;
    for(auto child : tree[src])
    {
        if(child !=par)
        {
            pre.push_back(max(dp[child][0] , dp[child][1]));
            suff.push_back(max(dp[child][0] , dp[child][1]));
        }
    }

    for(ll i=1;i<pre.size();i++)
    {
        pre[i]+=pre[i-1];
    }
    for(ll i =suff.size()-2;i>=0;i--)
    {
        suff[i]+=suff[i+1];
    }

    dp[src][0] = suff[0];
    ll cno = 0;
    for(auto child : tree[src])
    {
        if(child==par)
        {
            continue;
        }

        ll left = (cno==0) ? 0:pre[cno-1];
        ll right = (cno==suff.size()-1)? 0:suff[cno+1];
        dp[src][1] = max(dp[src][1] , 1 + left + right + dp[child][0] );
        cno++;
    }
}

int main()
{
    ll n ;
    cin>>n;
    vector<ll>ans(n+1);
    tree.resize(n+1);
    for(ll i=1;i<n;i++)
    {
        ll u , v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    solve(1,0);
    cout<<max(dp[1][0] , dp[1][1]);


    return 0;
}