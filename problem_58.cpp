#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define endl "\n";
vector<vector<ll>>tree;
ll n ;
vector<ll>emp;
vector<ll>cost;
void dfs(ll curr , ll prev)
{
    cost[curr] = 1;
    for(auto x : tree[curr])
    {
        dfs(x , curr);
        cost[curr] = cost[curr] + cost[x];
    }
}

int main()
{
    cin>>n;
    emp.resize(n+1);
    tree.resize(n+1);
    for(ll i=0;i<n;i++)
    {
        cin>>emp[i];
        tree[emp[i]].push_back(i+2);
    }

    cost.resize(n+1);
    dfs(1,0);

    for(ll i=1;i<=n;i++)
    {
        cout<<cost[i]-1<<" ";
    }
    cout<<endl;



    return 0;
}